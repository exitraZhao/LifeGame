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
    int quota_balance = 2;
    int quota_life = 3;
    
public:
    World();
    World(int cell[40][40] ){
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                grid[i][j] = cell[i][j];
            }
        }
    };
    void judgeGame();
    void showGrid();
    int checkAround(int,int);
    
};

#endif /* World_hpp */
