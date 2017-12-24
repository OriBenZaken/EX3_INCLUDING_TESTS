
#ifndef REVERSITESTS_ROOM_H
#define REVERSITESTS_ROOM_H

#include <sstream>


using namespace std;
class Room {

public:
    Room(){}
    enum RoomStatus {WaittingToOtherPlayer, TwoPlayersConnected, Running, Stopped};

    const string &getRoomName() const;

    void setRoomName(const string &roomName);

    int getFirstClientSocket() const;

    void setFirstClientSocket(int firstClientSocket);

    int getSecondClientSocket() const;

    void setSecondClientSocket(int secondClientSocket);
    RoomStatus getRoomStatus() const;

    void setRoomStatus(RoomStatus roomStatus);



private:
    string roomName;
    int firstClientSocket;
    int secondClientSocket;
    RoomStatus roomStatus;



};


#endif //REVERSITESTS_ROOM_H
