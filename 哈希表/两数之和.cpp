#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        // 暴力解法
        // for(int i = 0; i < nums.size(); ++i){
        //     for(int j = i + 1; j < nums.size(); ++j){
        //         if(nums[i] == target - nums[j]) return {i, j};
        //     }
        // }
        // return {};
        //hash
        //数组中同一个元素在答案里不能重复出现，因此：
        //用unordered_map的话，不能先遍历nums数组来初始化hashtable（即不能先：for(auto i : nums) hashtable[nums[i]] = i）,否则会重复使用nums数组中的元素
        unordered_map<int, int> hashtable;// key:nums[i], value:i（key是值，value是索引）
        for(int i = 0; i < nums.size(); ++i){
            //本方法是一边查找一边往hashtable添加元素，如果先遍历一遍nums数组，再遍历一遍hashtable，就会出现重复使用nums数组中的元素
            if(hashtable.find(target - nums[i]) != hashtable.end()) return {i, hashtable[target - nums[i]]}; //如果hashtable中存在要匹配的target - nums[i]，则返回结果
            else hashtable[nums[i]] = i; //如果不存在，则把访问过的元素和下标{nums[i], i}添加到hashtable中
        }
        return {};
    }
};
int main(){
    Solution s;
    vector<int> nums {3,3,2};
    vector<int> ret = s.twoSum(nums, 6);
    for(const auto &index : ret) cout << index << endl;
    return 0;
}