
#include "TwoPlayersOneComputerGame.h"
using namespace std;

void TwoPlayersOneComputerGame::run() {
    this->printer->printCurrentBoard();
    this->printer->printBoard(this->board);
    while (this->status != GameOver) {
        this->printer->announceWhoPlayNow(currPlayer);
        vector< pair<int, int> > moves = gameLogic->possibleMoves(currPlayer->getType(), otherPlayer->getType());
        if (moves.empty()) {
            // No possible moves for both players. TwoPlayersOneComputerGame Over.
            if (this->status == NoPossibleMoves) {
                this->printer->noPossibleMovesForBothPlayers();
                this->status = GameOver;
                break;
            }
            this->printer->noPossibleMovesForCurrentPlayer();
            switchCurrPlayer();
            this->status = NoPossibleMoves;
            continue;
        } else {
            this->status = Playing;
            pair <int, int> chosenMove = currPlayer->getInput(moves, this->board, currPlayer->getType(), otherPlayer->getType());
            this->gameLogic->makeMove(chosenMove.first, chosenMove.second, currPlayer->getType(), otherPlayer->getType());
            this->printer->announceWhoMadeAMove(chosenMove.first, chosenMove.second, otherPlayer->getType());
            switchCurrPlayer();
            this->printer->printCurrentBoard();
            this->printer->printBoard(this->board);
            if (this->board->getNumOfEmptyCells() == 0) {
                this->status = GameOver;
            }
        }
    }
    this->printer->announceWinner(this->board, currPlayer->getType());
}

void TwoPlayersOneComputerGame::switchCurrPlayer() {
    Player* temp = currPlayer;
    currPlayer = otherPlayer;
    otherPlayer = temp;
}




TwoPlayersOneComputerGame::~TwoPlayersOneComputerGame() {
    delete this->gameLogic;
    delete (*this).currPlayer;
    delete (*this).otherPlayer;
}