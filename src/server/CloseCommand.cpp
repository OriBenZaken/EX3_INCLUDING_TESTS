
#include <unistd.h>
#include "CloseCommand.h"
int CloseCommand::execute(vector<string> args,vector<Room> &rooms) {


    //todo: add mutex
    pthread_mutex_t count_mutex;
    pthread_mutex_lock(&count_mutex);

    for (int i = 0; i < rooms.size(); i++) {
        if ((rooms.at(i).getFirstClientSocket())==clientSocket) {
            int gameStatus = GAME_OVER;
            int n = write(rooms.at(i).getSecondClientSocket(),&gameStatus,sizeof(gameStatus));
            // notify other player the game is over
            if (n ==-1) {
                cout <<"Error writing to socket" <<endl;
                return ERROR;
            }
            rooms.at(i).setRoomStatus(Room::Stopped);
            close(rooms.at(i).getFirstClientSocket());
            close(rooms.at(i).getSecondClientSocket());
            break;
        } else if ((rooms.at(i).getSecondClientSocket())==clientSocket) {
            int gameStatus = GAME_OVER;
            int n = write(rooms.at(i).getFirstClientSocket(),&gameStatus,sizeof(gameStatus));
            // notify other player the game is over
            if (n ==-1) {
                cout <<"Error writing to socket" <<endl;
                return ERROR;
            }
            rooms.at(i).setRoomStatus(Room::Stopped);
            close(rooms.at(i).getFirstClientSocket());
            close(rooms.at(i).getSecondClientSocket());

            break;
        }
    }

    pthread_mutex_unlock(&count_mutex);
    return VALID;







}

CloseCommand::CloseCommand(int clientSocket) : Command(clientSocket) {}
