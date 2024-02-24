#include <iostream>
#include <vector>
using namespace std;

//dp[i][j]表示：容量为 i个0，j个1 的背包，最多装dp[i][j]个物品
//本题可以转换成：容量为 m个0，n个1 的背包，最多装多少个物品
//本题背包容量多了一个维度，因此滚动数组为二维数组
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //dp[i][j]表示：容量为 i个0，j个1 的背包，最多装dp[i][j]个物品
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(auto const &str : strs){ //每个str相当于物品，遍历每一个物品
            int zero = 0, one = 0;  //zero和one相当与物品的重量weight[i]
            //统计str中 0和1 的个数
            for(auto const &ch : str){
                if(ch == '0') ++zero;
                else ++one;
            }
            //遍历背包
            for(int i = m; i >= zero; --i){
                for(int j = n; j >= one; --j){
                    dp[i][j] = max(dp[i][j], dp[i - zero][j - one] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;
    Solution s;
    cout << s.findMaxForm(strs, m, n) << endl;
    return 0;
}