//
// Created by liz on 03/12/17.
//

#ifndef REVERSITESTS_REMOTEGAME_H
#define REVERSITESTS_REMOTEGAME_H


#include <cstring>
#include "IGame.h"
#include "client/Client.h"
#include "StandartGameLogic.h"
#include "RemotePlayer.h"
#define NO_MOVES -2
#define GAME_OVER -3
#define WAITING 0
#define BLACK_TYPE 1
#define WHITE_TYPE 2
#define KEEP_PLAYING -4


class RemoteGame : public IGame{

public:
    RemoteGame(Board* board, string serverSettingsFileName) : board(board) {
        client = getServerSettingsFromFile(serverSettingsFileName);
        gameLogic = new StandartGameLogic(board);
        currPlayer = new RemotePlayer(client);
        client->connectToServer();
        int typeNum = client->getType();
        if(typeNum ==WAITING) {
            cout<<"waiting for other player to join..."<<endl;
            typeNum = client->getType();
            if(typeNum==BLACK_TYPE) {
                currPlayer->setType(Board::Black);
                myType = Board::Black;
                //for debug only
                cout<<"black"<<endl;

            }
        } else if (typeNum ==WHITE_TYPE) {
            currPlayer->setType(Board::White);
            myType = Board::White;
            //for debug only
            cout<<"white"<<endl;
        }
        (*this).setOpponentType();
    }
    void run();
    ~RemoteGame();


private:
    GameLogic *gameLogic;
    Board* board;
    Player* currPlayer;
    //Player* otherPlayer;
    Board::Cell opponentType;
    Board::Cell myType;
    Status status;
    Client* client;
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
    Client* getServerSettingsFromFile(string fileName);
};



#endif //REVERSITESTS_REMOTEGAME_H
