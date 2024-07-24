#include <iostream>
#include <vector>
#include <stack>

using namespace std;

static const int maxv = 1e9;

int main()
{
    int N, sum;
    cin >> N;
    vector<int> val_of_money(N);
    for (int i = 0; i < N; ++i)
        cin >> val_of_money[i];
    cin >> sum;

    vector<int> dp(sum+1, maxv);
    vector<int> parent(sum+1, -1);
    dp[0] = 0;
    parent[0] = 0;

    for (int i = 1; i < dp.size(); ++i) {
        for (int j : val_of_money) {
            if(i - j >= 0 && dp[i] > dp[i-j] + 1) {
                dp[i] = dp[i-j] + 1;
                parent[i] = j; }
        }
    }

    stack<int> result;

    if(dp[sum] != maxv) {
        int i = sum;
        while(i > 0) {
            result.push(parent[i]);
            i = i-parent[i];
        }

        int cnt = result.size();
        for (int j = 0; j < cnt; ++j) {
            cout << result.top() << " ";
            result.pop();
        }

    } else {
        cout << "No solution";
    }

    return 0;
}
