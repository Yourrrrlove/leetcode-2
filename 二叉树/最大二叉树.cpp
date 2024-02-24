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
    int findMaxIndex(vector<int> &nums, int begin, int end){
        int maxval = nums[begin], index = begin;
        for(; begin < end; ++begin){
            if(nums[begin] > maxval){
                maxval = nums[begin];
                index = begin;
            }
        }
        return index;
    }
    TreeNode *traversal(vector<int> &nums, int start, int end){
        if(start == end) return nullptr;
        //找到最大值在nums中的下标
        int index = findMaxIndex(nums, start, end);
        //根据最大值创建根节点
        TreeNode *root = new TreeNode(nums[index]);
        //递归创建左子树
        root->left = traversal(nums, start, index);
        //递归创建右子树
        root->right = traversal(nums, index + 1, end);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        return traversal(nums, 0, nums.size());
    }
};