#include <iostream>
#include <vector>
using namespace std;

void dfs_algo(vector<vector<pair<int,int>>>& matr, vector<bool>& used_vert
              , vector<bool>& used_edge, int cur_node)
{
    used_vert[cur_node] = true;
    for (auto& it : matr[cur_node])
    {
        int next_node = it.first;
        int next_edge = it.second;
        if(!used_vert[next_node])
        {
            used_edge[next_edge] = true;
            dfs_algo(matr, used_vert, used_edge, next_node);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> edges;
    vector<vector<pair<int,int>>> graph(N);

    for (int i = 0; i < M; ++i) {
        int fst_val, scnd_val;
        cin >> fst_val >> scnd_val;
        edges.push_back({fst_val, scnd_val});
        --fst_val;
        --scnd_val;
        graph[fst_val].push_back({scnd_val, edges.size() - 1});
        graph[scnd_val].push_back({fst_val, edges.size() - 1});
    }

    vector<bool> is_vizited_edge(M, false);
    vector<bool> is_vizited_vertex(N, false);

    dfs_algo(graph, is_vizited_vertex, is_vizited_edge, 0);

    for (int i = 0; i < is_vizited_edge.size(); ++i) {
        if(is_vizited_edge[i])
            cout << edges[i].first << " " << edges[i].second << endl;
    }

    return 0;
}
