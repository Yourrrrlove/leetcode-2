#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
输入: g = [1,2], s = [1,2,3]
输出: 2
解释: 
你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
你拥有的饼干数量和尺寸都足以让所有孩子满足。
所以你应该输出2.
*/

// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         if(s.size() == 0 || g.size() == 0) return 0;
//         //必须先升序排序
//         sort(s.begin(), s.end());
//         sort(g.begin(), g.end());
//         int result = 0;
//         int i = s.size() - 1, j = g.size() - 1;
//         //从后往前遍历胃口和饼干尺寸
//         while(i >= 0 && j >= 0){ //防止越界，只要有一个遍历完了就结束
//             while(j >= 0 && s[i] < g[j]) --j; //如果饼干尺寸小于胃口，就尝试满足上一个较小的胃口，直到s[i]能满足g[j]或者遍历完胃口
//             if(j >= 0) --i, --j, ++result; //满足了一个孩子，饼干和胃口都减一
//         }
//         return result;
//     }
// };

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0 || g.size() == 0) return 0;
        //必须先升序排序
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int result = 0;
        int i = s.size() - 1;
        //从后往前遍历胃口和饼干尺寸
        for(int j = g.size() - 1; j >= 0; --j){
            if(i >= 0 && s[i] >= g[j]){
                ++result;
                --i;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> g = {1,2,4};
    vector<int> s = {1,2,3};
    cout << sol.findContentChildren(g, s) << endl;
    return 0;
}