#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

//小顶堆法，顶堆是完全二叉树，父节点>左右子树，则为大顶堆；父节点<左右子树，则为小顶堆

class Solution {
public:
    class MyCompare{   //关系仿函数，指定比较规则，使小顶堆可以比较pair<int, int>数据类型
    public:
        bool operator()(const pair<int, int>& x, const pair<int, int>& y){
            //树的生成是从头节点开始，小顶堆的孩子节点比头节点大的，应排到后面，所以为了让小顶堆从小到大排序，这里的仿函数应该和正常的升序仿函数反着写（即：正常的升序仿函数应该是return x < y; 小顶堆的升序仿函数就要写return x > y）
            return x.second > y.second;  //<key, value>类型，按照value（出现频率）比较
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        for(int i = 0; i < nums.size(); i++)
        {
            mymap[nums[i]]++;  //先将<元素值，元素出现频率>存到unordered_map中
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int> >, MyCompare> my_prique;  //创建按照MyCompare排序规则的小顶堆，为什么要有vector<pair<int, int>我也不知道原因，创建小顶堆的语法就是这样，记住就好了
        for(unordered_map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++){
            my_prique.push(*it);
            if(my_prique.size() > k){  //小顶堆中只维护 k 个pair<key, value>类型的数据，超过k个就要pop掉
                my_prique.pop();
            }
        }//遍历完unordered_map后，小顶堆中只有k个元素（按频率升序排序）
        vector<int> result(k);  //这里的result必须指明大小为k，因为下边先给result[i]赋值，必须先确定result的大小
        for(int i = k - 1; i >= 0; i--)  //由于小顶堆是按照出现频率从小到大排序的，为了取前k个最高频率的元素，应该倒着存储
        {
            result[i] = my_prique.top().first;  //小顶堆中每个元素都是pair<元素值, 频率>类型，first才是元素值
            my_prique.pop();
        }
        return result;
    }
};


int main(){
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution s;
    vector<int> result = s.topKFrequent(nums, k);
    for(const auto &num : result) cout << num << " ";
    cout << endl;
    return 0;
}