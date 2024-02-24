#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int> (obstacleGrid[0].size(), 0));
        /*
        dp[i][0]初始化为1，因为从(0, 0)到(i, 0)的路径只有一条（在没碰到障碍物的情况下，只能一直向下走）
        如果碰到了障碍物，那么后面的dp[i][0]都是0，因为碰到了障碍物，就不能再往下走了，后面的位置不可能到达
        */
        for(int i = 0; i < obstacleGrid.size() && obstacleGrid[i][0] == 0; ++i) dp[i][0] = 1; 
        /*
        dp[0][j]初始化为1，因为从(0, 0)到(0, j)的路径只有一条（在没碰到障碍物的情况下，只能一直向右走）
        如果碰到了障碍物，那么后面的dp[0][j]都是0，因为碰到了障碍物，就不能再往右走了，后面的位置不可能到达
        */
        for(int j = 0; j < obstacleGrid[0].size() && obstacleGrid[0][j] == 0; ++j) dp[0][j] = 1;
        for(int i = 1; i < obstacleGrid.size(); ++i){
            for(int j = 1; j < obstacleGrid[0].size(); ++j){
                if(obstacleGrid[i][j] == 0){ //如果(i, j)位置没有障碍物,才更新dp[i][j]，否则dp[i][j]保持为0
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}