#include <iostream>
#include <cmath>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs_algo(TreeNode* root, int cur_val, int& answer)
{
    cur_val = (cur_val << 1) | root->val;

    if(root->left == nullptr && root->right == nullptr)
        answer += cur_val;

    if (root->left != nullptr)
        dfs_algo(root->left, cur_val, answer);

    if(root->right != nullptr)
        dfs_algo(root->right, cur_val, answer);
}

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int res_sum = 0;
        int cur_val = 0;
        dfs_algo(root, cur_val, res_sum);
        cout << res_sum;
    }
};

int main()
{
    Solution a;
    cout << a.sumRootToLeaf() << endl;
    return 0;
}



//class Solution {
//public:
//    int res_sum = 0;

//    void dfs_algo(TreeNode* root, int cur_val)
//    {
//        cur_val = cur_val * 2 + root->val;

//        if(root->left == nullptr && root->right == nullptr)
//            res_sum += cur_val;


//        if (root->left != nullptr) {
//            dfs_algo(root->left, cur_val);
//        }

//        if(root->right != nullptr)
//            dfs_algo(root->right, cur_val);
//    }

//    int sumRootToLeaf(TreeNode* root) {
//        int cur_val = 0;
//        dfs_algo(root, cur_val);
//        return res_sum;
//    }
//};




//class Solution {
//public:

//    void dfs_algo(TreeNode* root, int cur_val, int& answer, int counter)
//    {
//        cur_val += root->val * pow(2, counter);

//        if(root->left == nullptr && root->right == nullptr)
//            answer += cur_val;

//        else if (root->left != nullptr) {
//            dfs_algo(root->left, cur_val, answer, counter + 1);
//        }

//        else if(root->right != nullptr)
//            dfs_algo(root->right, cur_val, answer, counter + 1);
//    }

//    int sumRootToLeaf(TreeNode* root) {
//        int res_sum = 0;
//        int cur_val = 0;
//        int counter = 0;
//        dfs_algo(root, cur_val, res_sum, counter);
//        return res_sum;
//    }
//};




































