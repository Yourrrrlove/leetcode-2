#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1); // 没找到的话为-1，找到了更新
        unordered_map<int, int> umap;
        //找每个温度右边第一个温度大于该温度的温度，应该用单调递增栈
        stack<int> st; //递增栈（从栈顶到栈底的温度值严格递增），存放温度的下标
        // 为nums1中每个元素及其下标建立映射
        for(int i = 0; i < nums1.size(); ++i) umap[nums1[i]] = i;
        st.push(0);
        for(int i = 1; i < nums2.size(); ++i){
            while(!st.empty() && nums2[i] > nums2[st.top()]){
                if(umap.count(nums2[st.top()]) > 0){ // 在nums2中找到了nums1中的元素（nums1和nums2中都有此元素，值为nums2[st.top()]）
                    //umap[nums2[st.top()]]是此公共元素在nums1中的下标，nums2[i]是此公共元素的下一个更大元素
                    result[umap[nums2[st.top()]]] = nums2[i];
                }
                st.pop();
            }
            // 如果当前温度<=栈顶温度 或 栈空了，直接入栈
            st.push(i);
        }
        return result;
    }
};

int main(){
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    Solution s;
    vector<int> result = s.nextGreaterElement(nums1, nums2);
    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}