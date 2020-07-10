#include <iostream>
#include <stack>
#include <memory>
#include <climits>

using namespace std;


template <typename T>
class TreeNode
{
    public:
        TreeNode(T a):val(a), right(0), left(0)
        {
        }

        ~TreeNode()
        {
            cout << "Destroyed : TreeNode" << endl;
        }

        T val;
        TreeNode<T> *right;
        TreeNode<T> *left;
};

template <typename T>
class Tree
{
    public:
        Tree():root(0)
        {

        }

        ~Tree()
        {
            cout << "Destroyed : Tree" << endl;
        }

        void insertTreeNode(TreeNode<T> *rootnode, TreeNode<T> *leftnode = 0, TreeNode<T> *rightnode = 0)
        {
            if(!root)
            {
                root = rootnode;
                root->left = leftnode;
                root->right = rightnode;
            }
        }

        void inorderTreeTraversal(void)
        {
            cout << __func__ << " [ ";
            inorderTreeTraversalHelper(root);
            cout << " ]" << endl;
        }

        void preorderTreeTraversal(void)
        {
            cout << __func__ << " [ ";
            preorderTreeTraversalHelper(root);
            cout << " ]" << endl;
        }

        void postTreeTraversal(void)
        {
            cout << __func__ << " [ ";
            postTreeTraversalHelper(root);
            cout << " ]" << endl;
        }

        void depthFirstTraversal(void)
        {
            if(!root)
            {
                return;
            }

            stack<TreeNode<T>*> *s = new stack<TreeNode<T>*>;
            s->push(root);
            
            cout << __func__ << " [ ";
            
            while(!s->empty())
            {
                TreeNode<T> *n = s->top();
                s->pop();
                if(n->right)
                {
                    s->push(n->right);
                }
            
                if(n->left)
                {
                    s->push(n->left);
                }
                
                cout << n->val << " ";
            }

            delete s;
 
            cout << " ]" << endl;
        }

        bool isBst(void)
        {
            return isBstHelper(root, INT_MAX, INT_MIN);
        }

    private:
        TreeNode<T> * root;

        void inorderTreeTraversalHelper(TreeNode<T> *root)
        {
            if(!root)
            {
                return;
            }

            inorderTreeTraversalHelper(root->left);
            cout << root->val << " ";
            inorderTreeTraversalHelper(root->right);
        }

        void preorderTreeTraversalHelper(TreeNode<T> *root)
        {
            if(!root)
            {
                return;
            }

            cout << root->val << " ";
            preorderTreeTraversalHelper(root->left);
            preorderTreeTraversalHelper(root->right);
        }

        void postTreeTraversalHelper(TreeNode<T> *root)
        {
            if(!root)
            {
                return;
            }

            postTreeTraversalHelper(root->left);
            postTreeTraversalHelper(root->right);
            cout << root->val << " ";
        }

        bool isBstHelper(TreeNode<T> *root, T max, T min)
        {
            if(!root)
            {
                return true;
            }

            if(root->val < min || root->val >= max)
            {
                return false;
            }

            return isBstHelper(root->left, root->val, min) && isBstHelper(root->right, max, root->val);
        }
};

int main(int argc, char **argv)
{
    Tree<int> mytree;

    unique_ptr<TreeNode<int>> node = unique_ptr<TreeNode<int>>(new TreeNode<int>(10));
    unique_ptr<TreeNode<int>> right = unique_ptr<TreeNode<int>>(new TreeNode<int>(100));
    unique_ptr<TreeNode<int>> left = unique_ptr<TreeNode<int>>(new TreeNode<int>(25));

    mytree.insertTreeNode(node.get(), left.get(), right.get());

    mytree.inorderTreeTraversal();   
    mytree.preorderTreeTraversal();   
    mytree.postTreeTraversal();
    mytree.depthFirstTraversal();

    cout << "isBST() - " << mytree.isBst() << endl;
 
    return 0;
}



