#include <iostream>
#include <vector>
using namespace std;

//子数组就是 连续子序列
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 || nums2.size() == 0) return 0;
        //dp[i][j]表示nums1[i-1]为结尾的数组和以nums2[j-1]为结尾的数组 的最长重复子数组的长度为dp[i][j]
        vector<vector<int>> dp(nums1.size() + 1, vector<int> (nums2.size() + 1, 0));
        int result = 0;
        for(int i = 1; i <= nums1.size(); ++i){
            for(int j = 1; j <= nums2.size(); ++j){
                //又找到一个重复的元素，所以dp[i][j] = 1 + 此重复元素之前的最长重复子数组的长度dp[i - 1][j - 1]
                //这里应该比较nums1[i - 1]和nums2[j - 1]，而不是nums1[i]和nums2[j]，因为为了初始化方便我们让i, j从1开始，i-1, j-1才是从首元素开始比较
                if(nums1[i - 1] == nums2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1; 
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};