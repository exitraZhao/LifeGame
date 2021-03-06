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
    
    int iterateNumber = 50;
    int cell[40][40] = {0};
    
    for (int i = 0; i < 40; i++) {
        cell[10][i] = 1;
    }
    for (int i = 0; i < 40; i++) {
        cell[30][i] = 1;
    }
    
    
    cout << "please select the model:" << "\n" << " 1 for Normal." << "\n" << " 2 for Division." << "\n" <<" 3 for GrandFather " << "\n" << " 4 for intervne " << "\n" << " 0 for Exit." << "\n";
    int choosenNum = 1 ;
    cin >> choosenNum ;
    while (choosenNum != 0) {
//        int x = 0,y = 0;
//        char m;
//        cout << "input the cell \n ";
//        while (x != -1 && y != -1) {
//            cin >> x >> m >> y;
//        }
        World world = *new World(cell);
        world.iterateGame(iterateNumber,choosenNum);
        cout << "\n" << "please select the model:" << "\n" << " 1 for Normal." << "\n" << " 2 for Division." << "\n"<< " 3 for GrandFather " << "\n"<<" 4 for intervene " << "\n" <<  " 0 for Exit." << "\n";
        cin >> choosenNum ;
       
    }
    
    return 0;

}
