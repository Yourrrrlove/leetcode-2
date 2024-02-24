#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count, count1; // 记录nums2和nums1中每个元素出现的次数
        vector<int> result;  // 记录交集元素
        for(const auto &num : nums2) ++count[num]; // 统计nums2中每个元素出现的次数
        for(const auto &num : nums1) ++count1[num];  // 统计nums1中每个元素出现的次数
        for(const auto &num : nums1){
            if(count.find(num) != count.end()){  // 如果nums1中的元素在nums2中出现过
                if(count[num] >0 && count1[num] > 0)  //如果num在num1和num2中出现次数不一致，则取较小值
                //例如num1 = [1,2,2,1], num2 = [2,2], 则输出[2,2]
                //例如num1 = [1,2,1], num2 = [2,2], 则输出[2]
                {
                    result.push_back(num);
                    --count[num];
                    --count1[num];
                }
            }
        }
        return result;
    }
};