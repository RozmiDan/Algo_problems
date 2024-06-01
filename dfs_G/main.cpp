#include <iostream>
#include <vector>

using namespace std;

const int dx[8]  {0,  0, 1, -1};
const int dy[8]  {1, -1, 0,  0};

bool is_ok(int x, int y, int n)
{
    return ((x < n && x > -1) && (y < n && y > -1));
}

void dfs_matrix(vector<vector<bool>>& matr, vector<vector<bool>>& enab, int x, int y, bool cur_color)
{
    enab[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int cur_x = x + dx[i];
        int cur_y = y + dy[i];
        if(is_ok(cur_x, cur_y, matr.size()))
        {
            if( ((cur_color + matr[cur_x][cur_y]) == 1) && (enab[cur_x][cur_y] == 0)) {
                dfs_matrix(matr, enab, cur_x, cur_y, matr[cur_x][cur_y]);
            }
        }
    }
}

int main()
{
    int n = 8;
    vector<vector<bool>> matrix(n, vector<bool>(n));
    vector<vector<bool>> is_enab(n, vector<bool>(n, false));
    int counter = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char val;
            cin >> val;
            if(val == 'W')
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(is_enab[i][j] != 1) {
                ++counter;
                dfs_matrix(matrix, is_enab, i, j, matrix[i][j]);
            }
        }
    }

    cout << counter;

    return 0;
}
