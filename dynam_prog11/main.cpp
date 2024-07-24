#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> M >> N;
    vector<int> weight(N);
    vector<int> dp(M + 1);
    for (int i = 0; i < N; ++i)
        cin >> weight[i];
    dp[0] = 1;

    for (int i : weight) {
        for (int j = M; j >= i; --j) {
            if(dp[j-i] == 1)
                dp[j] = 1;
        }
    }

    for (int i = M; i >= 0; --i) {
        if(dp[i] != 0){
            cout << i;
            break; }
    }

    return 0;
}
