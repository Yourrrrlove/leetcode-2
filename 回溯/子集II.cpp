#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int> &nums, vector<bool> &used, int startIndex){
        result.push_back(path); //放在for循环之前，把空集在内的所有长度的子集都放进result
        if(path.size() >= nums.size()) return;
        for(int i = startIndex; i < nums.size(); ++i){
            //树层去重
            //used[i-1]是通过回溯重设为false的，说明nums[i-1]已经使用过了，不能再使用了
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used, i + 1);
            //回溯
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        path.clear();
        result.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());  //必须先排序，让重复的元素相邻
        backtracking(nums, used, 0);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 2, 1};
    vector<vector<int>> ret = s.subsetsWithDup(nums);
    for(auto const &vec : ret){
        for(auto const& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}