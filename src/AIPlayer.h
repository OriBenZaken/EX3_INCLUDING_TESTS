//
// Created by liz on 19/11/17.
//

#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "Player.h"
#include "GameLogic.h"
/**
 * AIPlayer in Reversi Game.
 */
class AIPlayer : public Player {
public:
/**
 * AIPlayer c'tor
 * @param type Board::Cell (Black/White)
 */
    AIPlayer(Board::Cell type, GameLogic* gameLogic) : Player(type, gameLogic) {
        //gameLogic = new StardantGameLogic();
    }
    /**
    * AIPlayer his possible moves and chooses the best move for him using the minimax algorithm.
    * @param options vector of possible moves.
    * @param board Board
    * @param currentCellType Board::Cell (White/Black)
    * @param opponentCellType Board::Cell (White/Black)
    * @return pair<int, int> of cell in the board - the desired move of the player.
     */    pair<int, int> getInput(vector< pair<int,int> > options, const Board* board,
                                   Board::Cell currentCellType, Board::Cell opponentCellType);
    /**
     * AIPlayer d'tor.
     */
    ~AIPlayer();
};
#endif //AIPLAYER_H
