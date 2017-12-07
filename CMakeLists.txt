cmake_minimum_required(VERSION 3.6)
project(ReversiTests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES src/Board.h src/Board.h src/GameLogic.cpp src/GameLogic.h src/StandartGameLogic.cpp src/StandartGameLogic.cpp
        src/StandartGameLogic.h src/TwoPlayersOneComputerGame.cpp src/TwoPlayersOneComputerGame.h src/HumanPlayer.h src/HumanPlayer.cpp
        src/Board.cpp src/IGame.cpp src/IGame.h src/Player.h src/Player.cpp src/AIPlayer.cpp src/AIPlayer.h
        src/client/Client.cpp src/client/Client.h src/RemotePlayer.cpp src/RemotePlayer.h src/RemoteGame.cpp src/RemoteGame.h
        src/server/Server.h src/server/Server.cpp)

set(TEST_FILES test/StandardGameLogicTest.cpp test/StandardGameLogicTest.h test/BoardsMatch.h
        test/AIPlayerTest.cpp test/AIPlayerTest.h)

add_executable(ReversiTests ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
add_executable(ReversiClient ${SOURCE_FILES} src/client/client_main.cpp)
add_executable(ReversiServer ${SOURCE_FILES} src/server/server_main.cpp)
target_link_libraries(ReversiTests gtest gtest_main pthread)
add_test(ReversiTests ReversiTests)