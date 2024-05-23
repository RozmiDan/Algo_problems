#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    long long s;
    cin >> n >> s;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i]; }

    long long result = 0;
    long long cur_sum = 0;
    int l_ptr = 0;
    for (int r_ptr = 0; r_ptr < nums.size(); ++r_ptr) {

        cur_sum += nums[r_ptr];

        while(cur_sum > s) {
            cur_sum -= nums[l_ptr];
            ++l_ptr;}

        long long n = r_ptr - l_ptr + 1;
        result += (n * (n + 1)) / 2;
    }

    cout << result;

    return 0;
}
