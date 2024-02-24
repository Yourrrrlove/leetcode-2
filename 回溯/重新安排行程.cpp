#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
private:
    vector<string> result;
    //string表示出发机场，map表示<终点机场, 可飞往终点机场的次数>
    unordered_map<string, map<string, int>> targets;
    //只要找到一条最小行程就立刻结束搜索，所以使用bool返回值
    bool backtracking(vector<vector<string>> &tickets, int flightNum){ //flightNum表示航班数(tickets.size())
        //n个航班需要n+1个机场，所以找到n+1个机场就表示所有航班都飞过了，结束搜索
        if(result.size() == flightNum + 1) return true;
        //pair中的const string表示终点机场，int表示可飞往机场的次数
        //targets[result.back()]表示以result中最后一个机场为出发机场的可飞往机场的名称和次数
        for(pair<const string, int> &target : targets[result.back()]){
            if(target.second > 0){ //如果可飞往机场的次数大于0
                result.push_back(target.first);
                --target.second;
                if(backtracking(tickets, flightNum) == true) return true;
                //回溯
                result.pop_back();
                ++target.second;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //初始化targets
        //ticket[0]表示出发机场，ticket[1]表示终点机场，targets[ticket[0]][ticket[1]]表示出发机场为ticket[0]的机场可飞往ticket[1]的次数
        for(vector<string> & ticket : tickets) ++targets[ticket[0]][ticket[1]];
        //起始机场为"JFK"
        result.push_back("JFK");
        backtracking(tickets, tickets.size());
        return result;
    }
};

int main(){
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    Solution s;
    vector<string> result = s.findItinerary(tickets);
    for(string & str : result) cout << str << " ";
    cout << endl;
    return 0;
}