

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
#define WAITING 0
#define BLACK_TYPE 1
#define WHITE_TYPE 2
#define KEEP_PLAYING -4

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
        client->connectToServer();
        int typeNum = client->getType();
        cout << "Connected to server." << endl;
        if (typeNum == WAITING) {
            cout << "waiting for other player to join..." << endl;
            typeNum = client->getType();
            if (typeNum == BLACK_TYPE) {
                currPlayer->setType(Board::Black);
                myType = Board::Black;
            }
        } else if (typeNum == WHITE_TYPE) {
            currPlayer->setType(Board::White);
            myType = Board::White;
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
    //todo: erase java docs
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
    string name;
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