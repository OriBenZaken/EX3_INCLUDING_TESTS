/**
 * HandleClientsTest class.
 * include tests of split ans swap functions.
 */

#ifndef REVERSITESTS_HANDLECLIENTS_H
#define REVERSITESTS_HANDLECLIENTS_H


using namespace std;

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "../src/server/HandleClients.h"
class HandleClientsTest : public testing::Test{
public:
    /**
     * isValidSwap function.
     * @param client1 - client socket 1
     * @param client2 - client socket 2
     * @return true if valid, false otherwise
     */
    bool isValidSwap(int client1, int client2);
    /**
     * isValidSplit function.
     * @param splitted - vector of strings
     * @return true if valid, false otherwise
     */
    bool isValidSplit(vector<string> splitted);

};


#endif //REVERSITESTS_HANDLECLIENTS_H
