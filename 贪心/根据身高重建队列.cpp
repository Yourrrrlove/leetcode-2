#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Solution {
public:
    class myCompare{
    public:
        bool operator()(const vector<int> &vec1, const vector<int> &vec2){
            if(vec1[0] == vec2[0]) return vec1[1] < vec2[1]; // 身高相同，按照k升序
            return vec1[0] > vec2[0]; // 身高降序
        }
    };
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
        // 按照身高降序排序, 若身高相同按照k升序排序
        sort(people.begin(), people.end(), myCompare());
        //用链表插入，效率高
        list<vector<int>> que;
        for(int i = 0;i < people.size(); ++i){
            int insertPos = people[i][1]; // people[i]要插入的位置
            auto it = que.begin(); // 插入位置的迭代器
            while(insertPos--) ++it; //移动迭代器到插入位置
            que.insert(it, people[i]); // 插入people[i]
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};

int main(){
    vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution s;
    vector<vector<int>> res = s.reconstructQueue(people);
    for(auto &vec : res){
        for(auto &i : vec){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}