#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


//set去重
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int> &nums, int startIndex){
        if(path.size() >= 2) result.push_back(path); //题目要求递增子序列的长度至少为2
        if(path.size() >= nums.size()) return;
        //用set去重，每次进入新的树层都重新建立一个set，因此for循环中不需要对set回溯
        unordered_set<int> used_set;
        for(int i = startIndex; i < nums.size(); ++i){
            //树层去重：set中出现过nums[i]就跳过
            //不满足递增：nums[i] < path.back()就跳过
            if(used_set.find(nums[i]) != used_set.end() || (!path.empty() && nums[i] < path.back())) continue;
            path.push_back(nums[i]);
            used_set.insert(nums[i]); //本层用过的元素加入set
            backtracking(nums, i + 1);
            path.pop_back(); //回溯
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        result.clear();
        backtracking(nums, 0);
        return result;
    }
};

//用used数组去重
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int> &nums, int startIndex){
        if(path.size() >= 2) result.push_back(path); //题目要求递增子序列的长度至少为2
        if(path.size() >= nums.size()) return;
        //用used数组去重，每次进入新的树层都重新建立一个数组，因此for循环中不需要对数组回溯
        //used数组不能设为全局变量，以[4,7,6,7]为例：
        //第一个7设为用过，后面递归遇到第二个7时，由于7已经被标记为用过，所以第二个7会被跳过，这样就无法得到[4,7,7]
        int used[201] = {0}; //题目中说了-100 <= nums[i] <= 100,所以开一个201大小的数组
        for(int i = startIndex; i < nums.size(); ++i){
            //树层去重：和nums[i]相等的值出现过就跳过
            //不满足递增：nums[i] < path.back()就跳过
            if(used[nums[i] + 100] == 1 || (!path.empty() && nums[i] < path.back())) continue;
            path.push_back(nums[i]);
            used[nums[i] + 100] = 1; //标记nums[i]已经使用过
            backtracking(nums, i + 1);
            path.pop_back(); //回溯
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        result.clear();
        backtracking(nums, 0);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums{4,7,6,7};
    auto ret = s.findSubsequences(nums);
    for(auto const &vec : ret){
        for(auto const &num : vec) cout << num << " ";
        cout << endl; 
    }
    return 0;
}