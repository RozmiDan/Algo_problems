#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> dijkstra_algo(vector<vector<pair<int,int>>>& graph, int strt_num)
{
    vector<int> dist(graph.size(), 2009000999);
    set<pair<int,int>> cur_min_val;

    dist[strt_num] = 0;
    cur_min_val.insert({dist[strt_num], strt_num});

    while (!cur_min_val.empty())
    {
        int cur_val = cur_min_val.begin()->second;
        cur_min_val.erase({dist[cur_val], cur_val});

        for (auto& it : graph[cur_val]) {
            int it_val = it.second;
            int it_dist = dist[cur_val] + it.first;
            if(it_dist < dist[it_val])
            {
                cur_min_val.erase({dist[it_val], it_val});
                dist[it_val] = it_dist;
                cur_min_val.insert({dist[it_val], it_val});
            }
        }
    }

    return dist;
}

int main()
{
    int quant_vert, quant_edg, srtr_vert;
    cin >> quant_vert >> quant_edg >> srtr_vert;

    vector<vector<pair<int,int>>> matrix(quant_vert); // fst - weight, scnd - num

    for (int i = 0; i < quant_edg; ++i) {
            int val_fst, val_scnd, val_thd;
            cin >> val_fst >> val_scnd >> val_thd;
            matrix[val_fst].push_back({val_thd, val_scnd});
            matrix[val_scnd].push_back({val_thd, val_fst});
    }

    vector<int> answer = dijkstra_algo(matrix, srtr_vert);

    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }

    return 0;
}
