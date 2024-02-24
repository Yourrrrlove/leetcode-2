#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0)); //dp[i][j]表示从(0,0)到(i,j)有多少条路径
        for(int i = 0; i < m; ++i) dp[i][0] = 1; //d[i][0]初始化为1，因为从(0, 0)到(i, 0)的路径只有一条（只能一直向下走）
        for(int j = 0; j < n; ++j) dp[0][j] = 1; //dp[0][j]初始化为1，因为从(0, 0)到(0, j)的路径只有一条（只能一直向右走）
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                //从(0, 0)到(i, j)可以从(i-1, j)向下走一步到达，也可以从(i, j-1)向右走一步到达
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1]; //返回从(0, 0)到(m-1, n-1)的路径数
    }
};

int main(){
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
    return 0;
}