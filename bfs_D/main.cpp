#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool is_ok(int x, int y, int N, int M)
{
    return ( ((x < N) && (x > -1)) && ((y < M) && (y > -1)) );
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> matrix(N, vector<char>(M,'.'));
    queue<pair<int,int>> q;

    int dx[4]{1, -1, 0, 0};
    int dy[4]{0, 0, -1, 1};

    int counter = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char val;
            cin >> val;
            if(val == '#')
                matrix[i][j] = val;
        }
    }

    // обходим все поле, ищем не посещенные компоненты
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(matrix[i][j] == '#') {
                ++counter;
                q.push({i,j});
                matrix[i][j] = '?';

                // стандартный алгоритм BFS
                while (!q.empty()) {
                    pair<int,int> val = q.front();
                    q.pop();
                    for (int i = 0; i < 4; ++i) {
                        pair<int,int> cur_val = {val.first + dx[i], val.second + dy[i]};
                        if(is_ok(cur_val.first, cur_val.second, N, M) && matrix[cur_val.first][cur_val.second] == '#')
                        {
                            matrix[cur_val.first][cur_val.second] = '?';
                            q.push(cur_val);
                        }
                    }
                }
            }
        }
    }

    cout << counter;

    return 0;
}
