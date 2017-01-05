//
//  World.hpp
//  LifeGame
//
//  Created by 赵一达 on 2016/12/14.
//  Copyright © 2016年 赵一达. All rights reserved.
//

#ifndef World_hpp
#define World_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class World {
private:
    int height = 40;
    int width = 40;
    int grid[40][40];
    int gridNext[40][40];
    int gridPre[40][40];
    int quota_balance = 2;
    int quota_life = 3;
    
    int aliveJudge = 1;
    int deadJudge = 0;
    
    int checkAroundLife(int,int);
    int checkAroundLifePre(int,int);
    bool checkParent(int,int);
    void judgeGame();
    void judgeGameDiv();
    void judgeGameHistory();
    void judgeGameIntervene();
    
    
public:
    World();
    World(int cell[40][40] ){
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                grid[i][j] = cell[i][j];
            }
        }
    };
   
    void showGrid();
    void iterateGame(int,int);
    void giveBorn(int,int);
   
    
};

class Cell {
private:
    int lifeJudge = 0;
    int aliveJudge = 1;
    int deadJudge = 0;
public:
    void setAlive();
    void setDead();
};
#endif /* World_hpp */
