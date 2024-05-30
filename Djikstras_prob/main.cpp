#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX = 10e8;

int main()
{
    int N, S, F;
    cin >> N >> S >> F;
    vector<vector<pair<int,int>>> graph(N); // fst val - num, scnd val - weight
    vector<int> distances(N, MAX);
    set<pair<int, int>> set; //fst val - weight, scnd val - num of vertex

    --S;
    --F;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int val;
            cin >> val;
            if(val != -1)
                graph[i].push_back({j, val});
        }
    }

    distances[S] = 0;
    set.insert({distances[S], S});
    while (!set.empty())
    {
        int cur_val_vertex = set.begin()->second; // достаем значение наименьшей по расстоянию вершины
        set.erase(set.begin()); // сразу же удаляем ее
        for (int i = 0; i < graph[cur_val_vertex].size(); ++i) {
            // пересчитываем значение соседей от текущ точки
            int cur_dist = distances[cur_val_vertex] + graph[cur_val_vertex][i].second;
            int cur_val = graph[cur_val_vertex][i].first;
            // если получившееся раст меньше, заменяем его в массиве расст
            if(cur_dist < distances[cur_val])
            {
                set.erase({distances[cur_val] ,cur_val});
                distances[cur_val] = cur_dist;
                set.insert({distances[cur_val] ,cur_val});
            }
        }
    }

    if(distances[F] == MAX)
        cout << -1;
    else
        cout << distances[F];

    return 0;
}
