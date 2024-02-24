#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n <= 2) return n;
        vector<int> dp(n + 1, 0); //dp[i]表示1-i节点可组成的二叉搜索树的个数
        dp[0] = 1; //空树也是一棵二叉搜索树
        dp[1] = 1, dp[2] = 2;
        for(int i = 3; i <= n; ++i){
            for(int j = 1; j <= i; ++j){ //以 j 为头节点
                dp[i] += dp[j - 1] * dp[i - j]; //以 j 为头节点的二叉搜索树的 左子树有j-1个节点，右子树有i-j个节点
            }
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout << s.numTrees(3) << endl;
    return 0;
}