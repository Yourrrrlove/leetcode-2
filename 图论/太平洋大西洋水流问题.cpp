#include <iostream>
#include <vector>
using namespace std;

/*
1. 从太平洋边上的节点逆流而上（从最上面一行和最左边一列向内dfs，寻找可以流向太平洋的位置），将遍历过的节点都标记上；
2. 从大西洋边上的节点逆流而上（从最下面一行和最右边一列向内dfs，寻找可以流向大西洋的位置），将遍历过的节点也标记上；
3. 两方都标记过的节点就是既可以流向太平洋也可以流向大西洋的位置
4. 水只能从高处流向低处，所以 dfs 时，只有满足`if(heights[next_x][next_y] ≥ heights[x][y])`条件时，才继续 dfs
*/
class Solution{
private:
    int dire[2][4] = {{-1,1,0,0},{0,0,-1,1}};
    //dfs负责将可以流向海洋的位置标记上
    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &visited, int x, int y){
        if(visited[x][y] == true) return; //防止重复访问
        visited[x][y] = true;
        int row = heights.size(), col = heights[0].size();
        for(int i = 0; i < 4; ++i){
            int next_x = x + dire[0][i], next_y = y + dire[1][i];
            //若下一个位置越界或者下一个位置的高度小于当前位置的高度，则不继续dfs
            if(next_x < 0 || next_x >= row || next_y < 0 || next_y >= col || heights[next_x][next_y] < heights[x][y]) continue;
            dfs(heights, visited, next_x, next_y);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        if(row == 0) return {};
        int col = heights[0].size();
        vector<vector<int>> result;
        //Pvisited[i][j] == true表示heights[i][j]可以流向太平洋
        vector<vector<bool>> Pvisited(row, vector<bool>(col, false)); //标记heights的某位置是否可以流向太平洋
        //Avisited[i][j] == true表示heights[i][j]可以流向大西洋
        vector<vector<bool>> Avisited(row, vector<bool>(col, false)); //标记heights的某位置是否可以流向大西洋
        //从太平洋边上（最左边和最上边）的节点逆流而上
        for(int i = 0; i < row; ++i){ //最左边一列
            dfs(heights, Pvisited, i, 0);
        }
        for(int j = 0; j < col; ++j){ //最上边一行
            dfs(heights, Pvisited, 0, j);
        }
        //从大西洋边上（最右边和最下边）的节点逆流而上
        for(int i = 0; i < row; ++i){ //最右边一列
            dfs(heights, Avisited, i, col - 1);
        }
        for(int j = 0; j < col; ++j){ //最下边一行
            dfs(heights, Avisited, row - 1, j);
        }
        //遍历一遍heights，找出既可以流向太平洋也可以流向大西洋的位置
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                //Pvisited[i][j]和Avisited[i][j]都为true的位置就是既可以流向太平洋也可以流向大西洋的位置
                if(Pvisited[i][j] == true && Avisited[i][j] == true) result.push_back({i, j});
            }
        }
        return result;
    }
};

int main(){
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    Solution s;
    vector<vector<int>> res = s.pacificAtlantic(heights);
    for(int i = 0; i < res.size(); ++i){
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}