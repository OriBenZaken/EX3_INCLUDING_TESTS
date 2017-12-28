/**
 * RoomsCollection class
 * holds room collection.
 */
#ifndef REVERSITESTS_ROOMSCOLLECTION_H
#define REVERSITESTS_ROOMSCOLLECTION_H


#include <vector>
#include "Room.h"

class RoomsCollection {

public:
    /**
     * getRooms function.
     * @return vector of rooms.
     */
    vector<Room> &getRooms();
    /**
     * setRooms function.
     * @param rooms - vector of rooms.
     */
    void setRooms(const vector<Room> &rooms);
    /**
     * getCount_mutex function.
     * @return pthread_mutex_t of the rooms
     */
    pthread_mutex_t &getCount_mutex();
    /**
     * setCount_mutex function.
     * @param count_mutex - pthread_mutex_t
     */
    void setCount_mutex(const pthread_mutex_t &count_mutex);

private:
    //members
    pthread_mutex_t count_mutex;
    vector<Room> rooms;


};


#endif //REVERSITESTS_ROOMSCOLLECTION_H
