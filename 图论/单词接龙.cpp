#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//无向图求最短路，广搜最为合适，广搜只要搜到了终点，那么一定是最短的路径
class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordset(wordList.begin(), wordList.end()); // 将vector转成unordered_set，提高查询速度
		if (wordset.count(endWord) == 0) return 0;  // 如果endWord没有在wordSet出现，直接返回0
		unordered_map<string, int> visitedmap;  //// 记录word是否访问过  key:word  value:到达该word的路径长度
		queue<string> wordque;
		wordque.push(beginWord); // 初始化，将beginWord放入队列
		visitedmap[beginWord] = 1;  // 初始化，刚开始只有beginWord，所以到达beginWord的路径长度为1
		while (!wordque.empty()) {
			string cur_word = wordque.front();
			wordque.pop();
			int path_length = visitedmap[cur_word];  // 到当前word的路径长度
			for (int i = 0; i < cur_word.size(); i++) {
				string new_word = cur_word; // 用一个新单词替换word
				for (int j = 0; j < 26; j++) {  //每次只能换一个字母，从26个字母中挨个试
					new_word[i] = j + 'a';
					if (new_word == endWord) return path_length + 1;   //试出了endWord，返回路径长度
					// 如果新单词在wordSet中出现过，且没有被访问过，将其放入队列，并标记为已访问
					if (wordset.count(new_word) != 0 && visitedmap.find(new_word) == visitedmap.end()) {
						wordque.push(new_word);
						visitedmap[new_word] = path_length + 1; //添加访问信息，本题是一个无向图，需要用标记位，标记着节点是否走过，否则会死循环
					}
				}
			}
		}
		return 0;
	}
};