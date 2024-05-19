#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    long long sum, result = 0;
    cin >> n >> sum;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];}

    long long cur_sum = 0;
    int l_ptr = 0;
    for (int r_ptr = 0; r_ptr < arr.size(); ++r_ptr) {
        cur_sum += arr[r_ptr];
        while(cur_sum > sum)
        {
            cur_sum -= arr[l_ptr];
            ++l_ptr;
        }
        result += r_ptr - l_ptr + 1;
    }

    cout << result;

    return 0;
}
