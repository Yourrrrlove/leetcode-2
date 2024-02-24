#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    // 获取path中的元素和
    int getSum(vector<int> &path){
        int sum = 0;
        for(const auto &num : path) sum += num;
        return sum;
    }
    void backtracking(int startIndex, int k, int n){
        if(getSum(path) > n) return;  // 剪枝
        if(path.size() == k){
            if(getSum(path) == n) result.push_back(path); //path中的元素个数等于k且元素和等于n，将path加入result
            return;  //如果path中的元素个数等于k但元素和不等于n，直接返回
        }
        for(int i = startIndex; i <= 9 - (k - path.size()) + 1; ++i){
            path.push_back(i);
            backtracking(i + 1, k, n);
            path.pop_back();  // 回溯
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k > 9 || n > 45) return {};
        path.clear();
        result.clear();
        backtracking(1, k, n);
        return result;
    }
};

int main(){
    Solution s;
    auto ret = s.combinationSum3(3, 9);
    for(const auto &vec : ret){
        for(const auto &num : vec){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}