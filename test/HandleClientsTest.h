//
// Created by liz on 28/12/17.
//

#ifndef REVERSITESTS_HANDLECLIENTS_H
#define REVERSITESTS_HANDLECLIENTS_H


using namespace std;

#include <gmock/gmock-matchers.h>
class HandleClientsTest : public testing::Test{
public:
    bool isValidSwap(int client1, int client2);
    bool isValidSplit(vector<string> splitted);

};


#endif //REVERSITESTS_HANDLECLIENTS_H
