#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int searchInsert(vector<int> &nums, int target){
        int left = 0, right = nums.size() - 1, mid = left + (right - left) / 2;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
            else return mid;
        }
        //如果while循环结束，说明没有找到target，此时left指向的是第一个大于target的元素
        //以[1,3,5,6]为例，target=4，循环结束时left指向5，right指向3，此时应该把4插入到left的位置
        return left;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,3,5,6};
    int target = 4;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}