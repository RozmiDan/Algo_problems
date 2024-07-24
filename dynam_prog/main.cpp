#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> costs(N+1);
    vector<int> res(N+1);
    for (int i = 1; i < N+1; ++i)
        cin >> costs[i];

    res[0] = costs[0];
    res[1] = costs[1];
    res[2] = costs[2];

    for (int i = 3; i < N+1; ++i)
    {
        if(res[i-1] > res[i-2])
            res[i] = res[i-1] + costs[i];
        else
            res[i] = res[i-2] + costs[i];
    }
    cout << res[N];

    return 0;
}

//if(res[i-1] >= 0 && res[i-2] >= 0)
//    res[i] = res[i-1] + costs[i];
//else
//    res[i] = max(res[i-1], res[i-2]) + costs[i];
