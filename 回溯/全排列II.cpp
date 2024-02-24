#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int> &nums, vector<bool> &used){
        if(path.size() == nums.size()){ //每个全排列的长度等于nums的长度
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            //去重
            //如果path中已经有了nums[i]，则跳过
            //同一树层相同元素：nums[i]和nums[i-1]相同，且used[i-1]==false(回溯重置为了false，说明此相同值在同一树层已使用过，不能再使用)
            if(used[i] == true || i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            path.push_back(nums[i]);
            used[i] = true;  //将nums[i]标记为已使用
            backtracking(nums, used);
            path.pop_back();  //回溯
            used[i] = false;  //回溯
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        result.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());  //排序，使重复元素相邻
        backtracking(nums, used);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,1,2,3,3};
    vector<vector<int>> ret = s.permuteUnique(nums);
    for(auto &vec : ret){
        for(auto &i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}