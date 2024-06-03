#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool is_ok(int x, int y, int n, int m)
{
    return ( (x < n && x > -1) && (y < m && y > -1));
}

int bfs(vector<vector<char>>& matr)
{
    int n = matr.size();
    int m = matr[0].size();
    int counter = 0;
    queue<pair<int,int>> q;

    int dx[4]{0, 0, 1, -1};
    int dy[4]{-1, 1, 0, 0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(matr[i][j] == '*')
            {
                q.push({i,j});
                matr[i][j] = '?';
                ++counter;

                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        int cur_x = x + dx[k];
                        int cur_y = y + dy[k];
                        if(is_ok(cur_x, cur_y, matr.size(), matr[0].size()) && matr[cur_x][cur_y] == '*')
                        {
                            matr[cur_x][cur_y] = '?';
                            q.push({cur_x, cur_y});
                        }
                    }
                }
            }
        }
    }
    return counter;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m, '.'));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char symb;
            cin >> symb;
            if(symb == '*')
                matrix[i][j] = symb;
        }
    }

    int res = bfs(matrix);

    cout << res;

    return 0;
}
