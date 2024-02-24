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

class Solution {
private:
    TreeNode *traversal(vector<int> &nums, int left, int right){
        if(left > right) return nullptr; //递归终止条件
        int middle = left + (right - left) / 2; //找到中间位置 防止溢出
        TreeNode *root = new TreeNode(nums[middle]); //用nums数组中间位置的值创建根节点
        root->left = traversal(nums, left, middle - 1); //递归创建左子树 左闭右闭
        root->right = traversal(nums, middle + 1, right);  //递归创建右子树 左闭右闭
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = traversal(nums, 0, nums.size() - 1);
        return root;
    }
};