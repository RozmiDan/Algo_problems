#include <iostream>
#include <vector>

using namespace std;

vector<int> dfs_graph(int num, vector<vector<int>>& graph, vector<bool>& counted
               , vector<int>& nums_in_comp)
{
    nums_in_comp.push_back(num);
    counted[num] = true;

    for (int it : graph[num]) {
        if(!counted[it])
            dfs_graph(it, graph, counted, nums_in_comp);
    }

    return nums_in_comp;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N+1, vector<int>());
    vector<bool> is_counted(N+1, false);
    vector<vector<int>> result;

    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

//    for (int i = 1; i < graph.size(); ++i) {
//        for (int j = 0; j < graph[i].size(); ++j) {
//            cout << graph[i][j] << " ";
//        }
//        cout << endl;
//    }

    for (int i = 1; i < is_counted.size(); ++i) {
        if(is_counted[i] == 0) {
            vector<int> nums;
            result.push_back(dfs_graph(i, graph, is_counted, nums)); }
    }

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i].size() << endl;
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
