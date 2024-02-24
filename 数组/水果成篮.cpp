#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// 滑动窗口

class Solution{
public:
    int totalFruit(vector<int> &fruits){
        int left = 0, result = 0; // left是窗口左边界, result是可以收集的水果的最大数目
        unordered_map<int, int> count; //{水果种类：水果数量}
        for(int right = 0; right < fruits.size(); right++){// right是窗口右边界
            ++count[fruits[right]]; // 统计right类水果的数量   fruits = [1,2,1]，1代表第1类，2代表第2类...
            while(count.size() > 2){  //只有两个篮子，每个篮子只能装一类水果，所以只能采集两种水果
                if(--count[fruits[left]] == 0){ //必须先把left类水果的数量减为0，再删除left类水果
                //例如[1,1,2,3]，当三类水果都在count中时，{1:2},{2:1},{3:1}，第一次--后，left从第一个1移动到第二个1，第二次--后，left从第二个1移动到2；此时left才算移动到了下一类水果
                //如果不将left类水果的数量减到0，而是直接erase掉left类水果，那么下面的++left只会执行一次，也就是left从第一个1移动到第二个1，还是第1类水果，此时left=1,right=3，导致采集了3类水果，违反题意
                    count.erase(fruits[left]);
                }
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> fruits{0,1,2,2};
    cout << s.totalFruit(fruits) << endl;
    return 0;
}