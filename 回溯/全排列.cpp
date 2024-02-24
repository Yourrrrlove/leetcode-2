#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int> &nums){
        if(path.size() == nums.size()){ //每个全排列的长度等于nums的长度
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            //如果path中已经有了nums[i]，则跳过
            if(find(path.begin(), path.end(), nums[i]) != path.end()) continue;
            path.push_back(nums[i]);
            backtracking(nums);
            path.pop_back();  //回溯
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        result.clear();
        backtracking(nums);
        return result;
    }
};