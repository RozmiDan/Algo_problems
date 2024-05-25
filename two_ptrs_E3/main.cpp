#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, sum_weight, weight, cost;
    cin >> n >> sum_weight;
    vector<int> arr_of_cost(n);
    vector<int> arr_of_weight(n);
    long long res_cost = 0;

    for (int i = 0; i < n; ++i) {
        cin >> arr_of_weight[i]; }

    for (int i = 0; i < n; ++i) {
        cin >> arr_of_cost[i]; }

    long long cur_cost = 0;
    long long cur_weight = 0;
    int l_ptr = 0;
    for (int r_ptr = 0; r_ptr < arr_of_weight.size(); ++r_ptr) {

        cur_weight += arr_of_weight[r_ptr];
        cur_cost += arr_of_cost[r_ptr];

        while (cur_weight > sum_weight) {
            cur_weight -= arr_of_weight[l_ptr];
            cur_cost -= arr_of_cost[l_ptr];
            ++l_ptr;
        }

        res_cost = max(cur_cost, res_cost);
    }

    cout << res_cost;
    return 0;
}
