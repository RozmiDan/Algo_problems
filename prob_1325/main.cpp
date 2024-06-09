#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void dfs_algo(TreeNode* node, TreeNode* parent, int targ, bool side)
    {

        if(node->left)
            dfs_algo(node->left, node, targ, false);

        if(node->right)
            dfs_algo(node->right, node, targ, true);

        if(!node->left && !node->right  && node->val == targ) {
            if(side)
                parent->right = nullptr;
            else
                parent->left = nullptr;
        }

    }

    TreeNode* removeLeafNodes(TreeNode* root, int targ) {
        TreeNode* preroot = new TreeNode(23);
        preroot->right = root;

        dfs_algo(root, preroot, targ, true);
        if(preroot->right == nullptr)
            return nullptr;
        return root;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
