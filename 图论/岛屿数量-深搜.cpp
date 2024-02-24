#include <iostream>
#include <vector>
using namespace std;


//x-1, y+0表示向上搜索
//x+1, y+0表示向下搜索
//x+0, y-1表示向左搜索
//x+0, y+1表示向右搜索
class Solution {
private:
    int dire[2][4] = {{-1,1,0,0},{0,0,-1,1}};
    //dfs负责将grid[x][y]所在的岛屿的全部陆地位置全部置为'0'
    void dfs(vector<vector<char>> &grid, int x, int y){
        int row = grid.size(), col = grid[0].size(); //获取grid的行数和列数
        grid[x][y] = '0'; //只有满足if(grid[i][j] == '1')条件时（即grid[x][y]是陆地时）才调用dfs函数，所以已经访问过该陆地，不能重复访问，需要将当前陆地置为'0'
        for(int i = 0; i < 4; ++i){ //遍历当前位置的上下左右四个方向
            int next_x = x + dire[0][i], next_y = y + dire[1][i];
            //若下一个位置超出边界或者下一个位置是水域，则跳过
            if(next_x <0 || next_x >= row || next_y < 0 || next_y >= col || grid[next_x][next_y] == '0') continue;
            //否则，继续深搜
            dfs(grid, next_x, next_y);
        }
    }
    void printGrid(vector<vector<char>> &grid){
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
public:
    int numIslands(vector<vector<char>>& grid){
        int row = grid.size();
        if(row == 0) return 0; //若grid为空，则岛屿数量为0
        int col = grid[0].size();
        int count = 0; //岛屿数量
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == '1'){ //若当前位置是陆地
                    count++; //岛屿数量+1
                    dfs(grid, i, j); //调用dfs将此陆地(grid[i][j])所在的岛屿全部置为'0'
                    printGrid(grid);
                }
            }
        }
        return count;
    }
};

int main(){
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    Solution s;
    cout << s.numIslands(grid) << endl;
    return 0;
}
/*
输出：
grid的变化过程：
0 0 0 0 0 
0 0 0 0 0 
0 0 1 0 0 
0 0 0 1 1 

0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 1 1 

0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 

*/