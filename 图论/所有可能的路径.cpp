#include <iostream>
#include <vector>
using namespace std;

//深搜,沿着一个方向一直走到底，然后回溯
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int cur){  //当前遍历的节点为cur
        if(cur == graph.size() - 1){  //若当前节点=graph.size()-1，即n-1，说明遍历到了最后一个节点
            result.push_back(path); //收获结果
            return;  //返回上一层
        }
        for(int i = 0; i < graph[cur].size(); i++){ //遍历节点cur链接的所有节点
            //graph[cur][i]为当前节点cur所连接的节点中的第i个节点
            path.push_back(graph[cur][i]);  //先把节点0和节点graph[cur][i]连起来
            dfs(graph, graph[cur][i]);  //递归  去搜索graph[cur][i]又连接了哪些节点
            path.pop_back();  //回溯
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.clear();
        result.clear();
        path.push_back(0); //先把0节点放入path,因为起点都要从0开始
        dfs(graph, 0);  //从0节点开始深搜
        return result;
    }
};