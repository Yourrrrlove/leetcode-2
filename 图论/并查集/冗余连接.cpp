#include <iostream>
#include <vector>
using namespace std;


class Solution{
private:
    int n = 1001;
    vector<int> father = vector<int> (n, 0);
    // 初始化
    void init(){
        for(int i = 0; i < n; i++) father[i] = i; // 初始化每个节点的父节点都是自己
    }
    // 查找根节点  未进行路径压缩优化
    // int find(int i){
    //     if(father[i] == i) return i; // 如果父节点是自己，说明是祖先（根节点）
    //     else return find(father[i]); //不断向上查找祖先
    // }

    // 查找根节点  进行路径压缩优化
    int find(int i){
        if(father[i] == i) return i;  // 如果父节点是自己，说明是祖先（根节点）
        else{
            father[i] = find(father[i]);  //不断向上查找祖先，在这里进行了路径压缩，会将[最初传进来的i到原来祖先之间]的所有节点的父节点都直接指向新传进来的根节点j
            return father[i];
        }
    }
    // 合并
    void join(int i, int j){
        int i_father = find(i);  // 找到i的祖先
        int j_father = find(j);  // 找到j的祖先
        //if(i_father == j_father) return;  // 如果发现i, j的祖先相同，则说明i, j在一个集合，不用做下边的操作，直接返回即可
        father[i_father] = j_father;  // 将i的祖先指向j的祖先
    }

    // 判断是否在同一个集合
    bool isSame(int i, int j){
        return find(i) == find(j);  // 如果两个节点的祖先相同，说明在同一个集合
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for(int i = 0; i < edges.size(); i++){
            cout << "issame: " << isSame(edges[i][0], edges[i][1]) << endl;
            if(isSame(edges[i][0], edges[i][1]) == true) return edges[i];  //如果当前两个节点已经在在同一个集合中了（即有2相同的祖先），再把这俩节点连起来一定会产生环，所以由当前这俩节点连成的边可以删去
            else join(edges[i][0], edges[i][1]); //如果当前两个节点不在同一集合中（即当前两个节点没有相同祖先），就可以相连
        }
        return {};
    }
};

int main(){
    vector<vector<int>> edges = {
        {1,2},
        {2,3},
        {3,4},
        {1,4},
        {1,5}
    };
    Solution s;
    vector<int> result = s.findRedundantConnection(edges);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}