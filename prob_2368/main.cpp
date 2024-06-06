#include <iostream>
#include <vector>

using namespace std;

int quant = 0;

void dfs_algo(vector<vector<int>>& matr, vector<bool>& counted, int cur_node)
{
    counted[cur_node] = true;
    quant += 1;

    for(auto& it : matr[cur_node])
    {
        if(!counted[it])
            dfs_algo(matr, counted, it);
    }
}

int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    vector<vector<int>> matrix(n, vector<int>());
    vector<bool> counted(n, false);
    for (auto& it : edges)
    {
        matrix[it[0]].push_back(it[1]);
        matrix[it[1]].push_back(it[0]);
    }
    for(int i = 0; i < restricted.size(); ++i)
    {
        counted[restricted[i]] = true;
    }

    dfs_algo(matrix, counted, 0);

    return quant;
}

int main()
{
    int n = 3;
    vector<vector<int>> matrix(n, vector<int>());

    return 0;
}
