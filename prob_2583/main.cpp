#include <iostream>
#include <vector>
#include <algorithm>

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

    void dfs_helper(TreeNode* node, int cur_lvl, vector<long long>& sums_level)
    {
        if(sums_level.size() < cur_lvl + 1)
            sums_level.push_back(node->val);
        else
            sums_level[cur_lvl] += node->val;

        if(node->left)
            dfs_helper(node->left, cur_lvl + 1, sums_level);

        if(node->right)
            dfs_helper(node->right, cur_lvl + 1, sums_level);

    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums_levl;
        dfs_helper(root, 0, sums_levl);
        if(k > sums_levl.size())
            return -1;
        else {
            sort(sums_levl.begin(), sums_levl.end(), [](long long a, long long b){return a > b;});
            return sums_levl[k-1];
        }
    }
};

int main()
{

    return 0;
}
