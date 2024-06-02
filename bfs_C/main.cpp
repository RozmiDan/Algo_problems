#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1e8;

bool is_ok(int x, int y, int N, int M)
{
    return ((x > -1 && x < N) && (y > -1 && y < M));
}

void bfs_algo(vector<vector<int>>& result, vector<pair<int,int>>& points)
{
    int n = result.size();
    int m = result[0].size();
    queue<pair<int,int>> q;

    int dx[4] {1, -1, 0, 0};
    int dy[4] {0, 0, -1, 1};

    // добавляем все стартовые точки в очередь, чтобы одновременно запустить в них поиск
    for (auto& it : points) {
        result[it.first][it.second] = 0;
        q.push({it.first, it.second});
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int cur_x = x + dx[i];
            int cur_y = y + dy[i];
            if(is_ok(cur_x, cur_y, result.size(), result[0].size()) && result[cur_x][cur_y] > 10e4)
            {
                result[cur_x][cur_y] = result[x][y] + 1;
                q.push({cur_x, cur_y});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> res(n, vector<int>(m, MAX));
    vector<pair<int,int>> point;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool val;
            cin >> val;
            if(val)
                point.push_back({i,j});
        }
    }

    bfs_algo(res, point);

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
                cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
