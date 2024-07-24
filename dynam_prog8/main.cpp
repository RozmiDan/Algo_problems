#include <iostream>
#include <vector>

using namespace std;

bool is_ok(int x, int y, int n, int m)
{
    return ((x <= n && x >= 0) && (y <= m && y >= 0));
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<long long>> dp(n + 2, vector<long long>(m + 2, 0));

//    for (int i = 1; i < n + 1; ++i) {
//        for (int j = 1; j < m + 1; ++j) {
//            if(i == 1 || j == 1)
//                dp[i][j] = 1;
//        }
//    }

    dp[1][1] = 1;

    for (int i = 2; i < n + 1; ++i) {
        for (int j = 2; j < m + 1; ++j) {
            if(is_ok(i-1, j-2, n, m))
                dp[i][j] += dp[i-1][j-2];
            if(is_ok(i-2, j-1, n, m))
                dp[i][j] += dp[i-2][j-1];
            if(is_ok(i-2, j+1, n, m))
                dp[i][j] += dp[i-2][j+1];
            if(is_ok(i+1, j-2, n, m))
                dp[i][j] += dp[i+1][j-2];
        }
    }

    for(int i = 0; i < n+2; ++i) {
        for (int j = 0; j < m+2; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return 0;
}


//if( (i == 1 || i == n) && (j % 5 == 0) ) {
//    dp[i][j] = 1;
//    if(is_ok(i, j+1, n, m))
//        dp[i][j+1] = 1;
//}
//else if( (j == 1 || j == m) && (i % 5 == 0) ) {
//    dp[i][j] = 1;
//    if(is_ok(i, j+1, n, m))
//        dp[i+1][j] = 1;
//}
