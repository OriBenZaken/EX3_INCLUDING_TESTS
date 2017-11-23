//
// Created by Ori Ben Zaken on 23/10/17.
// ID: 311492110
//
#include <iostream>
#include "Board.h"
#include "TwoPlayersOneComputerGame.h"
using namespace std;

/**
 * creates a new Reversi game and runs it.
 * @return 0
 */
int main() {

    Board b(8);

    b.initialize();
    //Board copy(b);

    IGame* game = new TwoPlayersOneComputerGame(&b, IGame::HumanVSAI);
    game->run();
    delete game;
  /*  delete p1;
    delete p2;*/
    return 0;
}