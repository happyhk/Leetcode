# 路径总和

## 题目简介

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
      if(root == nullptr) return false;
      if(root->left == nullptr && root->right == nullptr && root->val == sum) return true;
      return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right,sum-root->val);
    }
};
```

## 思路总结

依然是耳熟能详的二叉树框架，首先这个题目不用辅助函数，刚开始用了辅助函数，感觉不伦不类，其实只要考虑的是当前节点，如果为空，肯定是返回空的，接着就是如果满足当前是最后节点（判断标准是当前节点的左右子节点都为空），以及当前节点为sum的值，其实sum一直在被减，，也可以用一个cur值来代替，这就是当时用辅助函数的原因，那么就不用了cur了，选择了原始的sum，并且不断减小。当期节点的值为sum时即可以返回一个true。然后利用框架思想不断递归。