#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10e8;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(N, MAX));

    for (int i = 0; i < M; ++i) {
        int fst_vert, scnd_vert, weight;
        cin >> fst_vert >> scnd_vert >> weight;
        matrix[--fst_vert][--scnd_vert] = weight;
        matrix[scnd_vert][fst_vert] = weight;
     }

    for (int x = 0; x < N; ++x) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                matrix[i][j] = min(matrix[i][j], matrix[i][x] + matrix[x][j]);
            }
        }
    }

    int res = MAX;
    int ans = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        int max_cur = 0;
        for (int j = 0; j < matrix.size(); ++j) {
            max_cur = max(max_cur, matrix[i][j]);
        }
        if(res > max_cur){
            res = max_cur;
            ans = i + 1;
        }
    }

    cout << ans;

    return 0;
}
