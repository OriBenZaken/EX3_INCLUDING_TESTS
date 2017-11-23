//
// Created by ori on 14/11/17.
// ID: 311492110
//

#ifndef EX2_HUMANPLAYER_H
#define EX2_HUMANPLAYER_H
#include "Player.h"
class HumanPlayer : public Player {
    /**
     * HumanPlayer c'tor
     * @param type Board::Cell (Black/White)
     */
public:
    //todo: add documentation
    HumanPlayer(Board::Cell type) : Player(type) {}
    pair<int, int> getInput(vector< pair<int,int> > options, const Board* board,
                            Board::Cell currentCellType, Board::Cell opponentCellType);
private:
    /**
     * Checks if a user input of a move is among the user possible moves.
     * @param options vector of all possible moves.
     * @param row row
     * @param col col
     * @return true - a possible move, else- false.
     */
    bool isValidMove(vector< pair<int,int> > options, int row, int col);

};
#endif //EX2_HUMANPLAYER_H
