#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
    int getRightBorder(vector<int> &nums, int target){
        int left = 0, right = nums.size() - 1, mid = left + (right - left) / 2, rightBorder = -2; //rightBorder初始化为-1,-2,-3,......都可以
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] > target) right = mid - 1;
            else{
                left = mid + 1;
                //最后跳出while循环时，left>right，此时left指向的就是最后一个target右边第一位的元素
                rightBorder = left;
            }
        }
        //如果rightBorder一直没变，说明target比数组最小元素还要小：例如[4，5，6],target = 2
        return rightBorder;
    }
    int getLeftBorder(vector<int> &nums, int target){
        int left = 0, right = nums.size() - 1, mid = left + (right - left) / 2, leftBorder = -2;  //leftBorder初始化为-1,-2,-3,......都可以
        while(left <= right){
            mid = left + (right - left) / 2;
            if(target > nums[mid]) left = mid + 1;
            else{
                right = mid - 1;
                //最后跳出while循环时，left>right，此时right指向的就是第一个target左边第一位的元素
                leftBorder = right;
            }
        }
        //如果leftBorder一直没变，说明target比数组最大元素还要大：例如[1,2,3],target = 4
        return leftBorder;
    }
public:
    vector<int> searchRange(vector<int> &nums, int target){
        int left_border = getLeftBorder(nums, target);
        int right_border = getRightBorder(nums, target);
        if(left_border == -2 || right_border == -2) return {-1, -1}; //target 在数组范围的右边或者左边，例如数组{3, 4, 5}，target为2或者数组{3, 4, 5},target为6，此时应该返回{-1, -1}
        if(right_border - left_border > 1) return {left_border + 1, right_border - 1}; //target 在数组范围中，且数组中存在target，例如数组{3,6,7},target为6,或{3,6,6,7}, target=6
        return {-1, -1}; //target 在数组范围中，且数组中不存在target，例如数组{3,6,7},target为5，此时应该返回{-1, -1}
    }
};

int main(){
    Solution s;
    vector<int> nums{5,7,7,8,10};
    vector<int> result = s.searchRange(nums,8);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}