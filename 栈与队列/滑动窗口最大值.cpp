#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

//暴力解法
//时间复杂度：O(n*k)
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> result;
//         for(int i = 0; i < nums.size() - k + 1; ++i){
//             int maxValue = INT_MIN;
//             for(int j = i; j < i + k; ++j){
//                 maxValue = nums[j] > maxValue ? nums[j] : maxValue;
//             }
//             result.push_back(maxValue);
//         }
//         return result;
//     }
// };

//双端队列deque
//时间复杂度：O(n)
class Solution {
private:
    //自定义的单调队列，用于维护滑动窗口最大值
    class MyQueue{
    public:
        deque<int> que;
        /*
        pop函数中的这个判断val == que.front()是为了确保我们只移除滑动窗口移出的元素。
        在这个问题中，val是滑动窗口即将移出的元素，que.front()是当前队列中的最大元素。
        当它们相等时，意味着滑动窗口的最大元素即将被移出，由于队列只维护可能成为窗口中最大值的元素，因此我们需要在队列中也移除它。
        如果它们不相等，那么滑动窗口移出的元素不是当前的最大元素，我们就不需要在队列中进行操作，此时pop为空操作。
        */
        void pop(int val){
            //队列非空且当前遍历到的元素==队头元素才将队头元素出队
            if(!que.empty() && val == que.front()) que.pop_front();
        }
        void push(int val){
            //单调队列只维护有可能成为最大值的元素，因此当队尾元素<遍历到的元素时，先将小于当前遍历到的元素的全部队尾元素出队
            while(!que.empty() && val > que.back()) que.pop_back();
            que.push_back(val); //当单调队列中只剩下比当前遍历到的元素大的值时，将当前遍历到的元素入队
        }

        int front(){
            return que.front();//由于是单调递减（非严格，元素可以相等）队列，所以队头元素就是当前滑动窗口的最大值
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQueue que;
        for(int i = 0; i < k; ++i) que.push(nums[i]); //先维护第一个滑动窗口
        result.push_back(que.front()); //将第一个滑动窗口的最大值添加到result中
        for(int i = k; i < nums.size(); ++i){
            que.pop(nums[i - k]);  //i - k 指向当前滑动窗口的首元素，当滑动窗口向后移时，应将当前滑动窗口的首元素出队
            que.push(nums[i]);  //将下一个滑动窗口的末尾元素入队
            //例如，nums = [1,3,-1,-3,5,3,6,7], k = 3，当滑动窗口从[1,3,-1]后移到[3,-1,-3]时，应该将1出队，将-3入队
            result.push_back(que.front()); //将单调队列的队头元素（即当前滑动窗口的最大元素）添加到result中
        }
        return result;
    }
};

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    Solution s;
    vector<int> result = s.maxSlidingWindow(nums, 3);
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}