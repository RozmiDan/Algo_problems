#include <iostream>
#include <vector>
#include <set>

using namespace std;

static int MAX = 10e8;

vector<int> dijkstra_algo(int N, int strt, int fin, vector<vector<pair<int,int>>>& graph)
{
    vector<int> dist(N, MAX);
    set<pair<int,int>> min_weight;
    vector<int> way_log(N, -1);

    way_log[strt] = strt;
    dist[strt] = 0;
    min_weight.insert({dist[strt], strt});

    while (!min_weight.empty())
    {
        int cur_vertex = min_weight.begin()->second;
        min_weight.erase(min_weight.begin());

        for (auto& it : graph[cur_vertex]) {
            int cur_val = it.second;
            int cur_dist = it.first + dist[cur_vertex];
            if(cur_dist < dist[cur_val])
            {
                min_weight.erase({dist[cur_val], cur_val});
                dist[cur_val] = cur_dist;
                way_log[cur_val] = cur_vertex;
                min_weight.insert({dist[cur_val], cur_val});
            }
        }
    }

    return way_log;
}

int main()
{
    int N, strt, fin;
    cin >> N >> strt >> fin;
    --strt;
    --fin;

    vector<int> answer;
    vector<vector<pair<int,int>>> matrix(N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int val;
            cin >> val;
            if(val != -1)
                matrix[i].push_back({val,j});
        }
    }

    vector<int> way = dijkstra_algo(N, strt, fin, matrix);

    int vertex = fin;
    if(way[fin] == -1)
        cout << way[fin];
    else {
        while( vertex != strt )
        {
            answer.push_back(vertex + 1);
            vertex = way[vertex];
        }
        answer.push_back(vertex + 1);

        for (int j = answer.size() - 1; j > -1; --j) {
            cout << answer[j] << " ";
        }
    }
    return 0;
}
