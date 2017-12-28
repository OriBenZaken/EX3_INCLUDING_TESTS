/**
 * Room class.
 * represents room of the game
 */
#ifndef REVERSITESTS_ROOM_H
#define REVERSITESTS_ROOM_H

#include <sstream>


using namespace std;
class Room {

public:
    /**
     * constructor
     */
    Room(){}
    /**
     * enum roomStatus
     */
    enum RoomStatus {WaittingToOtherPlayer, TwoPlayersConnected, Running, Stopped};
    /**
     * getRoomName function
     * @return string room name
     */
    const string &getRoomName() const;
    /**
     * setRoomName function.
     * @param roomName - string roomName
     */
    void setRoomName(const string &roomName);
    /**
     * getFirstClientSocket function.
     * @return clientSocket
     */
    int getFirstClientSocket() const;
    /**
     * setFirstClientSocket function.
     * @param firstClientSocket - client socket
     */
    void setFirstClientSocket(int firstClientSocket);
    /**
     * getSecondClientSocket function.
     * @return first client socket
     */
    int getSecondClientSocket() const;
    /**
     * setSecondClientSocket function.
     * @param secondClientSocket - second client socket
     */
    void setSecondClientSocket(int secondClientSocket);
    /**
     * getRoomStatus function.
     * @return room status (enum)
     */
    RoomStatus getRoomStatus() const;
    /**
     * setRoomStatus function.
     * @param roomStatus - room status enum param
     */
    void setRoomStatus(RoomStatus roomStatus);

private:
    //members
    string roomName;
    int firstClientSocket;
    int secondClientSocket;
    RoomStatus roomStatus;



};


#endif //REVERSITESTS_ROOM_H
