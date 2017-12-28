

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

//todo: delete unrelevant comments
void RemoteGame::run() {
    (*this).turn = BLACK_TYPE;
    this->printer->printCurrentBoard();
    this->printer->printBoard(this->board);
    while (this->status != GameOver) {
        // My turn
        if(priority==turn) {
            this->printer->announceWhoPlayNow(this->currPlayer);
            vector< pair<int, int> > moves = gameLogic->possibleMoves(currPlayer->getType(), (*this).opponentType);
            if (moves.empty()) {
                // No possible moves for both players. TwoPlayersOneComputerGame Over
                if (this->status == NoPossibleMoves) {
                    this->printer->noPossibleMovesForBothPlayers();
                    this->status = GameOver;
                    //(*this).client->sendMoveToServer(GAME_OVER,GAME_OVER)
                    this->client->sendPlayCommand(NO_MOVES, NO_MOVES);
                    this->client->sendCloseGameRequest(this->roomName);
                    break;
                } else {
                    //inform server this player hasn't moves
                    //(*this).client->sendMoveToServer(NO_MOVES,NO_MOVES);
                    this->client->sendPlayCommand(NO_MOVES, NO_MOVES);
                }
                this->printer->noPossibleMovesForCurrentPlayer();
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
                this->printer->printCurrentBoard();
                this->printer->printBoard(this->board);
            }
            // Opponent turn
        } else {
            //the waiting player side
            this->printer->waitForOtherPlayerMove();
            /* int otherPlayerGameStatus = this->client->getOtherPlayerGameStatusFromServer();
             if (otherPlayerGameStatus == GAME_OVER) {
                 this->status = GameOver;
                 break;
             }*/
            pair<int, int> chosenMove = (*this).client->getMoveFromServer();
            if (chosenMove.first == GAME_OVER) {
                this->status = GameOver;
                break;
            }
            if (chosenMove.first !=NO_MOVES && chosenMove.second !=NO_MOVES) {
                this->gameLogic->makeMove(chosenMove.first, chosenMove.second,
                                          opponentType,currPlayer->getType());
                this->printer->announceWhoMadeAMove(chosenMove.first, chosenMove.second, opponentType);
                this->printer->printCurrentBoard();
                this->printer->printBoard(board);
                this->status = Playing;
            } else {
                (*this).status = NoPossibleMoves;

            }
        }
        //reach this point anyway
        if (this->board->getNumOfEmptyCells() == 0) {
            this->status = GameOver;
            (*this).client->sendCloseGameRequest((*this).roomName);
        }
        switchTurn();
    }

    this->printer->announceWinner(this->board, myType);
}


void RemoteGame:: switchTurn() {

    if ((*this).turn ==BLACK_TYPE) {
        (*this).turn = WHITE_TYPE;
    } else {
        (*this).turn = BLACK_TYPE;
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
        throw "Something is wrong with the server settings file";
    }
}

RemoteGame::~RemoteGame() {
    delete this->client;
    delete this->gameLogic;
    delete this->currPlayer;
}