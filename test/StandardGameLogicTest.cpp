//
// Created by ori on 23/11/17.
//

#include <gmock/gmock-matchers.h>
#include "StandardGameLogicTest.h"
#include "BoardsMatch.h"
/**
 * checks if in the start positions of the board - possible moves of Black player are as they should be.
 */
TEST_F(StandardGameLogicTest, CorrectPossibleMovesTest) {
    vector< pair<int, int> > moves = this->gameLogic.possibleMoves(Board::Black, Board::White);
    vector< pair<int , int> > expectedMoves;
    expectedMoves.push_back(make_pair(1, 2));
    expectedMoves.push_back(make_pair(2, 1));
    expectedMoves.push_back(make_pair(3, 4));
    expectedMoves.push_back(make_pair(4, 3));
    ASSERT_THAT(moves, expectedMoves) << "possible moves of Black player are not as they should be";
}

/**
 * brings board to this state:
 *
 *
*| 1 | 2 | 3 | 4 | 5 | 6 |
*--------------------------
*1| O | O |   |   |   |   |
*--------------------------
*2| O | O | X | X |   | O |
*--------------------------
*3|   |   | X | X | O | O |
*--------------------------
*4|   | X | X | X |   | O |
*--------------------------
*5|   |   |   |   |   |   |
*--------------------------
*6|   |   |   |   |   |   |
*--------------------------
 * checks if Black player got no possible moves in this state.
*/
TEST_F(StandardGameLogicTest, NoPossibleMovesTest) {
    board.initialize();
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
/**
 * checks a correct make move behaviour.
 */
TEST_F(StandardGameLogicTest, ValidMakeMoveTest) {
    board.initialize();
    Board copyBoard(board);
    copyBoard.setCell(2, 1, Board::Black);
    copyBoard.setCell(2, 2, Board::Black);
    gameLogic.makeMove(2, 1, Board::Black, Board::White);
    EXPECT_TRUE(BoardsMatch(board, copyBoard, board.getSize()));
}

/**
 * checks that a not valid move doesn't effect on the board.
 */
TEST_F(StandardGameLogicTest, NotValidMakeMoveTest) {
    board.initialize();
    Board copyBoard(board);
    // Empty cell but not a valid move
    gameLogic.makeMove(4, 2, Board::Black, Board::White);
    EXPECT_TRUE(BoardsMatch(board, copyBoard, board.getSize()));
}