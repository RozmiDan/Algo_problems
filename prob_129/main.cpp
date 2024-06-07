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

    int res_sum = 0;

    void dfs_algo(TreeNode* node, int cur_num)
    {
        if(node->right)
            dfs_algo(node->right, cur_num * 10 + node->val);
        if(node->left)
            dfs_algo(node->left, cur_num * 10 + node->val);
        if(!node->left && !node->right) {
            cur_num = cur_num * 10 + node->val;
            res_sum += cur_num; }
    }


    int sumNumbers(TreeNode* root) {
        dfs_algo(root, 0);
        return res_sum;
    }
};


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
