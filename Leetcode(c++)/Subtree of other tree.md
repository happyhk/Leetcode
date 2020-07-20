# 另一个树的子树

## 题目简介

给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。<br>

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr) return false;
        return isSubTreeStartRoot(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    bool isSubTreeStartRoot(TreeNode* s,TreeNode* t){
        if(s == nullptr && t == nullptr) return true;
        if(s == nullptr || t == nullptr) return false;
        if(s->val != t->val) return false;
        return isSubTreeStartRoot(s->left,t->left) && isSubTreeStartRoot(s->right,t->right);
    }
};
```

## 思路总结

这个问题也是一个比较典型的利用辅助函数，并且递归时同时用两个不同的函数进行递归，只要这个明确了，其他都是小意思。