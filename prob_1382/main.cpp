#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs_algo(TreeNode* node, vector<int>& vals)
{
    if(node == nullptr)
        return;
    if(node->left)
        dfs_algo(node->left, vals);
    vals.push_back(node->val);
    if(node->right)
        dfs_algo(node->right, vals);
}

TreeNode* build_tree(int fst_ptr, int scnd_ptr, vector<int>& vals)
{
    if(fst_ptr > scnd_ptr)
        return 0;

    int mid = (fst_ptr + scnd_ptr) / 2;
    TreeNode* node = new TreeNode(vals[mid]);
    node->left = build_tree(fst_ptr, mid-1, vals);
    node->right = build_tree(mid+1, scnd_ptr, vals);
    return node;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> val_in_tree;
    dfs_algo(root, val_in_tree);
    return build_tree(0, val_in_tree.size() - 1, val_in_tree);
}
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
