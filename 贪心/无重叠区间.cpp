#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
弓箭的数量就相当于是非交叉区间的数量
只要把弓箭那道题目代码里射爆气球的判断条件加个等号（认为[0，1][1，2]不是相邻区间）
然后用总区间数减去弓箭数量 就是要移除的区间数量了。
*/

class Solution{
public:
    class myCompare{
    public:
        bool operator()(const vector<int> &v1, const vector<int> &v2){
            return v1[0] < v2[0]; // 按照区间左边界升序排序
        }
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), myCompare());
        int result = 1;
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] >= intervals[i - 1][1]) ++result;
            else intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
        }
        return intervals.size() - result;
    }
};