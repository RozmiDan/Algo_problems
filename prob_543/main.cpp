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
    int res = 0;

    int diamHelper(TreeNode* node)
    {
        int left_len = 0;
        int right_len = 0;
        if(node->left)
            left_len = diamHelper(node->left);
        if(node->right)
            right_len = diamHelper(node->right);

        res = max(res, left_len + right_len );

        return max(left_len, right_len) + 1;

    }

    int diameterOfBinaryTree(TreeNode* root) {
        diamHelper(root);
        return res;
    }
};

int main()
{
    cout << "" << endl;
    return 0;
}
