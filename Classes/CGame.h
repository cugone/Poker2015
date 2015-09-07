#ifndef POKER_CGAME_H
#define POKER_CGAME_H

#include <iostream>
#include <vector>

class Player;
class Dealer;

struct GameStats {
    unsigned long long game_count = 0;
    unsigned long long hand_count = 0;
    unsigned long long no_pair_count = 0;
    unsigned long long one_pair_count = 0;
    unsigned long long two_pair_count = 0;
    unsigned long long three_kind_count = 0;
    unsigned long long straight_count = 0;
    unsigned long long flush_count = 0;
    unsigned long long fullhouse_count = 0;
    unsigned long long four_kind_count = 0;
    unsigned long long straight_flush_count = 0;
};

class Game {
public:
    Game(Dealer& dealer, std::vector<Player>& players);
    Game(const Game& other) = delete;
    Game(const Game&& other) = delete;
    Game& operator=(const Game& rhs) = delete;
    Game&& operator=(const Game&& rhs) = delete;

    void Run(unsigned long long max_play_count);

    void LogPlayerHands(std::ostream& os) const;
    void LogPlayerHands(std::ostream& os);
    void RecordHandTypeCount(const std::vector<Player>& players);

    void LogGameCount(std::ostream& os) const;
    void LogGameCount(std::ostream& os);

    void LogHandCount(std::ostream& os) const;
    void LogHandCount(std::ostream& os);

    void IncrementGameCount();
    void IncrementHandCount();

protected:
    void StartGame(Dealer& d);
    void CalculatePlayerHandValues(std::vector<Player>& players);
    void ResetGame(Dealer& d);
private:
    Dealer& _dealer;
    std::vector<Player>& _players;
    GameStats _stats;
};

#endif