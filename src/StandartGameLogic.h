//
// Created by ori on 24/10/17.
// ID: 311492110
//
#ifndef EX2_STANDARTGAMELOGIC_H
#define EX2_STANDARTGAMELOGIC_H
#include <iostream>
#include "Board.h"
#include "GameLogic.h"

#include "Player.h"

/**
 * Standard game logic of Reversi game. Players only allowed to put a washer in a cell in the
 * board which will cause the opponent's cells to flip.
 */
class StandartGameLogic : public GameLogic {
public:
    /**
     * StandartGameLogic ctor.
     * @param board Board
     */
    StandartGameLogic(Board* board) : board(board) {}
    //copy ctr
    /**
     * StandardGameLogic copy ctor.
     * @param toCopy reference to StandardGameLogic object.
     */
    StandartGameLogic(const GameLogic& toCopy) {
        Board copy(*toCopy.getBoard());
        (*this).setBoard(&copy);
    }
    /**
     * prints end stores in a array the possible moves of a player in the game.
     * @param moves pair<int, int> array that stores all the possible cells for player's next move.
     * @param player Player (Cell enum)
     * @param opponent  Opponent (Cell enum)
     * @return possible moves array
     */
    vector< pair<int, int> > possibleMoves(Board::Cell player, Board::Cell opponent);
    /**
     * gets form the player his next move choice and make the changes in the board according
     * to the move (row,col).
     * @param row row
     * @param col col
     * @param player Player (Cell enum)
     * @param opponent Opponent (Cell enum)
     */
    bool makeMove(int row, int col, Board::Cell player, Board::Cell opponent);
    /**
    * sets board member.
    * @param board Board
    */
    void setBoard(Board *board);
    /**
 * returns score of current player : #cells of current player type - #cells of opponent player type.
 * @param current Board::Cell (Black/White)
 * @param opponent Board::Cell (Black/White)
 * @return score
 */
    int getScores(Board::Cell current, Board::Cell opponent);
    /**
    * sets board member.
    * @param board Board
     */
    Board * getBoard() const;
private:
    Board* board;
    /**
     * Checks if a cell is a possible move.
     * @param row row
     * @param col col
     * @param player Player (Cell enum)
     * @param opponent Opponent (Cell enum)
     * @return true - cell is a possible move. false - cell is not a possible move.
     */
    bool checkCell(int row, int col,Board::Cell player, Board::Cell opponent);
    /**
     * Checks if certain direction (determined by change in row and col) is a legit flip move.
     * @param row row
     * @param col col
     * @param rowDirection change in row
     * @param colDirection change in col
     * @param player Player (Cell enum)
     * @return
     */
    bool scanDirection(int row, int col, int rowDirection, int colDirection, Board::Cell player);
    /**
     * given a direction in the board (determined by change in row and col) - checks if this direction
     * is a legit flip move.
     * @param row row
     * @param col col
     * @param rowDorection change in row
     * @param colDirection change in col
     * @param opponent Opponent (Cell enum)
     */
    void flipCells(int row, int col,int rowDorection,
                   int colDirection, Board::Cell opponent);
};
#endif //EX2_STANDARTGAMELOGIC_H