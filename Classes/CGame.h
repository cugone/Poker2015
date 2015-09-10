/*******************************************************************************
* solution: Poker
* project:  Poker
* file:     Classes\CGame.h
* author:   Casey Ugone
* summary:  Declares the game class
*           Copyright (c) 2015 Blisspoint Softworks. All rights reserved.
*
*******************************************************************************/
#ifndef POKER_CGAME_H
#define POKER_CGAME_H

#include <iostream>
#include <vector>

class Player;
class Dealer;

/**************************************************************************************************
 * <summary>A game statistics.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 **************************************************************************************************/
struct GameStats {
    /** <summary>Number of games.</summary> */
    unsigned long long game_count = 0;
    /** <summary>Number of hands.</summary> */
    unsigned long long hand_count = 0;
    /** <summary>Number of no pairs.</summary> */
    unsigned long long no_pair_count = 0;
    /** <summary>Number of one pairs.</summary> */
    unsigned long long one_pair_count = 0;
    /** <summary>Number of two pairs.</summary> */
    unsigned long long two_pair_count = 0;
    /** <summary>Number of three kinds.</summary> */
    unsigned long long three_kind_count = 0;
    /** <summary>Number of straights.</summary> */
    unsigned long long straight_count = 0;
    /** <summary>Number of flushes.</summary> */
    unsigned long long flush_count = 0;
    /** <summary>Number of fullhouses.</summary> */
    unsigned long long fullhouse_count = 0;
    /** <summary>Number of four kinds.</summary> */
    unsigned long long four_kind_count = 0;
    /** <summary>Number of straight flushes.</summary> */
    unsigned long long straight_flush_count = 0;
 };

/**************************************************************************************************
 * <summary>A game.</summary>
 * <remarks>Casey Ugone, 9/9/2015.</remarks>
 **************************************************************************************************/
class Game {
public:

    /**************************************************************************************************
     * <summary>Constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="dealer"> [in,out] The dealer.</param>
     * <param name="players">[in,out] The players.</param>
     **************************************************************************************************/
    Game(Dealer& dealer, std::vector<Player>& players);

    /**************************************************************************************************
     * <summary>Copy constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    Game(const Game& other) = delete;

    /**************************************************************************************************
     * <summary>Move constructor.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="other">The other.</param>
     **************************************************************************************************/
    Game(const Game&& other) = delete;

    /**************************************************************************************************
     * <summary>Assignment operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this Game.</returns>
     **************************************************************************************************/
    Game& operator=(const Game& rhs) = delete;

    /**************************************************************************************************
     * <summary>Move assignment operator.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="rhs">The right hand side.</param>
     * <returns>A shallow copy of this Game.</returns>
     **************************************************************************************************/
    Game&& operator=(const Game&& rhs) = delete;

    /**************************************************************************************************
     * <summary>Runs this Game.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    void Run();

    /**************************************************************************************************
     * <summary>Logs player hands.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="os">[in,out] The operating system.</param>
     **************************************************************************************************/
    void LogPlayerHands(std::ostream& os) const;

    /**************************************************************************************************
     * <summary>Logs player hands.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="os">[in,out] The operating system.</param>
     **************************************************************************************************/
    void LogPlayerHands(std::ostream& os);

    /**************************************************************************************************
     * <summary>Record hand type count.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="players">The players.</param>
     **************************************************************************************************/
    void RecordHandTypeCount(const std::vector<Player>& players);

    /**************************************************************************************************
     * <summary>Logs game count.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="os">[in,out] The operating system.</param>
     **************************************************************************************************/
    void LogGameCount(std::ostream& os) const;

    /**************************************************************************************************
     * <summary>Logs game count.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="os">[in,out] The operating system.</param>
     **************************************************************************************************/
    void LogGameCount(std::ostream& os);

    /**************************************************************************************************
     * <summary>Logs hand count.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="os">[in,out] The operating system.</param>
     **************************************************************************************************/
    void LogHandCount(std::ostream& os) const;

    /**************************************************************************************************
     * <summary>Logs hand count.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="os">[in,out] The operating system.</param>
     **************************************************************************************************/
    void LogHandCount(std::ostream& os);

    /**************************************************************************************************
     * <summary>Increment game count.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    void IncrementGameCount();

    /**************************************************************************************************
     * <summary>Increment hand count.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     **************************************************************************************************/
    void IncrementHandCount();

protected:

    /**************************************************************************************************
     * <summary>Starts a game.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="d">[in,out] The Dealer to process.</param>
     **************************************************************************************************/
    void StartGame(Dealer& d);

    /**************************************************************************************************
     * <summary>Calculates the player hand values.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="players">[in,out] The players.</param>
     **************************************************************************************************/
    void CalculatePlayerHandValues(std::vector<Player>& players);

    /**************************************************************************************************
     * <summary>Resets the game described by d.</summary>
     * <remarks>Casey Ugone, 9/9/2015.</remarks>
     * <param name="d">[in,out] The Dealer to process.</param>
     **************************************************************************************************/
    void ResetGame(Dealer& d);
private:
    /** <summary>The dealer.</summary> */
    Dealer& _dealer;
    /** <summary>The players.</summary> */
    std::vector<Player>& _players;
    /** <summary>The statistics.</summary> */
    GameStats _stats;

};

#endif