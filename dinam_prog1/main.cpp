#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> costs(N+1, 0);
    vector<long long> res(N+1, 0);
    for (int i = 1; i < N+1; ++i) {
        cin >> costs[i];
    }

    res[1] = costs[1];
    res[2] = costs[2];

    for (int i = 3; i < N+1; ++i)
        res[i] = min(res[i-1], res[i-2]) + costs[i];

    cout << res[N];

    return 0;
}
