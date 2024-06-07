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

    TreeNode* dfs_build(int fst_ptr, int scnd_ptr, vector<int>& nums)
    {
        if(fst_ptr > scnd_ptr)
            return NULL;

        int cur_max_ind = max_element(nums.begin() + fst_ptr, nums.begin() + scnd_ptr) - nums.begin();
        cout << cur_max_ind << " ";
        TreeNode* node = new TreeNode(nums[cur_max_ind]);
        node->left = dfs_build(fst_ptr, cur_max_ind-1, nums);
        node->right = dfs_build(cur_max_ind+1, scnd_ptr, nums);
        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs_build(0, nums.size()-1, nums);
    }
};

int main()
{
    vector<int> nums{2,8,1,6,7,0,21};
    Solution a;
    a.constructMaximumBinaryTree(nums);
    int res = max_element(nums.begin(), nums.end()) - nums.begin();
    cout << res;
    return 0;
}
