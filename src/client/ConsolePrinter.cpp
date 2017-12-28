
#include "ConsolePrinter.h"


void ConsolePrinter::printCurrentBoard() {
    cout << "Current board:" << endl;
}

void ConsolePrinter::printBoard(Board *board) {
    int size = board->getSize();
    cout << " |";
    for (int i = 0 ; i <  size; i++) {
        if (i < 9) {
            cout << " ";
        }
        cout << i + 1 << " |";
    }
    cout << endl;
    for (int i = 0 ; i <  2 + 4 * size ; i++) {
        cout << "-";
    }
    for (int i = 0 ; i <  size ; i++) {
        cout << endl << i + 1 << "|";
        for (int j = 0; j < size; j++) {
            cout << " ";
            switch(board->getCell(i,j)) {
                case Board::Empty:
                    cout << " ";
                    break;
                case Board::White:
                    cout << "O";
                    break;
                case Board::Black:
                    cout << "X";
                    break;
            }
            cout << " |";
        }
        cout << endl;
        for (int k = 0 ; k <  2 + 4 * size ; k++) {
            cout << "-";
        }
    }
    cout << endl;
}

void ConsolePrinter::noPossibleMovesForBothPlayers() {
    cout << "No Possible for both players." << endl;
}

void ConsolePrinter::noPossibleMovesForCurrentPlayer() {
    cout << "No possible moves. Play passes back to the other player. ";
    cout << "Press any key to continue." << endl;
    string keyToContinue;
    getline(cin, keyToContinue);
}

void ConsolePrinter::waitForOtherPlayerMove() {
    cout <<"Waiting to other player's move..."<< endl;
}

void ConsolePrinter::announceWinner(Board* board, Board::Cell myType) {
    IGame::Status winningStatus = IGame::checkWinner(board);
    if (winningStatus == IGame::BlackWins) {
        if (myType == Board::Black) {
            cout << "Congratulations X! You Won!." << endl;
        } else {
            cout << "O you're such a LOSER!." << endl;

        }
    } else if (winningStatus == IGame::WhiteWins) {
        if (myType == Board::White) {
            cout << "Congratulations O! You Won!." << endl;
        } else {
            cout << "X you're such a LOSER!." << endl;
        }
    } else {
        cout << "It's a tie." << endl;
    }
}

void ConsolePrinter::announceWhoPlayNow(Player* currPlayer) {
    if (currPlayer->getType() == Board::Black) {
        cout << "X: It's your move." << endl;

    } else {
        cout << "O: It's your move." << endl;
    }
}

void ConsolePrinter::announceWhoMadeAMove(int row, int col, Board::Cell opponentType) {
    if (opponentType ==  Board::Black) {
        cout << "X played (" << row + 1 << "," << col + 1 << ")" << endl;
    } else {
        cout << "O played (" << row + 1 << "," << col + 1 << ")" << endl;
    }
}

void ConsolePrinter::printPossibleMoves(vector<pair<int, int> > options) {
    int i = 0;
    cout << "Your possible moves: ";
    cout << "(" << options[i].first + 1 << "," << options[i].second + 1 << ")";
    while (i + 1 < options.size()) {
        i++;
        cout << ",(" << options[i].first + 1 << "," << options[i].second + 1 << ")";
    }
}

void ConsolePrinter::enterYourMove() {
    cout << endl << "Please enter your move row,col:" << endl;
}

void ConsolePrinter::illegalMoveInput() {
    cout << "The move you chose is illegal. Try again." << endl;
}

void ConsolePrinter::illegalMoveInputFormat() {
    cout << "Wrong input format. Should be 'row,col'. Let's try again." << endl;
}

string ConsolePrinter::mainMenu() {
    cout<<"Hello!"<<endl<<"Please choose one of the following options:"<<endl;
    cout<<"1. a human local player."<<endl;
    cout<<"2. an AI player."<<endl;
    cout<<"3. a remote player."<<endl;
    IGame:: PlayersType playersType;
    string input = "";
    getline(cin,input);
    return input;
}

void ConsolePrinter::invalidInputMainMenu() {
    cout << "Please choose correct option." << endl;
}

void ConsolePrinter::errorConnectingToServerAndExitMsg(const char *msg) {
    cout << endl << "Failed to connect to server. Reason: " << msg << endl;
    cout << "Game ended, we're sorry. Have a nice week" << endl;
}

void ConsolePrinter::remoteGameWelcomeMsg() {
    cout << "Welcome to Reversi Online!" << endl;
}

string ConsolePrinter::remoteGameMainMenu() {
    string choice;
    cout << "Please, choose between the following options: (enter number of option)" << endl;
    cout << "1. Create a new game room." << endl;
    cout << "2. Join to existing game room." << endl;
    cout << "3. Show all available game rooms." << endl;
    getline(cin, choice);
    return choice;
}

string ConsolePrinter::enterNameForNewRoom() {
    string choice;
    cout << "Enter room name for the new room:" << endl;
    getline(cin, choice);
    return choice;
}

void ConsolePrinter::newRoomWasCreated(string name) {
    cout << "New room '" << name << "' was created. Waiting for second player to join..." << endl;
}

void ConsolePrinter::requestWasRejectedByServer() {
    cout << "Request was rejected by server. Let's try again." << endl;
}

void ConsolePrinter::noExistingRooms() {
    cout << "No existing rooms." << endl;
}

string ConsolePrinter::printJoinGameRooms(vector<string> rooms) {
    string choice;
    cout << "Enter the name of room to join between the existing rooms:" << endl;
    for (int i = 0; i < rooms.size(); i++) {
        cout << i + 1 << ". " << rooms[i] << endl;
    }
    getline(cin, choice);
    return choice;
}

void ConsolePrinter::joinedToRoom(string name) {
    cout << "Joined to room '" << name << "'." << endl;
}

void ConsolePrinter::printGameRooms(vector<string> rooms) {
    string choice;
    cout << "Available game rooms:" << endl;
    for (int i = 0; i < rooms.size(); i++) {
        cout << i + 1 << ". " << rooms[i] << endl;
    }
    cout << endl << "Press any key + enter to go back to the main menu." << endl;
    getline(cin, choice);
}

void ConsolePrinter::connectedToServer() {
    cout << "Connected to server." << endl;
}


ConsolePrinter::~ConsolePrinter() {
}