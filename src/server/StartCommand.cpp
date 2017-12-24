//
// Created by liz on 22/12/17.
//

#include <unistd.h>
#include "StartCommand.h"
void StartCommand:: execute(vector<string> args,vector<Room> &rooms){

    Room::RoomStatus roomStatus;
    bool isValid = true;
    //todo: add mutex
    pthread_mutex_t count_mutex;
    pthread_mutex_lock(&count_mutex);
    for (int i = 0; i < rooms.size(); i++) {
        if ((rooms.at(i).getRoomName().compare(args.at(1)) == 0)) {
            isValid = false;
            break;
        }
    }
    pthread_mutex_unlock(&count_mutex);

    if (!isValid) {
        int msg= ERROR;
        int n = write(clientSocket, &msg, sizeof(msg));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
    } else {
        Room room;
        room.setRoomName(args.at(1));
        room.setRoomStatus(Room::WaittingToOtherPlayer);
        room.setFirstClientSocket((*this).clientSocket);
        rooms.push_back(room);
        int msg = VALID;
        int n = write(clientSocket, &msg, sizeof(msg));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
            return;
        }
    }

}

StartCommand::StartCommand(int clientSocket) : Command(clientSocket) {}
