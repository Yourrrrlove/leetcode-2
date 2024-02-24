#include <iostream>
#include <vector>
using namespace std;

/*
判断 一个顶点到另一个顶点有没有有效路径其实就是看这两个顶点是否在同一个集合里
*/

class Solution{
private:
    int n = 200001;
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
        if(i_father == j_father) return;  // 如果发现i, j的祖先相同，则说明i, j在一个集合，不用做下边的操作，直接返回即可
        father[i_father] = j_father;  // 将i的祖先指向j的祖先
    }

    // 判断是否在同一个集合
    bool isSame(int i, int j){
        return find(i) == find(j);  // 如果两个节点的祖先相同，说明在同一个集合
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        init();
        for(int i = 0; i < edges.size(); i++){
            join(edges[i][0], edges[i][1]);
        }
        return isSame(source, destination);
    }
};