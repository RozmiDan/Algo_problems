#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int cntr = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(graph[i][j] == 1)
                ++cntr;
                graph[j][i] = 0;
        }
    }

    cout << cntr;

    return 0;
}
