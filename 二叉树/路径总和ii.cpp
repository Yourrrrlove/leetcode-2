#include <string>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode){}
};

class Solution {
private:
    void traversal(TreeNode *cur, int count){
        if(cur->left == nullptr && cur->right == nullptr){  //到了叶子节点
            if(count == 0) result.push_back(path);  //如果这条路径上的节点之和等于targetSum，则将这条路径加入到result中
            return;  //只要到了叶子节点，就要返回，不管这条路径上的节点之和是否等于targetSum
        }
        if(cur->left){  //左
            path.push_back(cur->left->val);
            traversal(cur->left, count - cur->left->val);
            path.pop_back();  //回溯
        }
        if(cur->right){  //右
            path.push_back(cur->right->val);
            traversal(cur->right, count - cur->right->val);
            path.pop_back(); //回溯
        }
    }
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return {};
        path.clear();
        result.clear();
        path.push_back(root->val);
        traversal(root, targetSum - root->val);
        return result;
    }
};