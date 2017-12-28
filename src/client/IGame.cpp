
#include "IGame.h"

IGame::Status IGame::checkWinner(Board* board) {
    int numOfWhites = 0;
    int numOfBlacks = 0;
    int size = board->getSize();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board->getCell(i, j) == Board::Black) {
                numOfBlacks++;
            } else if (board->getCell(i, j) == Board::White) {
                numOfWhites++;
            }
        }
    }
    if (numOfBlacks > numOfWhites) {
        return BlackWins;
    } else if (numOfWhites > numOfBlacks) {
        return WhiteWins;
    } else {
        return Tie;
    }
}