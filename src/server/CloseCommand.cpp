
#include <unistd.h>
#include "CloseCommand.h"
void CloseCommand::execute(vector<string> args,vector<Room> &rooms) {

    pthread_mutex_t count_mutex;
    pthread_mutex_lock(&count_mutex);
    for (int i = 0; i < rooms.size(); i++) {
        if (rooms.at(i).getRoomName().compare(args.at(1)) == 0) {
            //update opponent game is over
            int gameStatus = GAME_OVER;
            int n = write(rooms.at(i).getSecondClientSocket(),&gameStatus,sizeof(gameStatus));
            // notify other player the game is over
            if (n ==-1) {
                cout <<"Error writing to socket" <<endl;
                return;
            }

            close(rooms.at(i).getFirstClientSocket());
            close(rooms.at(i).getSecondClientSocket());
            break;

        }
    }
    pthread_mutex_unlock(&count_mutex);


}

CloseCommand::CloseCommand(int clientSocket) : Command(clientSocket) {}
