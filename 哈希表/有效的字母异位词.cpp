#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false; // 长度不同，肯定不是字母异位词，直接返回false
        int hash[26] = {0};  // 用于记录每个字母出现的次数，初始化为0，总共26个字母
        for(const auto &ch : s) ++hash[ch - 'a'];  // 遍历字符串s，统计s中的每个字母出现的次数
        for(const auto &ch : t) --hash[ch - 'a'];  // 遍历字符串t，用t中的每个字母出现的次数抵消s中的每个字母出现的次数
        // 如果s和t是字母异位词，那么s中的每个字母出现的次数和t中的每个字母出现的次数必定能相互抵消，即最后hash数组中的每个元素的值都应该是0
        for(const auto &x : hash){
            if(x != 0) return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    string s1 = "anagram", s2 = "nagarab";
    cout << std::boolalpha << s.isAnagram(s1, s2) << std::noboolalpha << endl;
    return 0;
}