//
// Created by liz on 03/12/17.
//

#ifndef REVERSITESTS_REMOTEGAME_H
#define REVERSITESTS_REMOTEGAME_H


#include "IGame.h"
#include "client/Client.h"
#include "StandartGameLogic.h"
#include "RemotePlayer.h"
#define NO_MOVES -2
#define GAME_OVER -3

class RemoteGame : public IGame{

public:
    RemoteGame(Board* board): board(board), client("127.0.0.1", 8003) {

        gameLogic = new StandartGameLogic(board);
        currPlayer = new RemotePlayer(&client);
        client.connectToServer();
        int typeNum = client.getType();
        if(typeNum ==0) {
            cout<<"waiting for other player to join..."<<endl;
            typeNum = client.getType();
            if(typeNum==1) {
                currPlayer->setType(Board::Black);
                //for debug only
                cout<<"black"<<endl;
            }
        } else if (typeNum ==2) {
            currPlayer->setType(Board::White);
            //for debug only
            cout<<"white"<<endl;
        }
        (*this).setOpponentType();
    }
    void run();


private:
    GameLogic *gameLogic;
    Board* board;
    Player* currPlayer;
    //Player* otherPlayer;
    Board::Cell opponentType;
    Status status;
    Client client;
    int priority;
    int turn;

    void setOpponentType();
    /**
     * Swap between current player to other player.
     */
    void switchCurrPlayer();
    void switchTurn();
    /**
     * Checks who is the winning player and prints a suitable message to the console.
     */
    void announceWinner();
    /**
     * Announces who's turn now: Black or White player.
     */
    void announceWhoPlayNow();
    /**
     * Announces who just made a move.
     * @param row row of the move cell.
     * @param col column of the move cell.
     */
    void announceWhoMadeAMove(int row, int col);
};



#endif //REVERSITESTS_REMOTEGAME_H
