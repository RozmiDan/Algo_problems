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

    bool res = false;

    void hasSumHelp(TreeNode* node, int targetSum, int cur_sum)
    {
        cur_sum += node->val;
        if((!node->right && !node->left) && cur_sum == targetSum)
             res = true;
        if(node->right)
            hasSumHelp(node->right, targetSum, cur_sum);
        if(node->left)
            hasSumHelp(node->left, targetSum, cur_sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        hasSumHelp(root, targetSum, 0);
        return res;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
