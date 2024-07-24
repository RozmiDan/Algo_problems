#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int quant_item, cap_sack;
    cin >> quant_item >> cap_sack;
    vector<int> weight(quant_item+1,0);
    vector<int> cost(quant_item+1,0);

    for (int i = 1; i < weight.size(); ++i)
        cin >> weight[i];
    for (int i = 1; i < cost.size(); ++i)
        cin >> cost[i];

    vector<vector<int>> dp(quant_item+1, vector<int>(cap_sack+1, 0));

    for (int i = 1; i < quant_item+1; ++i) {
        for (int j = 1; j < cap_sack+1; ++j) {
            if(weight[i] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + cost[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    stack<int> result;

    int tmp = cap_sack;
    for (int i = quant_item; i > 0; --i) {
        if(dp[i][tmp] != dp[i-1][tmp]) {
            result.push(i);
            tmp -= weight[i]; }
    }

    int sz = result.size();
    for (int i = 0; i < sz; ++i) {
        cout << result.top() << endl;
        result.pop();
    }

    return 0;
}
