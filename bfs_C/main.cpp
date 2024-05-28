#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> grahp(N, vector<int>(N, 0));
    int counter = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grahp[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(grahp[i][j] == 1)
            {
                ++counter;
                grahp[j][i] = 0;
            }
        }
    }

    if(counter == N - 1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
