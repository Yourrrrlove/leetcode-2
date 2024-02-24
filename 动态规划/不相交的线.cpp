#include <iostream>
#include <vector>
#include <string>
using namespace std;

//本题其实就是 求最长公共子序列的长度，不要求连续
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //dp[i][j]表示从nums1[0]开始到nums1[i-1]结尾的子序列和从nums2[0]开始到nums2[j-1]结尾的子序列，两者最长公共子序列长度为dp[i][j]
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0)); //这里已经把dp[0][j]和dp[i][0]初始化为0，为什么初始化为0？
        //dp[0][j]表示两个子序列之中，有一个子序列为空（因为没有nums[-1]这个元素），那最长公共子序列长度就是0，所以dp[0][j]和dp[i][0]应该初始化为0
        for(int i = 1; i <= nums1.size(); i++){
            for(int j = 1; j <= nums2.size(); j++){
                //这里应该比较nums1[i - 1]和nums2[j - 1]，而不是nums1[i]和nums2[j]，因为为了初始化方便我们让i, j从1开始，i-1, j-1才是从首元素开始比较
                if(nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1; //若nums1[i - 1] == nums2[j - 1]，则最长公共子序列长度+1
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //若nums1[i - 1] 不等于 nums2[j - 1]，则看nums1[0, i - 2]与nums2[0, j - 1]的最长公共子序列 和 nums1[0, i - 1]与nums2[0, j - 2]的最长公共子序列，取最大的
            }
        }
        return dp[nums1.size()][nums2.size()]; //nums1和nums2的最长公共子序列长度为dp[nums1.size()][nums2.size()]
    }
};