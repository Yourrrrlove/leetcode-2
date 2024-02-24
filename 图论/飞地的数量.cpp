#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
    int count = 0;
    int dire[2][4] = {{-1,1,0,0}, {0,0,-1,1}};
    //dfs负责将grid[x][y]所在的岛屿的全部陆地位置全部置为0
    void dfs(vector<vector<int>>& grid, int x, int y){
        int row = grid.size(), col = grid[0].size();
        grid[x][y] = 0;
        ++count;
        for(int i = 0; i < 4; ++i){
            int next_x = x + dire[0][i], next_y = y + dire[1][i];
            if(next_x < 0 || next_x >= row || next_y < 0 || next_y >= col || grid[next_x][next_y] == 0) continue;
            dfs(grid, next_x, next_y);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid){
        int row = grid.size(), col = grid[0].size();
        /*
        把最上下左右四条边上的陆地所在的岛屿全部置为0
        grid最后剩下的陆地就是飞地
        */
        for(int i = 0; i < row; ++i){ //最左边一列
            if(grid[i][0] == 1) dfs(grid, i, 0);
        }
        for(int i = 0; i < row; ++i){ //最右边一列
            if(grid[i][col - 1] == 1) dfs(grid, i, col - 1);
        }
        for(int j = 0; j < col; ++j){ //最上边一行
            if(grid[0][j] == 1) dfs(grid, 0, j);
        }
        for(int j = 0; j < col; ++j){ //最下边一行
            if(grid[row - 1][j] == 1) dfs(grid, row - 1, j);
        }
        //统计grid中剩下的陆地(即飞地)的数量
        count = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 1) ++count;
            }
        }
        return count;
    }
};

int main(){
    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    Solution s;
    cout << s.numEnclaves(grid) << endl;
    return 0;
}

