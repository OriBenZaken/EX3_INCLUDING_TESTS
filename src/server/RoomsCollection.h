//
// Created by liz on 28/12/17.
//

#ifndef REVERSITESTS_ROOMSCOLLECTION_H
#define REVERSITESTS_ROOMSCOLLECTION_H


#include <vector>
#include "Room.h"

class RoomsCollection {

public:
    vector<Room> &getRooms();

    void setRooms(const vector<Room> &rooms);

    pthread_mutex_t &getCount_mutex();

    void setCount_mutex(const pthread_mutex_t &count_mutex);

private:
    pthread_mutex_t count_mutex;
    vector<Room> rooms;


};


#endif //REVERSITESTS_ROOMSCOLLECTION_H
