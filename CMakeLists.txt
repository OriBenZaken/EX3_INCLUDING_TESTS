cmake_minimum_required(VERSION 3.6)
project(ReversiTests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES src/client/Board.h src/client/Board.h src/client/GameLogic.cpp src/client/GameLogic.h src/client/StandartGameLogic.cpp src/client/StandartGameLogic.cpp
        src/client/StandartGameLogic.h src/client/TwoPlayersOneComputerGame.cpp src/client/TwoPlayersOneComputerGame.h src/client/HumanPlayer.h src/client/HumanPlayer.cpp
        src/client/Board.cpp src/client/IGame.cpp src/client/IGame.h src/client/Player.h src/client/Player.cpp src/client/AIPlayer.cpp src/client/AIPlayer.h
        src/client/Client.cpp src/client/Client.h src/client/RemotePlayer.cpp src/client/RemotePlayer.h src/client/RemoteGame.cpp src/client/RemoteGame.h
        src/server/Server.h src/server/Server.cpp)

set(TEST_FILES test/StandardGameLogicTest.cpp test/StandardGameLogicTest.h test/BoardsMatch.h
        test/AIPlayerTest.cpp test/AIPlayerTest.h)

add_executable(ReversiTests ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
add_executable(ReversiClient ${SOURCE_FILES} src/client/client_main.cpp)
add_executable(ReversiServer ${SOURCE_FILES} src/server/server_main.cpp)
target_link_libraries(ReversiTests gtest gtest_main pthread)
add_test(ReversiTests ReversiTests)