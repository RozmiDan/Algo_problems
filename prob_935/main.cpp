#include <iostream>
#include <vector>

using namespace std;

static const long long mod = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> next_step{
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1,3},
        {2,4}
    };
    vector<long long> cur_raw(10, 1);
    cur_raw[0] = 0;
    cur_raw[8] = 0;
    vector<long long> prev_raw(10, 0);

    for (int i = 1; i < n; ++i) {
        prev_raw.swap(cur_raw);
        for (int j = 0; j < 10; ++j) {
            cur_raw[j] = 0;
            for(int x = 0; x < next_step[j].size(); ++x) {
                cur_raw[j] += prev_raw[next_step[j][x]];
                cur_raw[j] %= mod;
            }
        }
    }

    long long cum_val = 0;

    for(int i = 0; i < prev_raw.size(); ++i)
        cum_val += cur_raw[i];

    cout << cum_val % mod;

    return 0;
}
