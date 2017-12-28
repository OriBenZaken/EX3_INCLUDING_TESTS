

#ifndef REVERSITESTS_REMOTEGAME_H
#define REVERSITESTS_REMOTEGAME_H
#include <fstream>
#include <sstream>
#include <cstring>
#include "IGame.h"
#include "Client.h"
#include "StandartGameLogic.h"
#include "RemotePlayer.h"
#include "Printer.h"

#define NO_MOVES -2
#define GAME_OVER -3
#define SERVER_DISCONNECTED -4
#define BLACK_TYPE 1
#define WHITE_TYPE 2

//RemoteGame class
class RemoteGame : public IGame {

public:
    /**
     * constructor.
     * @param board - game's board
     * @param serverSettingsFileName - settings file name
     */
    RemoteGame(Board *board, string serverSettingsFileName, Printer* printer) : board(board), printer(printer) {
        client = getServerSettingsFromFile(serverSettingsFileName);
        gameLogic = new StandartGameLogic(board);
        currPlayer = new RemotePlayer(client, printer);
        int typeNum;
        try {
            client->connectToServer();
            this->printer->connectedToServer();
            this->client->GetIntoGameRoom(roomName, printer);
            typeNum = client->getType();
        } catch (...) {
            delete gameLogic;
            delete currPlayer;
            delete client;
            throw "Error while connecting to server";
        }
        if (typeNum == BLACK_TYPE) {
            currPlayer->setType(Board::Black);
            myType = Board::Black;
        } else if (typeNum == WHITE_TYPE) {
            currPlayer->setType(Board::White);
            myType = Board::White;
        } else {    // myType = 0, server disconnected
            this->status = IGame::GameOver;
            return;
        }
        (*this).setOpponentType();
        this->status = IGame::Playing;
    }
    /**
     * run method.
     * runs the game
     */
    void run();
    /**
     * destructor
     */
    ~RemoteGame();


private:

    /**
     * setOpponentType function.
     * sets opponent type
     */
    void setOpponentType();
    //todo: erase irrelevant java docs and add comments
    /**
     * Swap between current player to other player.
     */
    void switchCurrPlayer();
    /**
     * switchTurn function.
     * switch turn between players
     */
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

    /**
     * getServerSettingsFromFile function.
     * @param fileName - settings file name
     * @return client
     */
    Client *getServerSettingsFromFile(string fileName);
    //members
    string roomName;
    GameLogic *gameLogic;
    Printer *printer;
    Board *board;
    Player *currPlayer;
    Board::Cell opponentType;
    Board::Cell myType;
    Status status;
    Client *client;
    int priority;
    int turn;
};


#endif //REVERSITESTS_REMOTEGAME_H
