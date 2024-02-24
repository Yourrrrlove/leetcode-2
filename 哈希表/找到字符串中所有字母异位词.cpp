#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> result;
//         if(p.size() > s.size()) return result; // 若p的长度大于s的长度，那s中一定不存在p的异位词
//         sort(p.begin(), p.end());  // 对p进行排序
//         for(int i = 0; i <= s.size() - p.size(); i++){
//             string str = s.substr(i, p.size());  // 截取s中长度为p.size()的子串
//             sort(str.begin(), str.end());  // 对子串进行排序
//             if(str == p) result.push_back(i);  // 若子串和p互为异位词，则排序后的子串e和排序后的p一定相等，将字串的起始索引i加入结果数组
//         }
//         return result;
//     }
// };

//滑动窗口
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(p.size() > s.size()) return result; // 若p的长度大于s的长度，那s中一定不存在p的异位词
        
        return result;
    }
};


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if(m < n) return {};
        vector<int> hashTable(26);
        for(auto ch : p) ++hashTable[ch - 'a']; // 统计p中每个字符出现的次数
        vector<int> ret;
        for(int l = 0, r = 0; r < m; ++r) {
            --hashTable[s[r] - 'a']; // 先减去当前字符的个数
            while(hashTable[s[r] - 'a'] < 0) {  // 当前字符的个数小于0，说明当前字符在p中不存在，或者之前出现过，但是在当前窗口中出现的次数超过了p中的次数，需要移动滑动窗口的左边界
                ++hashTable[s[l] - 'a'];
                ++l;
            }
            if(r - l + 1 == n) ret.push_back(l); // 当前窗口的大小等于p的长度，说明找到了一个异位词，将滑动窗口的左边界加入结果数组
        }
        return ret;
    }
};