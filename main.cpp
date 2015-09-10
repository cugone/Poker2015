/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     main.cpp
* author:   Casey Ugone
* summary:  Implements the main class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <tinyxml2.h>

#include "Classes/CGame.h"
#include "Classes/CDealer.h"
#include "Classes/CPlayer.h"
#include "Classes/CHand.h"
#include "Classes/CCard.h"
#include "Classes/CDeck.h"

void DisplayHandResults(const std::vector<Player>& players, std::ostream& os = std::cout);
void WaitForEnter();
bool PromptPlayAgain();
unsigned int GetNumPlayers();
unsigned int GetGameHandSize();
unsigned long long GetMaxPlayCount();

int main() {

    const unsigned int max_num_players = GetNumPlayers();
    const unsigned long long max_play_count = GetMaxPlayCount();

    Dealer dealer;
    std::vector<Player> players(max_num_players, Player{ });

    Game g(dealer, players);

    unsigned long long playcount = 0;
    do {
        g.Run();
        if(max_play_count <= 0) DisplayHandResults(players); //Only display hands to user if play is not automatic.
    } while(max_play_count > 0 ? (++playcount < max_play_count) : PromptPlayAgain());

    std::ofstream file;
    file.open("stats.dat");
    g.LogPlayerHands(file);
    g.LogHandCount(file);
    g.LogGameCount(file);
    file.close();

    return 0;
}

unsigned int GetNumPlayers() {
    
    tinyxml2::XMLDocument doc;
    unsigned int default_value = 2;

    auto load_result = doc.LoadFile("options.dat");
    if(load_result != tinyxml2::XML_NO_ERROR) return default_value;

    auto root = doc.FirstChildElement("options");
    if(root == nullptr) return default_value;

    auto curPlayer = root->FirstChildElement("player_count");
    if(curPlayer == nullptr) return default_value;

    unsigned int value = 0;
    if(curPlayer->QueryUnsignedText(&value) != tinyxml2::XMLError::XML_SUCCESS) return default_value;
    
    return value;
}

unsigned long long GetMaxPlayCount() {

    tinyxml2::XMLDocument doc;

    unsigned long long default_value = 0;

    auto load_result = doc.LoadFile("options.dat");
    if(load_result != tinyxml2::XML_NO_ERROR) return default_value;

    auto root = doc.FirstChildElement("options");
    if(root == nullptr) return default_value;

    auto curPlayer = root->FirstChildElement("play_count");
    if(curPlayer == nullptr) return default_value;

    auto result = curPlayer->GetText();
    if(result == nullptr) return default_value;

    std::stringstream text_value;
    text_value << result;

    unsigned long long value = 0;
    text_value >> value;

    if(text_value.fail()) return default_value;

    return value;
}

void DisplayHandResults(const std::vector<Player>& players, std::ostream& os) {
    auto p1hand = players[0].GetHand();
    auto p2hand = players[1].GetHand();
    if(p1hand > p2hand) {
        os << "PLAYER 1 WINS!" << std::endl;
    }
    if(p2hand > p1hand) {
        os << "PLAYER 2 WINS!" << std::endl;
    }
    if(p2hand == p1hand) {
        os << "TIE!" << std::endl;
    }
}

void WaitForEnter() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(!std::cin.get());
}


bool PromptPlayAgain() {
    std::cout << "Play again? (Y/N): ";
    char answer = '\0';
    std::cin >> answer;
    answer = toupper(answer);
    return answer == 'Y';
}
