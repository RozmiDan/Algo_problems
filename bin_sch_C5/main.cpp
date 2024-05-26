#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_ok(long long mid, long long k, vector<int>& fst_arr
                , vector<int>& scnd_arr)
{
    long long count_pairs = 0;
    for (int i = 0; i < fst_arr.size(); ++i) {
        long long cur_j = mid - fst_arr[i];
        long long right_bound = scnd_arr.size() - 1;
        long long left_bound = 0;
        long long cur_res = -1;
        while (left_bound <= right_bound)
        {
            long long mid_bound = (left_bound + right_bound) / 2;
            if(scnd_arr[mid_bound] <= cur_j)
            {
                left_bound = mid_bound + 1;
                cur_res = mid_bound;
            }
            else {
                right_bound = mid_bound - 1;
            }
        }
        count_pairs += cur_res + 1;
    }
    return count_pairs >= k;
}

int main()
{
    int n;
    long long k;
    cin >> n >> k;
    vector<int> nums_a(n), nums_b(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums_a[i]; }

    for (int i = 0; i < n; ++i) {
        cin >> nums_b[i]; }

    sort(nums_b.begin(), nums_b.end());

    long long left_bound = 0;
    long long right_bound = 2 * 10e9;
    long long result = 0;
    while (left_bound <= right_bound)
    {
        long long middle_bound = (right_bound + left_bound) / 2;
        if(is_ok(middle_bound, k, nums_a, nums_b))
        {
            right_bound = middle_bound - 1;
            result = middle_bound;
        }
        else {
            left_bound = middle_bound + 1;
        }
    }

    cout << result;
    return 0;
}
