//
// Created by liz on 19/11/1

#include <map>
#include "AIPlayer.h"
pair<int, int> AIPlayer::getInput(vector< pair<int,int> > options, const Board* board,
                                Board::Cell currentCellType, Board::Cell opponentCellType){
    /*for (int i = 0; i<options.size();i++) {
        cout << options[i].first+1<<options[i].second+1<<endl;
    }*/
    map<pair<int,int>,int> scoresPerOption;
    for(int i=0;i<options.size();i++) {
        Board copyBoard(*board);
        //set the current gameLogicBoard
        (*this).gameLogic->setBoard(&copyBoard);
       // cout<<"copy Boardbefore"<<options[i].first+1<<options[i].second+1<<endl;
       // this->gameLogic->getBoard()->print();
        (*this).gameLogic->makeMove(options[i].first,options[i].second,currentCellType,opponentCellType);
       // cout<<"copy BoardAfter"<<options[i].first+1<<options[i].second+1<<endl;
       // this->gameLogic->getBoard()->print();
        //get opponent optional moves, the params are inverse in purpuse
        vector< pair<int,int> > opponentOptionalScors = (*this).gameLogic->possibleMoves(opponentCellType,currentCellType);

        int max;
        if (opponentOptionalScors.size() != 0) {
            int once = 0;
            for (int j = 0; j < opponentOptionalScors.size(); j++) {
                Board temp(copyBoard);
                gameLogic->setBoard(&temp);
              //  cout << "before movment x" << endl;
                //gameLogic->getBoard()->print();

                gameLogic->makeMove(opponentOptionalScors[j].first, opponentOptionalScors[j].second,
                                    opponentCellType, currentCellType);
                //cout << "after movment x" << endl;
               // gameLogic->getBoard()->print();
                int optionalMax = gameLogic->getScores(opponentCellType, currentCellType);
                //update the maximum score
                if (once == 0) {
                    max = optionalMax;
                    once++;
                }

                if (optionalMax >= max) {
                    max = optionalMax;
                }

            }
        }else {
            max = gameLogic->getScores(opponentCellType, currentCellType);
        }
        scoresPerOption[options[i]] = max;

    }
    //find min score for opponent
    int min = scoresPerOption[options[0]];
    pair<int,int> chosenMove = options[0];
    for (int i=0;i<scoresPerOption.size(); i++) {
        if(scoresPerOption[options[i]]<min){
            min = scoresPerOption[options[i]];
            chosenMove = options[i];
        }
    }

    //(*board).print();
    //return the selected move
    return chosenMove;

}

AIPlayer::~AIPlayer() {
   // delete (*this).gameLogic;
}