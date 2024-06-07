#include <iostream>
#include <vector>
#include<stack>

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

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> values;
        stack<TreeNode*> q;

        if(!root)
           return values;

        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur_val = q.top();
            q.pop();
            values.push_back(cur_val->val);

            if(cur_val->right)
                q.push(cur_val->right);
            if(cur_val->left)
                q.push(cur_val->left);
        }
        return values;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
