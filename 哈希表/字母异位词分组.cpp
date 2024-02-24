#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// class Solution {
// private:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size()) return false; // 长度不同，肯定不是字母异位词，直接返回false
//         int hash[26] = {0};  // 用于记录每个字母出现的次数，初始化为0，总共26个字母
//         for(const auto &ch : s) ++hash[ch - 'a'];  // 遍历字符串s，统计s中的每个字母出现的次数
//         for(const auto &ch : t) --hash[ch - 'a'];  // 遍历字符串t，用t中的每个字母出现的次数抵消s中的每个字母出现的次数
//         // 如果s和t是字母异位词，那么s中的每个字母出现的次数和t中的每个字母出现的次数必定能相互抵消，即最后hash数组中的每个元素的值都应该是0
//         for(const auto &x : hash){
//             if(x != 0) return false;
//         }
//         return true;
//     }
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> result;  // 用于存放分组结果
//         if(strs.size() == 0) return result;
//         vector<string> path;  // 用于存放每个分组
//         vector<bool> visited(strs.size(), false);  // 用于标记每个字符串是否已经被访问过
//         for(int i = 0; i < strs.size(); i++){
//             if(visited[i]) continue; // 如果当前字符串已经被访问过，直接跳过，不能重复添加
//             visited[i] = true;  // 标记当前字符串已经被访问过
//             path.clear();  // 清空path，准备存放新的分组
//             path.push_back(strs[i]);  // 将当前字符串添加到path中
//             for(int j = i + 1; j < strs.size(); j++){
//                 if(visited[j]) continue;
//                 if(isAnagram(strs[i], strs[j])){ // 如果当前字符串和strs[i]是字母异位词，将其添加到path中
//                     visited[j] = true;  // 标记当前字符串已经被访问过
//                     path.push_back(strs[j]);
//                 }
//             }
//             result.push_back(path);  // 将path添加到result中
//         }
//         return result;
//     }
// };


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;  // 用于存放分组结果
        if(strs.size() == 0) return result;
        unordered_map<string, vector<string>> hash;  // 用于存放每个分组
        
        for(string &s : strs){
            string key = s;
            //由于互为字母异位词的两个字符串包含的字母相同，因此对两个字符串分别进行排序之后得到的字符串一定是相同的，故可以将排序之后的字符串作为哈希表的键。
            sort(key.begin(), key.end()); 
            hash[key].emplace_back(s); //将互为字母异位词的字符串放在一个vector中，实现分组
        }
        for(auto it = hash.begin(); it != hash.end(); ++it){
            result.emplace_back(it->second);  // 将每个分组添加到result中
        }
        return result;
    }
};