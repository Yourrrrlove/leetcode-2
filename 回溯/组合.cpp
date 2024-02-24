#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int begin, int n, int k){
        if(path.size() == k){ //选够了k个数，就把path加入到result中
            result.push_back(path);
            return;
        }
        //for(int i = begin; i <= n; ++i)  //不剪枝
        for(int i = begin; i <= n - (k - path.size()) + 1; ++i){ //剪枝
            path.push_back(i);  //先选一个数 i
            backtracking(i + 1, n, k); //在[i+1, n]中选剩下的数
            path.pop_back(); //回溯
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        if(n < k) return {};
        path.clear();
        result.clear();
        backtracking(1, n, k);
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> ret = s.combine(4, 2);
    for(const auto &vec : ret){
        for(const auto &num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}