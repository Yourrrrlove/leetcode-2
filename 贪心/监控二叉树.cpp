#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
头结点放不放摄像头也就省下一个摄像头， 叶子节点放不放摄像头省下了的摄像头数量是指数阶别的。

所以要从下往上看，局部最优：让叶子节点的父节点安摄像头，所用摄像头最少，整体最优：全部摄像头数量所用最少！

思路就是从低到上，先给叶子节点父节点放个摄像头，然后隔两个节点放一个摄像头，直至到二叉树头结点。

数字0 1 2 的含义：
0：该节点无覆盖
1：本节点有摄像头
2：本节点有覆盖
*/
class Solution{
private:
    int result = 0;
    //后序遍历，左右根
    int traversal(TreeNode *cur){
        if(cur == nullptr) return 2; //空节点有覆盖
        int left = traversal(cur->left); //左
        int right = traversal(cur->right); //右
        if(left == 2 && right == 2) return 0; //左右节点都有覆盖，当前节点无覆盖

        //下面这两种情况 不能交换顺序
        /*
        如果我们交换这两个if语句的顺序，那么当左子节点或右子节点无覆盖，而另一个子节点已经放置了摄像头时，
        代码会先执行if(left == 1 || right == 1)，误判断当前节点已经被覆盖，
        然后跳过if(left == 0 || right == 0)，导致无覆盖的节点没有被覆盖，这是错误的。
        所以，if(left == 0 || right == 0)和if(left == 1 || right == 1)的顺序不能交换。
        */
        if(left == 0 || right == 0){ //左右节点只要有一个无覆盖，当前节点就放摄像头
            ++result;
            return 1; //返回当前节点放置摄像头后的状态
        }
        if(left == 1 || right == 1) return 2; //左右节点有一个放了摄像头，则当前节点就已经被覆盖
        return -1;
    }
public:
    int minCameraCover(TreeNode* root){
        if(root == nullptr) return 0;
        result = 0;
        if(traversal(root) == 0) ++result; //如果左右子树都被监控了，只剩根节点无覆盖，就在根节点额外放1个摄像头
        return result;
    }
};