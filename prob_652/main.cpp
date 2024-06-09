#include <iostream>
#include <map>
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
class Solution {
public:

    map<string, vector<TreeNode*>> table;

    string dfs_algo(TreeNode* node)
    {
        // для обеспчения отображения дерева полностью, необходимо хранить и нулевые ноды
        if(!node)
            return "?";

        // от каждой ноды про находим ее поддерево и записываем его в хэштаблицу
        string result = "[" + dfs_algo(node->left) + to_string(node->val) + dfs_algo(node->right) + "]";

        if(table[result].size() <= 1)
            table[result].push_back(node);

        return result;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> answer;
        dfs_algo(root);
        for(auto& it : table)
            if(it.second.size() > 1)
                answer.push_back(it.second[0]);

        return answer;
    }
};

int main()
{
//    map<string, vector<TreeNode*>> table;
//    for(auto& it : table)
//    {
//        if(it.second.size() > 1)
//            cout << " ";
//    }

    TreeNode a(23);
    TreeNode c(2);
    TreeNode q(65, &a, &c);
    cout << q.left->val;
    TreeNode w(3);
    TreeNode e(19);

    return 0;
}
