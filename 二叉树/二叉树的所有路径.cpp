#include <iostream>
#include <stack>
#include <queue>
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
    void backtracking(TreeNode *cur, vector<int> &path, vector<string> &result){
        path.push_back(cur->val);  //中
        if(cur->left == nullptr && cur->right == nullptr){
            string str;
            for(size_t i = 0; i < path.size() - 1; ++i) str += (std::to_string(path[i]) + "->");
            result.push_back(str + std::to_string(path[path.size() - 1]));
            return;
        }
        if(cur->left){
            backtracking(cur->left, path, result);  //左
            path.pop_back();  //回溯
        }
        if(cur->right){
            backtracking(cur->right, path, result); //右
            path.pop_back(); //回溯
        }

    }
public:
    vector<int> path;
    vector<string> result;
    vector<string> binaryTreePaths(TreeNode* root) {
        path.clear();
        result.clear();
        if(root == nullptr) return result;
        backtracking(root, path, result);
        return result;
    }
};


//精简版

class Solution {
private:
    void backtracking(TreeNode *cur, string path, vector<string> &result){
        path += std::to_string(cur->val);  //中
        if(cur->left == nullptr && cur->right == nullptr){
            result.push_back(path);
            return;
        }
        if(cur->left) backtracking(cur->left, path + "->", result); //左
        if(cur->right) backtracking(cur->right, path + "->", result);  //右
    }
public:
    string path;
    vector<string> result;
    vector<string> binaryTreePaths(TreeNode* root) {
        path.clear();
        result.clear();
        if(root == nullptr) return result;
        backtracking(root, path, result);
        return result;
    }
};