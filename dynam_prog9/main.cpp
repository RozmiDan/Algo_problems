#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> coord(N);
    vector<long long> res_len(N, 0);

    for (int i = 0; i < N; ++i)
        cin >> coord[i];

    sort(coord.begin(), coord.end());

    if(N == 2) {
        cout << coord[1] - coord[0];
        return 0; }

    res_len[0] = 0;
    res_len[1] = coord[1] - coord[0];
    res_len[2] = coord[2] - coord[0];

    for (int i = 3; i < N; ++i)
        res_len[i] = min(res_len[i-1] + coord[i] - coord[i-1], res_len[i-2] + coord[i] - coord[i-1]);

    cout << res_len[res_len.size()-1] << " ";


    return 0;
}
