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

    bool flag_symm = true;

    void dfs_algo(TreeNode* fst_node, TreeNode* scnd_node)
    {
        if(!fst_node && !scnd_node)
            return;

        if((fst_node && !scnd_node) || (!fst_node && scnd_node)) {
            flag_symm = false;
            return; }

        if(fst_node->val == scnd_node->val) {
            dfs_algo(fst_node->right, scnd_node->left);
            dfs_algo(fst_node->left, scnd_node->right); }
        else
            flag_symm = false;
    }

    bool isSymmetric(TreeNode* root) {
        dfs_algo(root->left, root->right);
        return flag_symm;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
