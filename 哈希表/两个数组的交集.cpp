#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count; // 记录nums2中每个元素出现的次数
        vector<int> result;  // 记录交集元素
        for(const auto &num : nums2) ++count[num]; // 统计nums2中每个元素出现的次数
        for(const auto &num : nums1){
            if(count.find(num) != count.end() && count[num] > 0){  // 如果nums1中的元素在nums2中出现过,且出现次数大于0.判断count[num]>0是为了防止往result重复添加元素：
            // 比如nums1 = [1,2,2,1], nums2 = [2,2], 如果不加count[num]>0,那么会输出[2,2],而不是[2]
                result.push_back(num);
                count[num] = 0;  //为了防止重复添加元素，将count[num]置为0
            }
        }
        return result;
    }
};