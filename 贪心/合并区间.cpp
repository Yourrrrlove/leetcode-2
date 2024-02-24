#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        if(intervals.size() == 0) return {};
        vector<vector<int>> result;
        // 按照区间左边界升序排序
        sort(intervals.begin(), intervals.end(), [](const vector<int> &v1, const vector<int> &v2){return v1[0] < v2[0];});
        result.push_back(intervals[0]); // 先把第一个区间放进去
        for(int i = 1; i < intervals.size(); ++i){
            // 如果当前区间的左边界小于等于result中最后一个区间的右边界，说明有重叠，更新result中最后一个区间的右边界(相当于合并)
            if(result.back()[1] >= intervals[i][0]) result.back()[1] = max(result.back()[1], intervals[i][1]);
            // 如果当前区间的左边界大于result中最后一个区间的右边界，说明没有重叠，直接放进result
            else result.push_back(intervals[i]);
        }
        return result;
    }
};