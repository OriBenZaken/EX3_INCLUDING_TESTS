
#ifndef EX2_GAMELOGIC_H
#define EX2_GAMELOGIC_H
#include <iostream>
#include <vector>
#include "Board.h"
#include <iostream>
#include "Board.h"
using namespace std;
/**
 * Game Logic interface of Reversi game.
 */
class GameLogic {
public:
    /**
     * GameLogic empty default ctor.
     */
    GameLogic() {}
    /**
     * Copy ctor of GameLogic
     * @param toCopy reference to Board object.
     * @return copy of toCopy
     */
    GameLogic(const GameLogic& toCopy) {
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
    virtual vector< pair<int, int> > possibleMoves(Board::Cell player, Board::Cell opponent);
    /**
     * gets form the player his next move choice and make the changes in the board according
     * to the move (row,col).
     * @param row row
     * @param col col
     * @param player Player (Cell enum)
     * @param opponent Opponent (Cell enum)
     */
    virtual bool makeMove(int row, int col, Board::Cell player, Board::Cell opponent);
    /**
     * returns ths game of the board.
     * @return Board
     */
    virtual Board *getBoard() const;
    /**
     * sets board member.
     * @param board Board
     */
    virtual void setBoard(Board *board);
    /**
     * returns score of current player : #cells of current player type - #cells of opponent player type.
     * @param current Board::Cell (Black/White)
     * @param opponent Board::Cell (Black/White)
     * @return score
     */
    virtual int getScores(Board::Cell current, Board::Cell opponent);
};
#endif //EX2_GAMELOGIC_H
