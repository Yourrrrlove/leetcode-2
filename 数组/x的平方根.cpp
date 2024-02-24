#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int mySqrt(int x){
        int res = -1, left = 0, right = x, mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if((long long) mid*mid <= x){  //转为long long型，防止溢出
                res = mid;  //res为 满足k^2 <= x 的最大k值
                left = mid + 1;
            }
            else right = mid - 1;
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.mySqrt(9) << endl;
    return 0;
}