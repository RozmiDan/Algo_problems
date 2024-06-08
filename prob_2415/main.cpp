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

    void dfs_algo(TreeNode* fst_node, TreeNode* scnd_node, int counter)
    {
        if(counter % 2 == 0)
        {
            int tmp = fst_node->val;
            fst_node->val = scnd_node->val;
            scnd_node->val = tmp;
        }
        if(fst_node->right) {
            dfs_algo(fst_node->left, scnd_node->right, counter + 1);
            dfs_algo(fst_node->right, scnd_node->left, counter + 1);
        } else {
            return;
        }
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        int cnt = 0;
        if(!root->left)
            return root;

        dfs_algo(root->left, root->right, cnt);
        return root;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
