
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

void GameLoop(Game& game, Dealer& dealer, std::vector<Player>& players, unsigned int max_hand_size);
void StartGame(Dealer& d);
void Deal(Dealer& d, std::vector<Player>& players, unsigned int max_hand_size);
void CalculatePlayerHandValues(std::vector<Player>& players);
void DisplayPlayerHands(const std::vector<Player>& players, std::ostream& os = std::cout);
void DisplayHandResults(const std::vector<Player>& players, std::ostream& os = std::cout);
void WaitForEnter();
void TakeCardsFromPlayers(Dealer& d, std::vector<Player>& players);
void ResetGame(Dealer& d);
bool PromptPlayAgain();
void DebugDisplayHandValueTypes(const std::vector<Player>& players, std::ostream& os = std::cout);
void DebugDisplayHandValueType(const Player& player, std::ostream& os = std::cout);
unsigned int GetNumPlayers();
unsigned int GetGameHandSize();
unsigned long long GetMaxPlayCount();

int main() {

    const unsigned int max_num_players = GetNumPlayers();
    const unsigned long long max_play_count = GetMaxPlayCount();

    Dealer dealer;
    std::vector<Player> players(max_num_players, Player{ });

    Game g(dealer, players);
    g.Run(max_play_count);

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

    unsigned long long default_value = 100;

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


void DebugDisplayHandValueTypes(const std::vector<Player>& players, std::ostream& os) {
    for(auto& p : players) {
        DebugDisplayHandValueType(p, os);
        os << '\n';
    }
    os.flush();
}

void DebugDisplayHandValueType(const Player& player, std::ostream& os) {
    auto& h = player.GetHand();
    os << "0x" << std::setfill('0') << std::setw(4) << std::hex << h.GetValue() << std::setfill(' ') << '\t' << hand::TypeToString(h.GetHandType());
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Play again? (Y/N): ";
    char answer = '\0';
    std::cin >> answer;
    answer = toupper(answer);
    return answer == 'Y';
}

void DisplayPlayerHands(const std::vector<Player>& players, std::ostream& os) {
    
    std::string FaceValues[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
    char SuitValues[] = { 'C', 'D', 'H', 'S' };

    std::size_t player_number = 0;
    for(auto& p : players) {

        os << 'P' << (++player_number);
        auto& h = p.GetHand();
        for(auto& c : h) {
            os << std::setw(3) << FaceValues[((c.GetFace() >> 4) - 2)];
            os << SuitValues[static_cast<uint8_t>(std::log2(c.GetSuit()))];
        }
        os << '\n';
    }
    os.flush();

}