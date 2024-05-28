#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt_edges = 0;
    vector<vector<int>> graph(N, vector<int>());
    int cur_way;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> cur_way;
            if(cur_way == 1) {
                graph[i].push_back(j);
                ++cnt_edges; }
        }
    }

    cout << N << " " << cnt_edges << endl;

    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            cout << i + 1 << " " << graph[i][j] + 1 << endl;
        }
    }

    return 0;
}
