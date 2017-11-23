//
// Created by ori on 23/11/17.
//

#include <gmock/gmock-matchers.h>
#include "gtest/gtest.h"
#include "StandardGameLogicTest.h"

TEST_F(StandardGameLogicTest, CorrectPossibleMovesTest) {
    board.print();
    vector< pair<int, int> > moves = this->gameLogic.possibleMoves(Board::Black, Board::White);
    vector< pair<int , int> > expectedMoves;
    expectedMoves.push_back(make_pair(1, 2));
    expectedMoves.push_back(make_pair(2, 1));
    expectedMoves.push_back(make_pair(3, 4));
    expectedMoves.push_back(make_pair(4, 3));
    ASSERT_THAT(moves, expectedMoves);
}

TEST_F(StandardGameLogicTest, NoPossibleMovesTest) {
    board.setCell(0,0,Board::White);
    board.setCell(0,1,Board::White);
    board.setCell(1,0,Board::White);
    board.setCell(1,1,Board::White);
    board.setCell(1,2,Board::Black);
    board.setCell(1,3,Board::Black);
    board.setCell(1,5,Board::White);
    board.setCell(2,2,Board::Black);
    board.setCell(2,3,Board::Black);
    board.setCell(2,4,Board::White);
    board.setCell(2,5,Board::White);
    board.setCell(3,1,Board::Black);
    board.setCell(3,2,Board::Black);
    board.setCell(3,3,Board::Black);
    board.setCell(3,5,Board::White);

    vector< pair<int, int> > moves = this->gameLogic.possibleMoves(Board::Black, Board::White);
    vector< pair<int , int> > expectedMoves;

    ASSERT_THAT(moves, expectedMoves);
}