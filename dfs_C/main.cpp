#include <iostream>
#include <vector>

using namespace std;

static int edges;

void dfs_gdf(int num, const vector<vector<int>>& matr, vector<bool>& is_counted)
{
    is_counted[num] = true;

    for (int it : matr[num]) {
        ++edges;
        if(!is_counted[it])
            dfs_gdf(it, matr, is_counted);
    }
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>());
    vector<bool> is_counted(N);
    int counter = 0;
    int cur_value;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> cur_value;
            if(cur_value == 1)
                matrix[i].push_back(j);
        }
    }

    for (int i = 0; i < matrix.size(); ++i) {
        if(!is_counted[i]){
            ++counter;
            dfs_gdf(i, matrix, is_counted);
        }
    }

    if(counter == 1 && edges / 2 == N - 1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
