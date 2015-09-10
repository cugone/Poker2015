/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\CGame.cpp
* author:   Casey Ugone
* summary:  Implements the game class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#include "CGame.h"

#include <iomanip>

#include "CDealer.h"
#include "CPlayer.h"

const unsigned int max_hand_size = 5;

Game::Game(Dealer& dealer, std::vector<Player>& players) : _dealer(dealer), _players(players), _stats() {
    /* DO NOTHING */
}

void Game::LogGameCount(std::ostream& os) const {
    auto f = os.flags();
    os.setf(std::ios::dec, std::ios::basefield);
    os.setf(std::ios::left, std::ios::adjustfield);
    os.setf(std::ios::boolalpha);
    os << std::left;
    os << std::setw(15) << "Game Count" << std::setw(2) << ":" << _stats.game_count << '\n';
    os.flush();
    os.flags(f);
}
void Game::LogGameCount(std::ostream& os) {
    static_cast<const Game&>(*this).LogGameCount(os);
}

void Game::LogHandCount(std::ostream& os) const {
    auto f = os.flags();
    os.setf(std::ios::dec, std::ios::basefield);
    os.setf(std::ios::left, std::ios::adjustfield);
    os.setf(std::ios::boolalpha);
    os << std::left;
    os << std::setw(15) << "Hand Count" << std::setw(2) << ":" << _stats.hand_count << '\n';
    os.flush();
    os.flags(f);
}
void Game::LogHandCount(std::ostream& os) {
    static_cast<const Game&>(*this).LogHandCount(os);
}

void Game::IncrementGameCount() {
    ++_stats.game_count;
}
void Game::IncrementHandCount() {
    ++_stats.hand_count;
}

void Game::CalculatePlayerHandValues(std::vector<Player>& players) {
    for(auto& p : players) {
        p.CalculateHandValue();
    }
}

void Game::StartGame(Dealer& d) {
    _dealer.ShuffleDeck(_dealer.GetDeck());
}

void Game::ResetGame(Dealer& d) {
    d.ShuffleDeck(d.GetDiscardDeck());
    d.CombineDecks(d.GetDeck(), d.GetDiscardDeck());
}

void Game::Run() {

    StartGame(_dealer);

    auto num_players = _players.size();
    auto min_deck_size = num_players * max_hand_size;
    auto& cur_deck = _dealer.GetDeck();

    Dealer::Deal(_dealer, _players, max_hand_size);
    CalculatePlayerHandValues(_players);
    RecordHandTypeCount(_players);
    for(auto& p : _players) {
        IncrementHandCount();
        p.DisplayHand(std::cout);
    }
    Dealer::TakeCardsFromPlayers(_dealer, _players);

    ResetGame(_dealer);
    IncrementGameCount();

}

void Game::LogPlayerHands(std::ostream& os) const {
    auto f = os.flags();
    os.setf(std::ios::dec, std::ios::basefield);
    os.setf(std::ios::left, std::ios::adjustfield);
    os.setf(std::ios::boolalpha);
    os << std::left;
    os << std::setw(15) << "Straight Flush"  << std::setw(2) << ":" << _stats.straight_flush_count << '\n';
    os << std::setw(15) << "Four of a Kind"  << std::setw(2) << ":" << _stats.four_kind_count      << '\n';
    os << std::setw(15) << "Full House"      << std::setw(2) << ":" << _stats.fullhouse_count      << '\n';
    os << std::setw(15) << "Flush"           << std::setw(2) << ":" << _stats.flush_count          << '\n';
    os << std::setw(15) << "Straight"        << std::setw(2) << ":" << _stats.straight_count       << '\n';
    os << std::setw(15) << "Three of a Kind" << std::setw(2) << ":" << _stats.three_kind_count     << '\n';
    os << std::setw(15) << "Two Pair"        << std::setw(2) << ":" << _stats.two_pair_count       << '\n';
    os << std::setw(15) << "One Pair"        << std::setw(2) << ":" << _stats.one_pair_count       << '\n';
    os << std::setw(15) << "High Card"       << std::setw(2) << ":" << _stats.no_pair_count        << '\n';
    os.flush();
    os.flags(f);
}

void Game::LogPlayerHands(std::ostream& os) {
    static_cast<const Game&>(*this).LogPlayerHands(os);
}

void Game::RecordHandTypeCount(const std::vector<Player>& players) {
    for(auto& p : players) {
        auto& h = p.GetHand();
        if(h.IsStraightFlush()) {
            ++_stats.straight_flush_count;
        } else if(h.IsFourOfAKind()) {
            ++_stats.four_kind_count;
        } else if(h.IsFullHouse()) {
            ++_stats.fullhouse_count;
        } else if(h.IsFlush()) {
            ++_stats.flush_count;
        } else if(h.IsStraight()) {
            ++_stats.straight_count;
        } else if(h.IsThreeOfAKind()) {
            ++_stats.three_kind_count;
        } else if(h.IsTwoPair()) {
            ++_stats.two_pair_count;
        } else if(h.IsPair()) {
            ++_stats.one_pair_count;
        } else {
            ++_stats.no_pair_count;
        }
    }
}