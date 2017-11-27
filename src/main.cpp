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
    cout<<"Hello!"<<endl<<"Please choose one of the following options:"<<endl;
    cout<<"1. I want to play against human."<<endl;
    cout<<"2. I want to play against computer."<<endl;
    IGame:: PlayersType playersType;
    string input;
    do {
        getline(cin,input);
        if (input.compare("1") == 0) {
            playersType = IGame::Humans;
        } else if (input.compare("2") == 0) {
            playersType = IGame::HumanVSAI;
        }else {
            cout<<"Please choose correct option."<<endl;
        }
    }while (input.compare("1") != 0 && input.compare("2") != 0);
    Board b(8);
    b.initialize();
    IGame* game = new TwoPlayersOneComputerGame(&b, playersType);
    game->run();
    delete game;
    return 0;
}