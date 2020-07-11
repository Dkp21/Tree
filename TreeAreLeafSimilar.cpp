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
    
    void getLeaf(TreeNode *root, vector<int> & a)
    {
        if(!root)
        {
            return;
        }
        
        if(!root->left && !root->right)
        {
            a.push_back(root->val);
        }
        
        getLeaf(root->left,a);
        getLeaf(root->right,a);
    }
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    
        vector<int> a;
        getLeaf(root1, a);
        vector<int> b;
        getLeaf(root2, b);
        
        if(a.size() != b.size())
            return false;
        
        
        for(int i = 0; i < a.size(); ++i)
        {
            if(a.at(i) != b.at(i))
            {
                return false;
            }
        }
        
        return true;
    }
};
