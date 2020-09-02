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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      if(preorder.size() == 0) return NULL;
    vector<int> left_preorder, left_inorder, right_preorder, right_inorder;
    int tmp = preorder[0];
    TreeNode *root = new TreeNode(tmp);
    int index = 0;
    for(int i = 0; i < inorder.size(); ++i) {
        if(tmp == inorder[i]) {
            index = i;
            break;
        }
    }
    for(int i = 1; i <= index; ++i) {
        left_preorder.push_back(preorder[i]);
    }
    for(int i = index + 1; i < preorder.size(); ++i) {
        right_preorder.push_back(preorder[i]);
    }
    for(int i = 0; i < index; ++i) {
        left_inorder.push_back(inorder[i]);
    }
    for(int i = index+1; i < inorder.size(); ++i) {
        right_inorder.push_back(inorder[i]);
    }
    root->left = buildTree(left_preorder, left_inorder);
    root->right = buildTree(right_preorder, right_inorder);
    return root;
    }
};
