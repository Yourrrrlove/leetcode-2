#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//深搜dfs
// class Solution {
// //处理当前节点，然后递归处理子节点
// //private:
// //    void dfs(const vector<vector<int>>& rooms, int key, vector<bool>& visited) {
// //        if (visited[key] == true) return;
// //        visited[key] = true;
// //        vector<int> keys = rooms[key];
// //        for (auto i : keys) {
// //            dfs(rooms, i, visited);
// //        }
// //    }
// //处理下一节点
// private:
//     void dfs(const vector<vector<int>>& rooms, int key, vector<bool>& visited) {
//         visited[key] = true;
//         vector<int> keys = rooms[key]; //当前房间能拿到的钥匙
//         for (auto i : keys) {
//             if (visited[i] == false) {  //只去没去过的房间
//                 visited[i] = true;
//                 dfs(rooms, i, visited);
//             }
//         }
//     }
// public:
//     bool canVisitAllRooms(vector<vector<int>>& rooms) {
//         vector<bool> visited(rooms.size(), false);
//         dfs(rooms, 0, visited);
//         for (auto i : visited) {
//             if (i == false) return false;  //遍历visited数组，如果有false，说明在dfs后仍然有房间到达不了
//         }
//         return true;
//     }
// };


//广搜bfs
class Solution {
private:
    void bfs(const vector<vector<int>>& rooms, int key, vector<bool>& visited) {
        queue<int> que;
        que.push(0);
        while (!que.empty()) {
            int key = que.front();
            que.pop();
            vector<int> keys = rooms[key];
            for (auto i : keys) {
                if (visited[i] == false) {
                    visited[i] = true;
                    que.push(i);
                }
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false); //记录房间是否访问过
        visited[0] = true;  //从0号房间开始，0号房间肯定访问过
        bfs(rooms, 0, visited);
        for (auto i : visited) {
            if (i == false) return false;  //bfs后，如果仍然有房间没访问过，说明有房间始终到达不了，返回false
        }
        return true;
    }
};