#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    class myCompare{
    public:
        bool operator()(const vector<int> &v1, const vector<int> &v2){
            return v1[0] < v2[0]; // 按照气球左边界升序排序
        }
    };
    int findMinArrowShots(vector<vector<int>>& points){
        if(points.size() == 0) return 0;
        int result = 1;  //若气球数量不为0，则至少需要一支箭
        // 按照气球左边界升序排序
        sort(points.begin(), points.end(), myCompare());
        for(int i = 1; i < points.size(); ++i){
            // 若气球i的左边界大于气球i-1的右边界，说明气球i和气球i-1不重叠，需要多一支箭
            if(points[i][0] > points[i - 1][1]) ++result;
            // 若气球i的左边界小于等于气球i-1的右边界，说明气球i和气球i-1重叠，需要更新重叠气球最小右边界（为了正确判断下个气球与当前气球是否重叠）
            /*
            以{{1,6},{2,8},{7,12}, {10,16}}为例：
            [1,6]和[2,8]需要一支箭，[7,12]和[10,16]需要一支箭
            如果不将[2,8]的右边界更新为6，那么由于7不大于8，会认为[7,12]和[2,8]重叠，不需要多一支箭，从而导致错误答案
            */
            else points[i][1] = min(points[i - 1][1], points[i][1]);
        }
        return result;
    }
};

int main(){
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    Solution s;
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}