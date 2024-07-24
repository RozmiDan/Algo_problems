#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> dp {1,2,4,0};

    if(N < 3)
    {
        cout << dp[N];
        return 0;
    }

    for (int i = 3; i <= N; ++i) {
        dp[3] = dp[1] + dp[2] + dp[0];
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[3];

    }
    cout << dp[3];

    return 0;
}
