#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int> &nums, int startIndex){
        result.push_back(path); //放在for循环之前，把空集在内的所有长度的子集都放进result
        if(path.size() >= nums.size()) return;
        for(int i = startIndex; i < nums.size(); ++i){
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back(); //回溯
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        result.clear();
        backtracking(nums, 0);
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ret = s.subsets(nums);
    for(auto const &vec : ret){
        for(auto const& num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}