//
//  Map.h
//  LifeGame
//
//  Created by 赵一达 on 2016/12/14.
//  Copyright © 2016年 赵一达. All rights reserved.
//


#ifndef Map_h
#define Map_h



class World {
private:
    int height = 40;
    int width = 40;
    int grid[40][40] = {};
    
public:
    World();
    World(int[]);
    void judgeGame();
    void showGrid();
    
};

#endif /* Map_h */
