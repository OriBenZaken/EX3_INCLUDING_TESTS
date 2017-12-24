
#include "JoinCommand.h"
#include <fstream>
#include <sstream>
#include <unistd.h>

int JoinCommand:: execute(vector<string> args,vector<Room> &rooms) {

    Room::RoomStatus roomStatus;
    bool isValid = false;
    //todo: add mutex
    pthread_mutex_t count_mutex;
    pthread_mutex_lock(&count_mutex);
    int indexOfRoom;
    for (int i = 0; i < rooms.size(); i++) {
        if ((rooms.at(i).getRoomName().compare(args.at(1)) == 0)&&
                rooms.at(i).getRoomStatus() == Room::WaittingToOtherPlayer) {
            isValid = true;
            rooms.at(i).setRoomStatus(Room::TwoPlayersConnected);
            rooms.at(i).setSecondClientSocket((*this).clientSocket);
            indexOfRoom = i;
            break;

        }
    }
    pthread_mutex_unlock(&count_mutex);
    if (!isValid) {
        int msg= ERROR;
        int n = write(clientSocket, &msg, sizeof(msg));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return ERROR;
        }
    } else {
        int msg = VALID;
        int n = write(clientSocket, &msg, sizeof(msg));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return ERROR;
        }

        //write players type for both players
        int result = BLACK_TYPE;
        n = write(rooms.at(indexOfRoom).getFirstClientSocket(), &result, sizeof(result));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return ERROR;
        }
        result = WHITE_TYPE;
        n = write(rooms.at(indexOfRoom).getSecondClientSocket(), &result, sizeof(result));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return ERROR;
        }
        return VALID;
    }

}

JoinCommand::JoinCommand(int clientSocket) : Command(clientSocket) {}
