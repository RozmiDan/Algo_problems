#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool is_coord_ok(int x, int y, int N)
{
    return ((N > x) && (N > y)) && ((x > -1) && (y > -1));
}

int main()
{
    //возможные ходы коня
    int dx[8] {-2, -1, 1, 2,  2,  1, -1, -2};
    int dy[8] { 1,  2, 2, 1, -1, -2, -2, -1};

    //принимаем значения
    int N;
    pair<int, int> strt, fin;
    cin >> N >> strt.first >> strt.second >> fin.first >> fin.second;
    --strt.second;
    --strt.first;
    --fin.first;
    --fin.second;

    //инициализируем поле для подсчета кол-ва ходов до клетки graph[i][j]
    vector<vector<int>> graph(N, vector<int>(N, -1));
    queue<pair<int, int>> q;

    q.push(strt);
    graph[strt.first][strt.second] = 0;

    while (!q.empty())
    {
        pair<int,int> cur_val = q.front();
        q.pop();

        //берем текущую клетку и рассматриваем все варианты следующего хода
        for (int i = 0; i < 8; ++i) {
            pair<int,int> val = {cur_val.first + dx[i], cur_val.second + dy[i]};
            if(is_coord_ok(val.first, val.second, N) && graph[val.first][val.second] == -1)
            {
                graph[val.first][val.second] = graph[cur_val.first][cur_val.second] + 1;
                q.push(val);
            }
        }

    }

    cout << graph[fin.first][fin.second];

    return 0;
}
