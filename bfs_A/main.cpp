#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> edges(N);
    queue<int> next_edge;
    vector<int> dist_edge(N, -1);
    int strt_val, fin_val;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int cur_val;
            cin >> cur_val;
            if(cur_val == 1)
                edges[i].push_back(j);
        }
    }
    cin >> strt_val >> fin_val;
    --strt_val;
    --fin_val;

    dist_edge[strt_val] = 0;
    next_edge.push(strt_val);

    while (!next_edge.empty())
    {
        int cur_val = next_edge.front();
        next_edge.pop();                //забрали из очереди значение
        for (int it : edges[cur_val]) {
            if(dist_edge[it] == -1) {
                next_edge.push(it);
                dist_edge[it] = dist_edge[cur_val] + 1;
            }

        }
    }

    cout << dist_edge[fin_val];

    return 0;
}
