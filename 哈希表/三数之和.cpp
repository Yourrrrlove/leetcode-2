#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//双指针法
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  //先将nums数组从小到大排序
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0) return result;  //
            if(i > 0 && nums[i] == nums[i - 1]) continue; //对a进行去重
            //双指针
            int left = i + 1, right = nums.size() - 1; //left指向i的下一个元素，right指向最后一个元素
            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0) --right;  //由于数组已经升序排序了，因此如果当前a+b+c>0，说明c太大，right左移
                else if(nums[i] + nums[left] + nums[right] < 0) ++left;  //同理，如果a+b+c<0，说明b太小，left右移
                else{  //a+b+c=0
                    result.push_back({nums[i], nums[left], nums[right]});  //如果a+b+c=0，说明找到了一组解，将其存入result中
                    while(left < right && nums[right] == nums[right - 1]) --right; //对b进行去重
                    while(left < right && nums[left] == nums[left + 1]) ++left;  //对c进行去重
                    //找到一组解之后，left和right都需要移动一位
                    --right;
                    ++left;
                }
            }
        }
        return result;
    }
};

//还可以用回溯