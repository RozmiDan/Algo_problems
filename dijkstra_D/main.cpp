#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9;

int dijkstra_algo(vector<vector<pair<int,int>>>& matr, int cost_last, int cost_fst)
{
    set<pair<int,int>> min_pair;
    vector<int> dist(matr.size(), INF);

    dist[0] = cost_fst;
    min_pair.insert({cost_fst,0});

    while (!min_pair.empty())
    {
        int val = min_pair.begin()->second;
        min_pair.erase(min_pair.begin());
        for (auto& it : matr[val])
        {
            int cur_val = it.second;
            int cur_dist = it.first + dist[val];
            if(cur_dist < dist[cur_val])
            {
                min_pair.erase({dist[cur_val], cur_val});
                dist[cur_val] = cur_dist;
                min_pair.insert({dist[cur_val], cur_val});
            }
        }
    }

    if(dist[matr.size() - 1] < 10e6)
        return dist[matr.size() - 1] - cost_last;
    else
        return -1;

}

int main()
{
    int n, m;
    cin >> n;

    vector<int> cost(n);
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    cin >> m;
    vector<vector<pair<int,int>>> matrix(n);
    int lst_cost = cost[n-1], fst_cost = cost[0];

    for (int i = 0; i < m; ++i) {
        int fst_val, scnd_val;
        cin >> fst_val >> scnd_val;
        --fst_val;
        --scnd_val;
        matrix[fst_val].push_back({cost[scnd_val], scnd_val});
        matrix[scnd_val].push_back({cost[fst_val], fst_val});
    }

    cout << dijkstra_algo(matrix, lst_cost, fst_cost);

    return 0;
}
