//
// Created by ori on 23/11/17.
//

#ifndef REVERSITESTS_STANDARDGAMELOGICTEST_H
#define REVERSITESTS_STANDARDGAMELOGICTEST_H


#include <gtest/gtest.h>
#include "StandardGameLogicTest.h"
#include "../src/StandartGameLogic.h"
/**
 * class for StandardGameLogic test.
 */
class StandardGameLogicTest : public testing::Test {
public:
    /**
     * StandardGameLogicTes d'tor
     */
    StandardGameLogicTest() : board(6), gameLogic(&board){
        board.initialize();
    }

protected:
    Board board;
    StandartGameLogic gameLogic;
};

#endif //REVERSITESTS_STANDARDGAMELOGICTEST_H
