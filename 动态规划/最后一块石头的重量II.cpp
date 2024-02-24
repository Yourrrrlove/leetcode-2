#include <iostream>
#include <vector>
using namespace std;

//将石头分成重量和尽可能相等的两堆，最后两堆相减
//也就是尽可能装满 sum/2 的背包，最后return sum - dp[sum/2]
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto const &stone : stones) sum += stone;
        vector<int> dp(1 + sum / 2, 0);
        for(int i = 0; i < stones.size(); ++i){
            for(int j = sum; j >= stones[i]; --j){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        //最后应该返回两堆石头的差值，sum - dp[sum/2]为一堆，dp[sum/2]为另一堆，所以返回两者差值sum - 2 * dp[sum / 2]
        return sum - 2 * dp[sum / 2];
    }
};

int main(){
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    Solution s;
    cout << s.lastStoneWeightII(stones) << endl;
    return 0;
}