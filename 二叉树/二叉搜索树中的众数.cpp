#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode){}
};

using namespace std;

//通用递归方法，适用于任何二叉树
class Solution {
private:
    //遍历所有节点，并用unordered_map统计每个节点值出现的次数
    void traversal(TreeNode *root, unordered_map<int, int> &map){
        if(root == nullptr) return;
        ++map[root->val];
        traversal(root->left, map);
        traversal(root->right, map);
    }
public:
    //自定义比较函数，按照出现次数降序排列
    class Compare{
    public:
        bool operator()(pair<int, int> &x, pair<int, int> &y) const{
            return x.second > y.second;
        }
    };
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;
        traversal(root, map);
        //把map转换成vector，然后按照出现次数降序排列
        vector<pair<int ,int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), Compare());
        //找出出现次数最多的节点值
        vector<int> result;
        result.push_back(vec[0].first);  //先把出现次数最多的节点值放入result
        //如果有多个节点值和vec[0].first出现次数一样多，都放入result
        for(size_t i = 1; i < vec.size(); ++i){
            if(vec[i].second == vec[0].second) result.push_back(vec[i].first);
            else break;
        }
        return result;
    }
};

//递归 中序遍历
class Solution {
private:
    int count, maxcount;
    TreeNode *pre = nullptr;
    vector<int> result;
    void traversal(TreeNode *root){
        if(root == nullptr) return;
        traversal(root->left);  //左
        //中
        if(pre == nullptr) count = 1;  //root是第一个节点
        else if(pre->val == root->val) ++count;  //root和pre节点值相同
        else count = 1;  //root和pre节点值不同
        pre = root;  //更新pre
        if(count == maxcount) result.push_back(root->val); //如果count等于maxcount，把root->val放入result
        else if(count > maxcount){
            maxcount = count;
            result.clear();  //如果count大于maxcount，说明之前result中的元素都不是出现频率最高的，要清空result数组
            result.push_back(root->val);  //现在的root->val才是出现频率最高的，放入result
        }
        //右
        traversal(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0, maxcount = 0;
        pre = nullptr;
        result.clear();
        traversal(root);
        return result;
    }
};

//迭代 中序遍历
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr) return {};
        int count = 0, maxcount = 0;
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;  //左
            }
            else{
                cur = st.top();  //中
                st.pop();
                if(pre == nullptr) count = 1;
                else if(pre->val == cur->val) ++count;
                else count = 1;
                pre = cur;
                if(count == maxcount) result.push_back(cur->val);
                if(count > maxcount){
                    maxcount = count;
                    result.clear();
                    result.push_back(cur->val);
                }
                cur = cur->right;  //右
            }
        }
        return result;
    }
};
