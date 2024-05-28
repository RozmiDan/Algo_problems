#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> arr_crossroads(N + 1, 0);
    int fst_crs, scnd_crs;
    for (int i = 0; i < M; ++i) {
        cin >> fst_crs >> scnd_crs;
        ++arr_crossroads[fst_crs];
        ++arr_crossroads[scnd_crs];
    }

    for (int i = 1; i < arr_crossroads.size(); ++i) {
        cout << arr_crossroads[i] << " ";
    }

    return 0;
}
