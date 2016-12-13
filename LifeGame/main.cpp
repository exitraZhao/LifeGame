//
//  main.cpp
//  LifeGame
//
//  Created by 赵一达 on 2016/12/13.
//  Copyright © 2016年 赵一达. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <curses.h>
#include "World.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int iterateNumber = 50;
    int cell[40][40] = {0};
    
    for (int i = 0; i < 40; i++) {
        cell[10][i] = 1;
    }
    for (int i = 0; i < 40; i++) {
        cell[30][i] = 1;
    }
    World world = *new World(cell);
    world.showGrid();
    
    
    for (int i = 0; i < iterateNumber; i++) {
        world.judgeGame();
        cout << "\n";
        world.showGrid();
        
    }
    
    
    return 0;

}
