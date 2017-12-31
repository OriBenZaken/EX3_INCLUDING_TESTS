
#include "PlayCommand.h"
int PlayCommand:: execute(vector<string> args,vector<Room> &rooms,pthread_mutex_t &count_mutex) {
    int x, y;
    istringstream(args.at(1)) >> x;
    istringstream(args.at(2)) >> y;
    pthread_mutex_lock(&count_mutex);
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms.at(i).getRoomStatus() == Room::Running) {
            if ((rooms.at(i).getFirstClientSocket()) == clientSocket) {
                int n = write(rooms.at(i).getSecondClientSocket(), &x, sizeof(x));
                if (n == -1) {
                    cout << "Error writing to socket" << endl;
                    return ERROR;
                }
                n = write(rooms.at(i).getSecondClientSocket(), &y, sizeof(y));
                if (n == -1) {
                    cout << "Error writing to socket" << endl;
                    return ERROR;
                }
                break;
            } else if ((rooms.at(i).getSecondClientSocket()) == clientSocket) {
                int n = write(rooms.at(i).getFirstClientSocket(), &x, sizeof(x));
                if (n == -1) {
                    cout << "Error writing to socket" << endl;
                    return ERROR;
                }
                n = write(rooms.at(i).getFirstClientSocket(), &y, sizeof(y));
                if (n == -1) {
                    cout << "Error writing to socket" << endl;
                    return ERROR;
                }
                break;
            }
        }
    }

    pthread_mutex_unlock(&count_mutex);
    return VALID;
}



PlayCommand::PlayCommand(int clientSocket) : Command(clientSocket) {

}
