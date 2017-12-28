/**
 * AIPlayerTest class.
 * include tests for AIPlayer takeInput method
 */
#ifndef REVERSITESTS_AIPLAYERTEST_H
#define REVERSITESTS_AIPLAYERTEST_H

#include <gtest/gtest.h>
#include "StandardGameLogicTest.h"
#include "StandardGameLogicTest.h"
#include "../src/client/StandartGameLogic.h"
#include "../src/client/AIPlayer.h"
#include <gmock/gmock-matchers.h>
#include "../src/client/Board.h"

class AIPlayerTest : public testing::Test {
public:
    /**
     * constructor.
     * initialize board, gameLogic and player.
     */
    AIPlayerTest() : board(TEST_SIZE){
        board.initialize();
        gameLogic = new StandartGameLogic(&board);

        player = new AIPlayer(Board::White, gameLogic);
    }
    /**
     * destructor.
     * frees memory allocation.
     */
    ~AIPlayerTest();
    /**
     * isExpectedMove function.
     * @param correctOptions - correct optional options.
     * @param pairReceived  - the received pair.
     * @return true if correct, false otherwise
     */
    bool isExpectedMove(vector< pair<int,int> > correctOptions, pair<int,int> pairReceived);

protected:
    //members
    Board board;
    StandartGameLogic* gameLogic;
    AIPlayer* player;
};


#endif //REVERSITESTS_AIPLAYERTEST_H
