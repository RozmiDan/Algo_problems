#include <iostream>
#include <vector>

using namespace std;

const int dx[4] {1, -1, 0, 0};
const int dy[4] {0, 0, -1, 1};

bool is_ok(int x, int y, int N, int M)
{
    return ((x < N && x > -1) && (y < M && y > -1));
}

void dfs_matr(vector<vector<char>>& matr, int x, int y)
{
    matr[x][y] = '?';
    for (int i = 0; i < 4; ++i) {
        if( is_ok(x+dx[i], y+dy[i], matr.size(), matr[0].size()) )
        {
            if(matr[x+dx[i]][y+dy[i]] == '#')
                dfs_matr(matr, x+dx[i], y+dy[i]);
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> matrix(N, vector<char>(M,'.'));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char val;
            cin >> val;
            if(val == '#')
                matrix[i][j] = val;
        }
    }



    int counter = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(matrix[i][j] == '#'){
                ++counter;
                dfs_matr(matrix, i, j);
            }
        }

    }


    cout << counter;
    return 0;
}
