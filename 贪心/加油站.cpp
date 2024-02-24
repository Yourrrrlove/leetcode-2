#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //如果gas的总和小于cost总和，那么无论从哪里出发，一定是跑不了一圈的
        if(accumulate(gas.begin(), gas.end(), 0) - accumulate(cost.begin(), cost.end(), 0) < 0) return -1;
        int startIndex = 0, curSum = 0; //curSum表示标号[startIndex, i]加油站累积的净油量
        for(int i = 0; i < gas.size(); ++i){
            curSum += (gas[i] - cost[i]);
            //如果curSum < 0，说明从startIndex到i这段路都不可能是起点
            //因为在这个区间选择任何一个位置作为起点，到i这里都会断油
            //那么起始位置从i+1重新算起，再从0计算curSum
            if(curSum < 0){
                curSum = 0;
                startIndex = i + 1;
            }
        }
        return startIndex;
    }
};

int main(){
    Solution s;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}