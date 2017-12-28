/**
 * StandardGameLogicTest class.
 * include tests for class StandardGameLogic
 */
#ifndef REVERSITESTS_STANDARDGAMELOGICTEST_H
#define REVERSITESTS_STANDARDGAMELOGICTEST_H
#define TEST_SIZE 6

#include <gtest/gtest.h>
#include "StandardGameLogicTest.h"
#include "../src/client/StandartGameLogic.h"
#include <gmock/gmock-matchers.h>
#include "BoardsMatch.h"

/**
 * class for StandardGameLogic test.
 */
class StandardGameLogicTest : public testing::Test {
public:
    /**
     * StandardGameLogicTes d'tor
     */
    StandardGameLogicTest() : board(TEST_SIZE), gameLogic(&board){
        board.initialize();
    }

protected:
    Board board;
    StandartGameLogic gameLogic;
};

#endif //REVERSITESTS_STANDARDGAMELOGICTEST_H
