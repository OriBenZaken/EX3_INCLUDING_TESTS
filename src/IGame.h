//
// Created by ori on 02/11/17.
// ID: 311492110
//
#ifndef EX2_IGAME_H
#define EX2_IGAME_H
#include "Player.h"
/**
 * Reversi Game interface.
 */
class IGame {
public:
    enum Status {Playing, NoPossibleMoves, GameOver};
    enum PlayersType {Humans, HumanVSAI};
    /** Runs a Reversi game until game is over : Win/Lose or a Tie.
     *
     */
    IGame()  {}
    //IGame(Player* currPlayer, Player* otherPlayer) : currPlayer(currPlayer), otherPlayer(otherPlayer) {}
    virtual void run() = 0;
    /**
     * virtual deafult ctor.
     */
    virtual ~IGame()  {}
};
#endif //EX2_IGAME_H
