#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//双指针法
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  //先将nums数组从小到大排序
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > target &&nums[i] > 0) break;  //如果nums[i](>0)已经大于target，那么后面的数都会大于target，直接退出循环
            if(i > 0 && nums[i] == nums[i - 1]) continue;  //对a去重
            for(int j = i + 1; j < nums.size(); ++j){
                if(nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) break;  //同理，如果nums[i] + nums[j](>0)已经大于target，那么后面的数都会大于target
                //上面那句可以剪枝优化为：if(nums[i] + nums[j] > target && nums[i] >= 0)，因为j>i，即nums[j]是nums[i]后面的元素，所以如果nums[i]>=0，那么nums[i] + nums[j]一定 >= 0
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;  //对b去重
                //双指针，此时a+b为确定值，问题转化为三数之和
                int left = j + 1, right = nums.size() - 1;  //left指向j的下一个元素，right指向最后一个元素
                while(left < right){
                    if((long) nums[i] + nums[j] + nums[left] + nums[right] > target) --right; //由于数组已经升序排序了，因此如果当前a+b+c+d>target，说明d太大，right左移
                    else if((long) nums[i] + nums[j] + nums[left] + nums[right] < target) ++left; //同理，如果a+b+c+d<target，说明c太小，left右移
                    else{ //a+b+c+d=target
                        result.push_back({nums[i], nums[j], nums[left], nums[right]}); //如果a+b+c+d=target，说明找到了一组解，将其存入result中
                        while(left < right && nums[right] == nums[right - 1]) --right;  //对c去重
                        while(left < right && nums[left] == nums[left + 1]) ++left;  //对d去重
                        //找到一组解之后，left和right都需要移动一位
                        ++left;
                        --right; 
                    }
                }
            }
        }
        return result;
    }
};