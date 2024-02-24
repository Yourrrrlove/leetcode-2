#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//x-1, y+0表示向上搜索
//x+1, y+0表示向下搜索
//x+0, y-1表示向左搜索
//x+0, y+1表示向右搜索
class Solution {
private:
    int dire[2][4] = {{-1,1,0,0},{0,0,-1,1}};
    int area = 0; //岛屿的面积
    //bfs负责将grid[x][y]所在的岛屿的全部陆地位置全部置为'0'
    void bfs(vector<vector<int>> &grid, int x, int y){
        int row = grid.size(), col = grid[0].size(); //获取grid的行数和列数
        queue<pair<int, int>> myque;
        myque.push({x, y});
        //已经访问过该陆地，不能重复访问，需要将当前位置置为'0'
        grid[x][y] = 0;
        while(!myque.empty()){
            auto cur = myque.front();
            myque.pop();
            for(int i = 0; i < 4; ++i){ //遍历当前位置的上下左右四个方向
                int next_x = cur.first + dire[0][i], next_y = cur.second + dire[1][i];
                //若下一个位置超出边界或者下一个位置是水域，则跳过
                if(next_x <0 || next_x >= row || next_y < 0 || next_y >= col || grid[next_x][next_y] == 0) continue;
                //bfs只将当前陆地位置的上下左右四个方向的陆地全部入队
                myque.push({next_x, next_y});
                ++area; //发现周围的一个新大陆，岛屿的面积+1
                grid[next_x][next_y] = 0; //将四周的陆地入队代表已访问grid[next_x][next_y]，要将grid[next_x][next_y]置为'0'
            }
        }
    }

    void dfs(vector<vector<int>> &grid, int x, int y){
        int row = grid.size(), col = grid[0].size(); //获取grid的行数和列数
        grid[x][y] = 0; //只有满足if(grid[i][j] == '1')条件时（即grid[x][y]是陆地时）才调用dfs函数，所以已经访问过该陆地，不能重复访问，需要将当前陆地置为'0'
        ++area; //发现周围的一个新大陆，岛屿的面积+1
        for(int i = 0; i < 4; ++i){ //遍历当前位置的上下左右四个方向
            int next_x = x + dire[0][i], next_y = y + dire[1][i];
            //若下一个位置超出边界或者下一个位置是水域，则跳过
            if(next_x <0 || next_x >= row || next_y < 0 || next_y >= col || grid[next_x][next_y] == 0) continue;
            //否则，继续深搜
            dfs(grid, next_x, next_y);
        }
    }
    void printGrid(vector<vector<int>> &grid){
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int row = grid.size();
        if(row == 0) return 0; //若grid为空，则岛屿数量为0
        int col = grid[0].size();
        int result = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 1){ //若当前位置是陆地
                    //bfs标记已访问的过程在while循环中 所以要单独处理第一个陆地，所以area初始化为1
                    // area = 1; //岛屿初始面积 = 当前陆地位置的面积 = 1
                    // bfs(grid, i, j); //调用bfs将此陆地(grid[i][j])所在的岛屿全部置为'0'
                    
                    //dfs标记已访问的过程在dfs函数中，所以不需要单独处理第一个陆地，所以area初始化为0
                    area = 0;
                    dfs(grid, i, j);
                    //printGrid(grid);
                    result = max(result, area); //更新最大岛屿面积
                }
            }
        }
        return result;
    }
};

int main(){
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };
    Solution s;
    cout << s.maxAreaOfIsland(grid) << endl;
    return 0;
}