#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int result = 0;
        int dire[2][4] = {{-1,1,0,0},{0,0,-1,1}};
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 1){ //遍历grid，碰到陆地就遍历其上下左右四个方向，四个方向中有海洋或者越界，就说明此方向是该陆地的一个边
                    for(int k = 0; k < 4; ++k){
                        int next_x = i + dire[0][k], next_y = j + dire[1][k];
                        if(next_x < 0 || next_x >= row || next_y < 0 || next_y >= col || grid[next_x][next_y] == 0) ++result;
                    }
                }
            }
        }
        return result;
    }
};