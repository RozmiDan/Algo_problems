#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
//    int n, m;
//    cin >> n >> m;
//    vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));

//    dp[1][1] = 1;

//    for (int i = 2; i <= n; i++) {
//        for (int j = 2; j <= m; j++) {
//            dp[i][j] = dp[i-1][j-2] + dp[i-2][j-1];
//        }
//    }

//    cout << dp[n][m];
//    return 0;
//}
    int N, M;
    cin >> N >> M;

//    if(N == 1 && M == 1) {
//        cout << 0;
//        return 0;
//    }

    vector<vector<long long>> dp(N+1, vector<long long>(M+1, 0));
    dp[1][1] = 1;

    for (int i = 2; i < N+1; ++i) {
        for (int j = 2; j < M+1; ++j) {
            dp[i][j] = dp[i-1][j-2] + dp[i-2][j-1];
        }
    }

//    for (int i = 0; i < N+1; ++i) {
//        for (int j = 0; j < M+1; ++j) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }

    cout << dp[N][M];
    return 0;
}
