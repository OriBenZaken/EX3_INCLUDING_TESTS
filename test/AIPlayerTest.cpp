//
// Created by liz on 25/11/17.
//


#include <gmock/gmock-matchers.h>
#include "../src/Board.h"
#include "AIPlayerTest.h"


bool isExpectedMove(vector< pair<int,int> > correctOptions, pair<int,int> pairRecieved) {
    //check if recieved option is one of the exspected options
   for (int i=0; i<correctOptions.size();i++) {
       if(correctOptions[i] == pairRecieved) {
           return true;
       }
   }
    return false;
}



TEST_F(AIPlayerTest, ValidMakeMoveTest1) {
    board.initialize();
    Board copyBoard(board);
    copyBoard.setCell(3, 3, Board::Empty);
    copyBoard.setCell(2, 3, Board::White);
    copyBoard.setCell(1, 2, Board::White);
    copyBoard.setCell(2, 2, Board::Black);
    copyBoard.setCell(3, 2, Board::Black);
    gameLogic->setBoard(&copyBoard);
    vector< pair<int,int> > options = gameLogic->possibleMoves(Board::White,Board::Black);
    pair<int,int> recievedPair = player->getInput(options,&copyBoard,Board::White,Board::Black);
    vector< pair<int,int> > correctOptions;
    correctOptions.push_back(make_pair(4,1));
    correctOptions.push_back(make_pair(4,2));

    EXPECT_TRUE(isExpectedMove(correctOptions, recievedPair));
}

TEST_F(AIPlayerTest, noMovesForOpponent) {
    board.initialize();
    Board copyBoard(board);
    copyBoard.setCell(2, 2, Board::Empty);
    copyBoard.setCell(2, 3, Board::Empty);
    copyBoard.setCell(3, 2, Board::Empty);
    copyBoard.setCell(3, 3, Board::Empty);

    copyBoard.setCell(0, 1, Board::Black);
    copyBoard.setCell(0, 2, Board::Black);
    copyBoard.setCell(0, 3, Board::Black);
    copyBoard.setCell(0, 4, Board::Black);
    copyBoard.setCell(1, 4, Board::Black);

    copyBoard.setCell(0, 5, Board::White);

    gameLogic->setBoard(&copyBoard);
    vector< pair<int,int> > options = gameLogic->possibleMoves(Board::White,Board::Black);
    pair<int,int> recievedPair = player->getInput(options,&copyBoard,Board::White,Board::Black);
    vector< pair<int,int> > correctOptions;
    correctOptions.push_back(make_pair(0,0));

    EXPECT_TRUE(isExpectedMove(correctOptions, recievedPair));
}




TEST_F(AIPlayerTest, ValidMakeMoveTest2) {
    board.initialize();
    Board copyBoard(board);
    copyBoard.setCell(2, 2, Board::Empty);
    copyBoard.setCell(2, 3, Board::Empty);
    copyBoard.setCell(3, 2, Board::Empty);
    copyBoard.setCell(3, 3, Board::Empty);

    copyBoard.setCell(2, 1, Board::Black);
    copyBoard.setCell(3, 2, Board::Black);
    copyBoard.setCell(4, 3, Board::Black);
    copyBoard.setCell(4, 4, Board::Black);
    copyBoard.setCell(3, 4, Board::Black);
    copyBoard.setCell(3, 2, Board::Black);


    copyBoard.setCell(3, 1, Board::White);
    copyBoard.setCell(4, 2, Board::White);
    copyBoard.setCell(5, 3, Board::White);
    copyBoard.setCell(5, 4, Board::White);


    gameLogic->setBoard(&copyBoard);
    vector< pair<int,int> > options = gameLogic->possibleMoves(Board::White,Board::Black);
    pair<int,int> recievedPair = player->getInput(options,&copyBoard,Board::White,Board::Black);
    vector< pair<int,int> > correctOptions;
    correctOptions.push_back(make_pair(1,0));

    EXPECT_TRUE(isExpectedMove(correctOptions, recievedPair));
}

AIPlayerTest::~AIPlayerTest() {

    delete gameLogic;
    delete player;

}

