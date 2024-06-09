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
    const long long MAX = 1e12;
    const long long MIN = -1e12;

    bool dfs_algo(TreeNode* node, long long min_val, long long max_val)
    {
        if(!node)
            return true;

        if(node->val <= min_val || node->val >= max_val)
            return false;

        // переходя в следующую ноду, мы оставляем одну из границ прежней от родительской ноды
        // в зависиомсти от стороны, заменяем правую или левую границу родительским значением
        bool res_lft = dfs_algo(node->left, min_val, node->val);
        bool res_rght = dfs_algo(node->right, node->val, max_val);

        return res_lft && res_rght;
    }

    bool isValidBST(TreeNode* root) {
        return dfs_algo(root, MIN, MAX);
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}




// Первоначальная идея рекурсивного обхода
// идея в том, чтобы от каждой ноды запускать рекурсивный поиск
// поиск минимума и максимума, и сравнивать их с текущим значением

//class Solution {
//public:
//    const int MAX = 1e9;
//    const int MIN = -1e9;
//    bool valid_flag = true;

//    int dfs_algo(TreeNode* node, bool side)
//    {
//        if(!node && side)
//            return MIN;
//        if(!node && !side)
//            return MAX;

//        int max_val_lft = dfs_algo(node->left, false); // 3    MAX
//        int min_val_rght = dfs_algo(node->right, true); // 7    MIN

//        if(node->val <= min_val_rght || node->val >= max_val_lft)
//            valid_flag = false;

//        if(side)
//            return min(node->val, max_val_lft);
//        else
//            return max(node->val, min_val_rght);
//    }

//    bool isValidBST(TreeNode* root) {
//        dfs_algo(root, false);
//        return valid_flag;
//    }
//};
