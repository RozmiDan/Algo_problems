#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

bool is_ok(int x, int y, int N)
{
    return ((x > -1 && x < N) && (y > -1 && y < N));
}

vector<vector<int>> bfs(vector<vector<char>>& matr, int st_x, int st_y
                        ,  vector<vector<pair<int,int>>>& dist_log)
{
    int n = matr.size();
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(n, INF));

    int dx[4] {0, 0, 1, -1};
    int dy[4] {1,-1, 0, 0};

    dist[st_x][st_y] = 0;
    dist_log[st_x][st_y] = {-1, -1};
    q.push({st_x, st_y});

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int cur_x = x + dx[i];
            int cur_y = y + dy[i];
            if(is_ok(cur_x, cur_y, n))
            {
                if((dist[cur_x][cur_y] > 1e8) && (matr[cur_x][cur_y] != 'O')) {
                    dist[cur_x][cur_y] = dist[x][y] + 1;
                    dist_log[cur_x][cur_y] = {x,y};
                    q.push({cur_x, cur_y});
                    //добав в очередь
                }
            }
        }
    }

    return dist;

}

int main()
{
    int N;
    cin >> N;

    vector<vector<pair<int,int>>> dist_log(N, vector<pair<int,int>>(N, {0,0}));
    vector<vector<char>> matrix(N, vector<char>(N, '.'));
    int strt_crd_x, strt_crd_y, fin_crd_x, fin_crd_y;


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
            if(matrix[i][j] == '@') {
                strt_crd_x = i;
                strt_crd_y = j; }
            if(matrix[i][j] == 'X') {
                fin_crd_x = i;
                fin_crd_y = j; }
        }
    }

    vector<vector<int>> res = bfs(matrix, strt_crd_x, strt_crd_y, dist_log);

    if(res[fin_crd_x][fin_crd_y] < 1e5) {
        cout << 'Y' << endl;
        pair<int,int> strt{-1, -1};
        int i = fin_crd_x;
        int j = fin_crd_y;
        while (dist_log[i][j] != strt) {
            auto cur_pair = dist_log[i][j];
            matrix[i][j] = '+';
            i = cur_pair.first;
            j = cur_pair.second;
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
    }
    else
        cout << 'N' << endl;

    return 0;
}
