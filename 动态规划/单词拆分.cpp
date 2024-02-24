#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <climits>
using namespace std;

//完全背包问题：容量为s.size()的字符串，能否用字典中的单词组成
//本题是求排列问题，因为组成的字符串是否正确和单词顺序有关，所以先遍历背包，后遍历物品
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false); //dp[j]表示长度为j的字符串能否用字典中的单词组成
        dp[0] = true; //空字符串，有1种排列方式，即什么都不装
        //求排列数，只能先遍历背包，再遍历物品
        for(int j = 0; j <= s.size(); ++j){
            for(int i = 0; i < j; ++i){
                string word = s.substr(i, j - i);
                //子串0-i可以用字典中的单词组成，且子串i-j在字典中，则0-j的字符串可以用字典中的单词组成
                if(dp[i] == true && wordset.find(word) != wordset.end()) dp[j] = true;
            }
        }
        return dp[s.size()];
    }
};