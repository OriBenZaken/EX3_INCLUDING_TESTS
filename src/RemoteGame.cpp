

#include <cstdlib>
#include "RemoteGame.h"

void RemoteGame::setOpponentType() {

    if(currPlayer->getType() ==Board::Black) {
        (*this).opponentType = Board::White;
        (*this).priority = BLACK_TYPE;
    } else {
        (*this).opponentType = Board::Black;
        (*this).priority = WHITE_TYPE;
    }
}

void RemoteGame::run() {
    (*this).turn = BLACK_TYPE;
    cout << "Current board:" << endl;
    this ->board->print();
    while (this->status != GameOver) {
        // My turn
        if(priority==turn) {
             announceWhoPlayNow();
            vector< pair<int, int> > moves = gameLogic->possibleMoves(currPlayer->getType(), (*this).opponentType);
            if (moves.empty()) {
                // No possible moves for both players. TwoPlayersOneComputerGame Over
                if (this->status == NoPossibleMoves) {
                    cout << "No Possible for both players." << endl;
                    this->status = GameOver;
                    (*this).client->sendMoveToServer(GAME_OVER,GAME_OVER);
                    break;
                } else {
                    //inform server this player hasn't moves
                    (*this).client->sendMoveToServer(NO_MOVES,NO_MOVES);
                }
                cout << "No possible moves. Play passes back to the other player. ";
                cout << "Press any key to continue." << endl;
                string keyToContinue;
                getline(cin, keyToContinue);
                switchTurn();
                this->status = NoPossibleMoves;
                continue;
            } else {
                this->status = Playing;
                //take chosen move from player and inform server about the selection
                pair<int, int> chosenMove = currPlayer->getInput(moves, this->board, currPlayer->getType(),
                                                                 opponentType);
                this->gameLogic->makeMove(chosenMove.first, chosenMove.second, currPlayer->getType(),
                                          opponentType);
                cout << "Current board:" << endl;
                this ->board->print();
            }
            // Opponent turn
        } else {
            //the waiting player side
            cout <<"Waiting to other player's move..."<<endl;
            int otherPlayerGameStatus = this->client->getOtherPlayerGameStatusFromServer();
            if (otherPlayerGameStatus == GAME_OVER) {
                this->status = GameOver;
                break;
            }
            pair<int, int> chosenMove = (*this).client->getMoveFromServer();
            if (chosenMove.first !=NO_MOVES && chosenMove.second !=NO_MOVES) {
                this->gameLogic->makeMove(chosenMove.first, chosenMove.second,
                                          opponentType,currPlayer->getType());
                announceWhoMadeAMove(chosenMove.first,chosenMove.second);
                cout << "Current board:" << endl;
                this ->board->print();
                this->status = Playing;
            } else {
                (*this).status = NoPossibleMoves;

            }
        }
        //reach this point anyway
        if (this->board->getNumOfEmptyCells() == 0) {
            this->status = GameOver;
        }
        switchTurn();
        //my turn
        if (this->turn == priority) {
            if (this->status == GameOver) {
                // let know the server that the game is over
                this->client->sendGameStatusToServer(GAME_OVER);
            } else {
                // let know the server that the game continues
                this->client->sendGameStatusToServer(KEEP_PLAYING);
            }
        }

    }

    announceWinner();
}

void RemoteGame:: switchTurn() {

    if ((*this).turn ==BLACK_TYPE) {
        (*this).turn = WHITE_TYPE;
    } else {
        (*this).turn = BLACK_TYPE;
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
        if (myType == Board::Black) {
            cout << "Congratulations X! You Won!." << endl;
        } else {
            cout << "O you're such a LOSER!." << endl;

        }
    } else if (numOfWhites > numOfBlacks) {
        if (myType == Board::White) {
            cout << "Congratulations O! You Won!." << endl;
        } else {
            cout << "X you're such a LOSER!." << endl;
        }
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

Client* RemoteGame::getServerSettingsFromFile(string fileName) {
    try {
        const char *serverSettingsFileName = fileName.c_str();
        ifstream fileInput(serverSettingsFileName); // supposed to be fileName. Just for debug.
        if (fileInput == NULL) {
            perror("Error while open the server settings file");
        }
        string IPString;
        string portString;
        getline(fileInput, IPString);
        getline(fileInput, portString);
        IPString = IPString.replace(0, sizeof("IP: ") - 1, "");
        IPString = IPString.replace(0, 0, "");
        portString = portString.replace(0, sizeof("Port: ") - 1, "");
        stringstream ss(portString);
        int port = 0;
        ss >> port;
        char *writable = new char[IPString.size() + 1];
        std::copy(IPString.begin(), IPString.end(), writable);
        writable[IPString.size()] = '\0';
        return new Client(writable, port);
    } catch (char* ex) {
        cout<<"error while reading settings file";
        exit(-1);
    }
}

RemoteGame::~RemoteGame() {
    delete this->client;
    delete this->gameLogic;
    delete this->currPlayer;
}

void RemoteGame::announceWhoMadeAMove(int row, int col) {
    if (opponentType ==  Board::Black) {
        cout << "X played (" << row + 1 << "," << col + 1 << ")" << endl;
    } else {
        cout << "O played (" << row + 1 << "," << col + 1 << ")" << endl;
    }
}