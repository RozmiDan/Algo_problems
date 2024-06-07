#include <iostream>
#include <set>

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

    set<int> uniq_elem;
    bool flag = false;

    void bfs_algo(TreeNode* node, int k)
    {
        if(uniq_elem.find(k - node->val) != uniq_elem.end())
        {
            flag = true;
            return;
        }

        uniq_elem.insert(node->val);
        if(!node->right && !node->left)
            return;
        if(node->right)
            bfs_algo(node->right, k);
        if(node->left)
            bfs_algo(node->left, k);
    }

    bool findTarget(TreeNode* root, int k) {
        bfs_algo(root, k);
        return flag;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
