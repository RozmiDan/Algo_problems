#include <iostream>
#include <vector>

using namespace std;

long long maximumOr(vector<int>& nums, int k) {

    vector<int> pref_nums(nums.size());
    vector<int> suf_nums(nums.size());
    suf_nums[nums.size() - 1] = nums[nums.size() - 1];
    pref_nums[0] = nums[0];

    long long result = 0;

    for (int i = 1; i < pref_nums.size(); ++i) {
        pref_nums[i] = pref_nums[i-1] | nums[i]; }

    for (int i = nums.size() - 2; i >= 0; --i) {
        suf_nums[i] = suf_nums[i+1] | nums[i]; }

    for (int i = 0; i < nums.size(); ++i)
    {
        long long new_res = nums[i] * (1 << k);
        if(i + 1 < nums.size())
            new_res |= suf_nums[i+1];
        if(i - 1 >= 0)
            new_res |= pref_nums[i-1];

        result = max(result, new_res);
    }

    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int>nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i]; }

    cout << maximumOr(nums, k);

    return 0;
}
