#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int cnt_verticlas, cnt_edges;
    cin >>  cnt_verticlas >> cnt_edges;
    vector<vector<int>> graph(cnt_verticlas + 1, vector<int>());

    int cur_fstvert, cur_scndvert;

    for (int i = 0; i < cnt_edges; ++i) {
        cin >> cur_fstvert >> cur_scndvert;
        graph[cur_fstvert].push_back(cur_scndvert);
    }

    cout << cnt_verticlas << endl;
    for (int i = 1; i < graph.size(); ++i) {
        cout << graph[i].size() << " ";
        for (int j = 0; j < graph[i].size(); ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
