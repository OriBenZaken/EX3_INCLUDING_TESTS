//
// Created by ori on 03/12/17.
//

#include "Client.h"
#include "../TwoPlayersOneComputerGame.h"
#include "../RemoteGame.h"
#include <iostream>
#include <stdlib.h>
#define SIZE 8
using namespace std;
int main() {
    cout<<"Hello!"<<endl<<"Please choose one of the following options:"<<endl;
    cout<<"1. a human local player."<<endl;
    cout<<"2. an AI player."<<endl;
    cout<<"3. a remote player."<<endl;

    IGame:: PlayersType playersType;
    string input;
    do {
        getline(cin,input);
        if (input.compare("1") == 0) {
            playersType = IGame::Humans;
        } else if (input.compare("2") == 0) {
            playersType = IGame::HumanVSAI;
        }else if (input.compare("3") ==0) {
            playersType = IGame::RemoteMode;
        } else {
            cout<<"Please choose correct option."<<endl;
        }
    }while (input.compare("1") != 0 && input.compare("2") != 0 && input.compare("3") != 0);
    Board b(SIZE);
    b.initialize();
    IGame* game;
    if (playersType == IGame::Humans || playersType ==IGame::HumanVSAI) {
        game = new TwoPlayersOneComputerGame(&b, playersType);
        game->run();
        delete game;
        return 0;

    }


   /* Client client("127.0.0.1", 8002);*/
    try {
        game = new RemoteGame(&b);
        game->run();
        //client.connectToServer();



    } catch (const char *msg) {
        cout << "Failed to connect to server. Reason:" << msg << endl;
        exit(-1);
    }

    delete game;



    int num1, num2;
    char op;



   /* while (true) {
        cout << "Enter an exercise (e.g., 15*19):";
        cin >> num1 >> op >> num2;
        cout << "Sending exercise: " << num1 << op
             << num2 << endl;
        try {
            int result = client.sendExercise(num1,
                                             op, num2);
            cout << "Result: " << result << endl;
        } catch (const char *msg) {
            cout << "Failed to send exercise to server. Reason: " << msg << endl;
        }
    }*/
}