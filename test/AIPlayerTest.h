//
// Created by liz on 25/11/17.
//

#ifndef REVERSITESTS_AIPLAYERTEST_H
#define REVERSITESTS_AIPLAYERTEST_H


#include <gtest/gtest.h>
#include "StandardGameLogicTest.h"
#include "StandardGameLogicTest.h"
#include "../src/StandartGameLogic.h"
#include "../src/AIPlayer.h"

class AIPlayerTest : public testing::Test {
public:
    AIPlayerTest() : board(6){
        board.initialize();
        gameLogic = new StandartGameLogic(&board);

        player = new AIPlayer(Board::White, gameLogic);
    }
    ~AIPlayerTest();

protected:
    Board board;
    StandartGameLogic* gameLogic;
    AIPlayer* player;
};


#endif //REVERSITESTS_AIPLAYERTEST_H
