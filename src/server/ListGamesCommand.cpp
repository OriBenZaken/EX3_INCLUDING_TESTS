
#include "ListGamesCommand.h"
int ListGamesCommand:: execute(vector<string> args,vector<Room> &rooms,pthread_mutex_t &count_mutex) {
    string roomNames = "";
    pthread_mutex_lock(&count_mutex);
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms.at(i).getRoomStatus() == Room::WaittingToOtherPlayer) {
            if (i == rooms.size() - 1) {
                roomNames += rooms.at(i).getRoomName();
            } else {
                roomNames += rooms.at(i).getRoomName() + ",";

            }
        }
    }
    pthread_mutex_unlock(&count_mutex);

    //write size of string to client
    int len = roomNames.length() + 1;
    int n = write(clientSocket, &len, sizeof(len));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return ERROR;
    }
    //write the string to client
    char msg[len];
    roomNames.copy(msg, len);
    n = write((*this).clientSocket, msg, len);
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return ERROR;
    }
    return VALID;


}

ListGamesCommand::ListGamesCommand(int clientSocket) : Command(clientSocket) {}


