# 两节点的最长路径

## 题目描述

给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。<br>

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
    int depth = 0;
    int diameterOfBinaryTree(TreeNode* root) {
      maxdepth(root);
      return depth;
    }
    int maxdepth(TreeNode* root){
      if(root == nullptr) return 0;
      int maxleft = maxdepth(root->left);
      int maxright = maxdepth(root->right);
      depth = max(depth,maxleft+maxright); //用来记录以每个节点作为根节点的最大路径值
      return max(maxleft,maxright)+1; //返回的是当前节点的最大深度
    }
};
```

## 思路阐述

二叉树的问题还是可以归结为框架，只要处理好当前节点所要做的事情即可，其他的交给框架，本题当前节点需要做的事情有两个：<br>

1、记录当前节点作为根节点的最大路径长度；<br>

2、记录当前节点的最大深度<br>

只要完成这两个任务即可。