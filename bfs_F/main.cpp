#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool is_ok(int x, int y, int n, int m)
{
    return ((x < n && x > -1)&&(y < m && y > -1));
}

vector<int> bfs(vector<vector<char>>& matr)
{
    vector<int> vec_count(3, 0); //count_ok, count_notok, count_dead
    queue<pair<int,int>> q;

    int dx[4]{0, 0, -1, 1};
    int dy[4]{1, -1, 0, 0};

    for (int i = 0; i < matr.size(); ++i) {
        for (int j = 0; j < matr[0].size(); ++j) {
            if(matr[i][j] != '-')
            {
                bool flag_X = false, flag_S = false;

                if(matr[i][j] == 'S')
                    flag_S = true;
                else
                    flag_X = true;

                q.push({i,j});
                matr[i][j] = '-';

                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; ++k) {
                        int cur_x = x + dx[k];
                        int cur_y = y + dy[k];
                        if( is_ok(cur_x, cur_y, matr.size(), matr[0].size()) && matr[cur_x][cur_y] != '-')
                        {
                            q.push({cur_x, cur_y});

                            if(matr[cur_x][cur_y] == 'S')
                                flag_S = true;
                            else
                                flag_X = true;

                            matr[cur_x][cur_y] = '-';
                        }
                    }

                }

                if(flag_S && flag_X)
                    ++vec_count[1];
                else if (flag_S && !flag_X)
                    ++vec_count[0];
                else if (!flag_S && flag_X)
                    ++vec_count[2];
            }
        }
    }

    return vec_count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> res = bfs(matrix);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }

    return 0;
}
