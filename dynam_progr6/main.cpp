#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N ;
    vector<vector<long long>> dp(N, vector<long long>(N, 0));

    for (int i = 0; i < N; ++i)
    {
        dp[i][i] = 1;
        dp[i][0] = 1;
    }

    for (int i = 2; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            if(dp[i][j] == 1)
                break;
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(dp[i][j] == 0)
                break;
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



//#include <iostream>
//#include <vector>

//using namespace std;

//int main()
//{
//    int N, M;
//    cin >> N >> M;
//    vector<vector<int>> dp(N, vector<int>(M, 0));

//    for (int i = 0; i < N; ++i)
//        dp[i][0] = 1;

//    for (int i = 0; i < M; ++i)
//        dp[0][i] = 1;

//    for (int i = 1; i < N; ++i) {
//        for (int j = 1; j < M; ++j) {
//            dp[i][j] = dp[i-1][j] + dp[i][j-1];
//        }
//    }

//    cout << dp[N-1][M-1];

//    return 0;
//}
