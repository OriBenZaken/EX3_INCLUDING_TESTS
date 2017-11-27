//
// Created by ori on 14/11/17.
// ID: 311492110
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H
#include <iostream>
#include "Board.h"
#include "GameLogic.h"
#include <vector>
using namespace std;
/**
 * Player Interface.
 * Player can be human or computer.
 */
class Player {
public:
    /**
     * Player default c'tor.
     */
    Player(){}
    /**
     * Player c'tor
     * @param type Board::Cell - Can be Black or White.
     */
    Player(Board::Cell type) : type(type) {}
    /**
    * display to the player all his possible moves and gets an input of a wished move.
    * @param options vector of possible moves.
    * @param board Board
    * @param currentCellType Board::Cell (White/Black)
    * @param opponentCellType Board::Cell (White/Black)
    * @return pair<int, int> of cell in the board - the desired move of the player.
     */
    Player(Board::Cell type, GameLogic *gameLogic) : type(type) {
       // GameLogic copyLogic(*gameLogic);
        (*this).gameLogic = gameLogic;
    }

    /**
     * returns the player type.
     * @return Board::Cell (Black/White)
     */
    virtual Board::Cell getType();
    /**
     * Sets the type of the player
     * @param newType Board:Cell
     */
    virtual void setType(Board::Cell newType);

    virtual pair<int, int> getInput(vector< pair<int,int> > options, const Board* board,
                                    Board::Cell currentCellType, Board::Cell opponentCellType);
    virtual ~Player();
protected:
    Board::Cell type;
    GameLogic * gameLogic;
};
#endif //EX2_PLAYER_H
