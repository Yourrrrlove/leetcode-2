#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
    static const int N = 1001;
    int n;  //边的数量 = edges,size()
    int father[N];
    // 初始化 每个节点的父节点都初始化为自己
    void init(){
        for(int i = 0; i < N; ++i) father[i] = i;
    }
    // 查找根节点 路径压缩优化版本
    int find(int i){
        if(father[i] == i) return i; // 如果父节点是自己，返回自己
        else{
            // 不断向上查找祖先，路径压缩体现在这里，递归的过程中，会将[最初传进来的i到原来祖先之间]的所有节点的父节点都直接指向新传进来的根节点j
            //例如：原来4->3->2->1，要找4的祖先，会先查找3,3的祖先是2,2的祖先是1，1的祖先是1，所以4的祖先是1，共查找了4次
            //路径压缩后：在递归的过程中，会将4，3，2，1的父节点都直接指向1，以后若再查找4的祖先，只需查找1次，就能直接找到1
            father[i] = find(father[i]);
            return father[i];
        }
    }
    // 合并
    void join(int i, int j){
        int fa_i = find(i), fa_j = find(j); //找到i, j的祖先
        if(fa_i == fa_j) return;  //如果i, j的祖先相同，说明i, j已经在一个集合，不用再合并，直接返回即可
        father[fa_i] = fa_j; //将i的祖先指向j的祖先
    }
    // 判断i,j是否在同一个集合
    bool isSame(int i, int j){
        return find(i) == find(j); //如果i, j的祖先相同，说明i, j在同一个集合
    }

    // 判断删除edgetoRemoveIndex这条边后，剩下的边是否构成树
    bool isTreeafterRemove(vector<vector<int>>& edges, int edgetoRemoveIndex){
        init();
        for(int i = 0; i < n; ++i){
            if(i == edgetoRemoveIndex) continue;  //跳过要删除的边,相当于删除了这条边
            if(isSame(edges[i][0], edges[i][1])) return false; //构成有向环了，一定不是树
            else join(edges[i][0], edges[i][1]);
        }
        return true;
    }
    // 找到构成有向环的边
    vector<int> edgetoCircle(vector<vector<int>>& edges){
        init();
        for(int i = 0; i < n; ++i){
            if(isSame(edges[i][0], edges[i][1]) == true) return edges[i]; //如果当前两个节点已经在同一个集合中了，再把这两个节点连起来一定会产生环，所以由当前这两个节点连成的边可以删去
            else join(edges[i][0], edges[i][1]);
        }
        return {};
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int inDegree[N] = {0}; //记录每个节点的入度(有多少个箭头指向该节点)
        n = edges.size();  //边的数量
        for(int i = 0; i < n; ++i){
            ++inDegree[edges[i][1]];  //统计每个节点的入度
        }
        vector<int> twoedges;  //记录入度为2的节点的两条边
        for(int i = n - 1; i >= 0; --i){ //要倒序，因为优先返回最后出现在二维数组中的答案
            if(inDegree[edges[i][1]] == 2) twoedges.push_back(i); //找到入度为2的节点的两条边
        }
        if(twoedges.size() > 0){ //如果有入度为2的节点，那一定有两条边指向该节点，即twoedges.size() 一定== 2
            //在这两条边里删一个，看删哪个可以构成树
            if(isTreeafterRemove(edges, twoedges[0]) == true) return edges[twoedges[0]];
            else return edges[twoedges[1]];
        }
        //没有入度为2的节点，那么一定有环，删掉构成环的边
        return edgetoCircle(edges);
    }
};

int main(){
    vector<vector<int>> edges = {
        {1,2},
        {2,3},
        {3,4},
        {4,1},
        {1,5}
    };
    Solution s;
    vector<int> result = s.findRedundantDirectedConnection(edges);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}