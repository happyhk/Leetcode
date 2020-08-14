# 路径总和III

## 题目简介

给定一个二叉树，它的每个结点都存放着一个整数值。<br>

找出路径和等于给定数值的路径总数。<br>

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。<br>

## 代码

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
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        int res = pathSumStartWithRoot(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
        return res;
    }
    int pathSumStartWithRoot(TreeNode* root, int sum){
        if(root == nullptr) return 0;
        int res = 0;
        if(sum == root->val) res++;
        res += pathSumStartWithRoot(root->right, sum-root->val)+
        pathSumStartWithRoot(root->left, sum -root->val);
        return res;
    }
};
```

## 思路总结

路径和不一定要以根节点开始，不一定以尾结点结束，就很明确了递归那一步为：<br>

```c++
pathSumStartWithRoot(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
```

调用辅助函数pathSumStartWithRoot，对于这种返回值不是bool的题目来说，终止循环条件不一定要返回，直接res++也行的。然后直接在最后返回res。