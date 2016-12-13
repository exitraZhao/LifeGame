//
//  World.cpp
//  LifeGame
//
//  Created by 赵一达 on 2016/12/14.
//  Copyright © 2016年 赵一达. All rights reserved.
//

#include "World.hpp"



void World::showGrid(){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
//            cout << grid[i][j];
            if( grid[i][j] == 1){
                cout << "O";
            }else{
                cout << " ";
            }
        }
        cout << "\n";
    }
}

int World::checkAround(int i, int j){
    int sum = 0;
    
    for (int a = i-1; a < i+2; a++){
        for (int b = j-1; b < j+2; b++){
            if (a >= 0 && b >= 0 && a < 40 && b < 40) {
                if ((a == i) && (b ==j)){
                }else {
                    if (grid[a][b] == 1) {
                        sum += 1;
                    }
                }
            }
        }
    }
    
    return sum;
}

void World::judgeGame(){
    
    int newGrid[40][40];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            newGrid[i][j] = grid[i][j];
        }
    }
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int checker = checkAround(i, j);
            
            if (checker == 3) {
                newGrid[i][j] = 1;
            } else if (checker == 2){
            } else {
                newGrid[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            grid[i][j] = newGrid[i][j];
        }
    }
}
