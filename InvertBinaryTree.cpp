/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Input:
 *
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 *
 * Output:
 *
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 *
 *
 *
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(!root)
            return nullptr;
        
        invertTree(root->right);
        invertTree(root->left);
        
        if(root)
        {
            TreeNode *n = root->right;
            root->right = root->left;
            root->left = n;
        }
        
        return root;
    }
};
