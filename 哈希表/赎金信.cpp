#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) return false;  // 如果ransomNote的长度大于magazine的长度，那么ransomNote肯定不能由magazine中的字母构成
        int hash[26] = {0};  // 用于记录magazine中每个字母出现的次数，初始化为0，总共26个字母
        for(const auto &ch : magazine) ++hash[ch - 'a'];  // 遍历magazine，统计magazine中的每个字母出现的次数
        for(const auto &ch : ransomNote) --hash[ch - 'a'];  // 遍历ransomNote，用ransomNote中的每个字母出现的次数抵消magazine中的每个字母出现的次数
        for(const auto &count : hash){
            if(count < 0) return false;  //若hash数组中有元素的值小于0，说明magazine中的字母出现的次数不够ransomNote中的字母出现的次数，那就不能用magazine中的字母凑成ransomNote，返回false
        }
        return true;
    }
};