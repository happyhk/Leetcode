# 合并二叉树

## 题目介绍

给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。<br>

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。<br>

## 代码

```c
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
      if(t1 == NULL && t2 == NULL) return NULL;
      if(t1 == NULL) return t2;
      if(t2 == NULL) return t1;
      TreeNode* root = new TreeNode(0);
      root->val = t1->val + t2->val;
      root->left = mergeTrees(t1->left,t2->left);
      root->right = mergeTrees(t1->right,t2->right);
      return root;
    }
};
```

## 思路总结

二叉树的问题依然是框架的问题，比如本题，需要合并二叉树，正常的情况都可以想到四种情况，第一种是如果t1和t2都为空，则可以直接返回一个空就行；第二种和第三种是t1和t2只有一个为空，则返回另外一个不为空的节点就行；第四种情况是t1和t2都不为空，这样的话就需要重新定义一个root节点，分别进行左右遍历即可！