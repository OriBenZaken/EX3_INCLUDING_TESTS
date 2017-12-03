//
// Created by liz on 03/12/17.
//

#include "RemoteGame.h"

void RemoteGame::setOpponentType() {

    if(currPlayer->getType() ==Board::Black) {
        (*this).opponentType = Board::White;
        (*this).priority = 1;
    } else {
        (*this).opponentType = Board::Black;
        (*this).priority = 2;
    }

}


void RemoteGame::run() {
    (*this).turn = 1;
    cout << "Current board:" << endl;
    this ->board->print();
    while (this->status != GameOver) {
        if(priority==turn) {
            announceWhoPlayNow();
            vector< pair<int, int> > moves = gameLogic->possibleMoves(currPlayer->getType(), (*this).opponentType);
            if (moves.empty()) {
                // No possible moves for both players. TwoPlayersOneComputerGame Over
                if (this->status == NoPossibleMoves) {
                    cout << "No Possible for both players." << endl;
                    this->status = GameOver;
                    (*this).client.sendMoveToServer(GAME_OVER,GAME_OVER);
                    break;
                } else {
                    //inform server this player hasn't moves
                    (*this).client.sendMoveToServer(NO_MOVES,NO_MOVES);
                }
                cout << "No possible moves. Play passes back to the other player. ";
                cout << "Press any key to continue." << endl;
                string keyToContinue;
                getline(cin, keyToContinue);
                //switchCurrPlayer();
                this->status = NoPossibleMoves;
                continue;
            } else {
                this->status = Playing;
                //take chosen move from player and inform server about the selection
                pair<int, int> chosenMove = currPlayer->getInput(moves, this->board, currPlayer->getType(),
                                                                 opponentType);

                this->gameLogic->makeMove(chosenMove.first, chosenMove.second, currPlayer->getType(),
                                          opponentType);
                cout<<"!!!!!!!!!!!"<<chosenMove.first<<" "<<chosenMove.second<<endl;

                cout << "Current board:" << endl;
                this ->board->print();


            }
        } else {
            //the waiting player side
            cout <<"Waiting to other player's move..."<<endl;
            pair<int, int> chosenMove = (*this).client.getMoveFromServer();
            cout<<"!!!!!!!!!!!"<<chosenMove.first<<" "<<chosenMove.second<<endl;
            if (chosenMove.first !=NO_MOVES && chosenMove.second !=NO_MOVES) {
                this->gameLogic->makeMove(chosenMove.first, chosenMove.second, currPlayer->getType(),
                                          opponentType);
                cout << "Current board:" << endl;
                this ->board->print();
            }
        }
        //reach this point anyway
        if (this->board->getNumOfEmptyCells() == 0) {
            //todo:tell server game is over!!!!
            this->status = GameOver;
        }
        switchTurn();

    }

    announceWinner();
}

void RemoteGame:: switchTurn() {

    if ((*this).turn ==1) {
        ((*this).turn =2);
    } else {
        (*this).turn = 1;
    }
}

void RemoteGame::announceWinner() {
    int numOfWhites = 0;
    int numOfBlacks = 0;
    int size = this->board->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (this->board->getCell(i, j) == Board::Black) {
                numOfBlacks++;
            } else if (this->board->getCell(i, j) == Board::White) {
                numOfWhites++;
            }
        }
    }
    if (numOfBlacks > numOfWhites) {
        cout << "Congratulations X! You Won!." << endl;
    } else if (numOfWhites > numOfBlacks) {
        cout << "Congratulations O! You Won!." << endl;
    } else {
        cout << "It's a tie." << endl;
    }
}


void RemoteGame::announceWhoPlayNow() {
    if (this->currPlayer->getType() == Board::Black) {
        cout << "X: It's your move." << endl;

    } else {
        cout << "O: It's your move." << endl;
    }
}