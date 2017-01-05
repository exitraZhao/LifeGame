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

int World::checkAroundLife(int i, int j){
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
    
    // new map.
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            gridNext[i][j] = grid[i][j];
        }
    }
    // copy from the original one.
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int checker = checkAroundLife(i, j);
            // count round
            if (checker == 3) {
                gridNext[i][j] = 1;
            } else if (checker == 2){
            } else {
                gridNext[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            grid[i][j] = gridNext[i][j];
        }
    }
    // replace the original one.
}

void World::iterateGame(int iterateNumber, int modelNum){
    showGrid();
    for (int i = 0; i < iterateNumber; i++) {
        
        if (modelNum == 1) {
            judgeGame();
        } else if (modelNum == 2){
            judgeGameDiv();
        } else if (modelNum == 3){
            judgeGameHistory();
        } else if (modelNum == 4){
            judgeGame();
            cout << "do you want to intervene the game? (1 for yes, 2 for no)\n";
            int z;
            cin >> z;
            if (z == 1) {
                cout << "choose a cell to give it born\n";
                int x,y;
                char m;
                cin >> x >> m >> y;
                giveBorn(x, y);
            }

        }
        cout << "\n";
        showGrid();
        
        cout << "///////////////////////";
    }
}
void World::judgeGameDiv(){
    // new map.
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            gridNext[i][j] = grid[i][j];
        }
    }
    // copy from the original one.
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int checker = checkAroundLife(i, j);
            // count round
            if (checker == 3) {
                gridNext[i][j] = 1;
            } else if (checker == 2){
                if (checkParent(i, j)) {
                    gridNext[i][j] = 1;
                }
            } else {
                gridNext[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            grid[i][j] = gridNext[i][j];
        }
    }
    // replace the original one.
    
}

bool World::checkParent(int i, int j){
    bool flag = false;
    int x[2];
    int y[2];
    
    int time = 0;
    
    for (int a = i-1; a < i+2; a++){
        for (int b = j-1; b < j+2; b++){
            if (a >= 0 && b >= 0 && a < 40 && b < 40) {
                if ((a == i) && (b ==j)){
                }else {
                    if (grid[a][b] == 1) {
                        x[time] = a;
                        y[time] = b;
                        time++;
                    }
                }
            }
        }
    }
    
    if (x[0] == x[1]){
        if (abs(y[0] - y[1]) == 1){
            flag = true;
        }
    }else if (y[0] == y[1]){
        if (abs(x[0] - x[1]) == 1){
            flag = true;
        }
    }
    
    return flag;
}

void World::judgeGameHistory(){
    // new map.
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            gridNext[i][j] = grid[i][j];
        }
    }
    // copy from the original one.
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int checker = checkAroundLife(i, j);
            // count round
            if (checker == 3) {
                gridNext[i][j] = 1;
                if (checkAroundLifePre(i, j) >= 3){
                    gridNext[i][j] = 0;
                }
            } else if (checker == 2){
                if (checkParent(i, j)) {
                    gridNext[i][j] = 1;
                }
            } else {
                gridNext[i][j] = 0;
            }
        }
    }
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            gridPre[i][j] = grid[i][j];
        }
    }
    // record the recent grid as history.
    
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            grid[i][j] = gridNext[i][j];
        }
    }
    // replace the original one.
}

int World::checkAroundLifePre(int i, int j){
    int sum = 0;
    
    for (int a = i-1; a < i+2; a++){
        for (int b = j-1; b < j+2; b++){
            if (a >= 0 && b >= 0 && a < 40 && b < 40) {
                if ((a == i) && (b ==j)){
                }else {
                    if (gridPre[a][b] == 1) {
                        sum += 1;
                    }
                }
            }
        }
    }
    
    return sum;
}

void World::giveBorn(int x, int y){
    if ((x >= 0 && x<+ 39) && (y >= 0 && y<+ 39)) {
        grid[x][y] = 1;
        cout << "set (" << x << "," << y << ") alive";
    }else {
        cout << "illegal.";
    }
}

