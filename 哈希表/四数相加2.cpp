#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hashtable;
        //hashtable的key是nums1[i] + nums2[j]，value是nums1[i] + nums2[j]出现的次数
        for(const auto &num1 : nums1){
            for(const auto &num2 : nums2){
                ++hashtable[num1 + num2];
            }
        }
        int ret = 0;  //ret记录满足nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0的{i,j,k,l}组合的个数
        //遍历nums3和nums4数组，如果 0-(num3 + num4) 在hashtable中出现过，则ret += 0 - (num3 + num4) 出现的次数（即hashtable[0 - (num3 + num4)]）
        for(const auto &num3 : nums3){
            for(const auto &num4 : nums4){
                if(hashtable.find(0 - num3 - num4) != hashtable.end()) ret += hashtable[0 - num3 - num4];
            }
        }
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> nums1 {1,2};
    vector<int> nums2 {-2,-1};
    vector<int> nums3 {-1,2};
    vector<int> nums4 {0,2};
    cout << s.fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}