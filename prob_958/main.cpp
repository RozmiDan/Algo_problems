#include <iostream>
#include <queue>

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

    bool isCompleteTree(TreeNode* root) {

        bool flag_end = false;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(!node) {
                flag_end = true;
                continue; }

            if(node && !flag_end)
            {
                q.push(node->left);
                q.push(node->right);
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
