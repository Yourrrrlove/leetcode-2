#include <iostream>
#include <vector>
using namespace std;
/*
输入：bills = [5,5,5,10,20]
输出：true
解释：
前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 true。
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for(const auto &bill : bills){
            if(bill == 5){
                ++five;
                continue; // 5元不用找零
            }
            if(bill == ten){
                ++ten;
                if(five == 0) return false; //10元只能用5元找零
                --five;
                continue;
            }
            if(bill == 20){
                ++twenty;
                /*
                five < 3 && ten < 1 包括两种情况：只有5元，没有10元 或 有不到三张5元，没有10元;
                ten >= 1 && five <= 0： 只有10元，没有5元
                */
                if(five < 3 && ten < 1 || (ten >= 1 && five <= 0)) return false;
                // 优先用10元 + 5元 找零
                if(ten >= 1 && five >= 1){
                    --ten;
                    --five;
                    continue;
                }
                // 用三张5元找零
                if(five >= 3){
                    five -= 3;
                    continue;
                }
            }
        }
        return true;
    }
};

int main(){
    vector<int> bills = {5,5,5,10,20};
    Solution s;
    cout << s.lemonadeChange(bills) << endl;
    return 0;
}