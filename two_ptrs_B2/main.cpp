#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, result = INT_MAX;
    long long sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];}

    long long cur_sum = 0;
    int l_ptr = 0;

    for (int r_ptr = 0; r_ptr < arr.size(); ++r_ptr) {
        cur_sum += arr[r_ptr];

        while(cur_sum - arr[l_ptr] >= sum)
        {
            cur_sum -= arr[l_ptr];
            ++l_ptr;
        }
        if(cur_sum >= sum)
            result = min(result, r_ptr - l_ptr + 1);

    }

    if(result == INT_MAX)
        result = -1;

    cout << result;

    return 0;
}
