
#ifndef EX2_HUMANPLAYER_H
#define EX2_HUMANPLAYER_H
#include "Player.h"
#include <sstream>
#include <stdexcept>
/**
 * Human player in Reversi Game.
 */
class HumanPlayer : public Player {
    /**
     * HumanPlayer c'tor
     * @param type Board::Cell (Black/White)
     */
public:
    /**
     * HumanPlayer ctor.
     * @param type Board::Cell (White/Black)
     */
    HumanPlayer(Board::Cell type) : Player(type) {}
    /**
     * display to the human player all his possible moves and gets an input of a wished move.
     * @param options vector of possible moves.
     * @param board Board
     * @param currentCellType Board::Cell (White/Black)
     * @param opponentCellType Board::Cell (White/Black)
     * @return pair<int, int> of cell in the board - the desired move of the player.
     */
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
