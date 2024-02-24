#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // 先升序排序，把负数放在前面
        //把最小的k个负数变成正数
        for(auto &num : nums){
            if(k <= 0 || num >= 0) break;
            --k;
            num = -num;
        }
        //如果经过for循环后k还有剩余，则nums中现在已经不存在负数了
        //如果k用完了  或者  k还有剩余且是偶数  则直接返回nums的和
        if(k <= 0 || k % 2 == 0) return accumulate(nums.begin(), nums.end(), 0);
        //如果k还有剩余且是奇数，则把nums中最小的数变成负数
        sort(nums.begin(), nums.end());
        nums[0] = -nums[0];
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

int main(){
    Solution s;
    vector<int> nums = {3,-1,0,2};
    cout << s.largestSumAfterKNegations(nums, 3) << endl;
    return 0;
}