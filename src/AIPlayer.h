//
// Created by liz on 19/11/17.
//

#ifndef AIPLAYER_H
#define AIPLAYER_H


#include "Player.h"
#include "GameLogic.h"

class AIPlayer : public Player {

public:
/**
 * AIPlayer c'tor
 * @param type Board::Cell (Black/White)
 */

    AIPlayer(Board::Cell type, GameLogic* gameLogic) : Player(type, gameLogic) {
        //gameLogic = new StardantGameLogic();

    }

    pair<int, int> getInput(vector< pair<int,int> > options, const Board* board,
                                      Board::Cell currentCellType, Board::Cell opponentCellType);
    ~AIPlayer();





};


#endif //AIPLAYER_H
