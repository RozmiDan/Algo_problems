#include <iostream>
#include <vector>

using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
{
    vector<int> result(queries.size());

    vector<int> pref_xor_nums(arr.size(), 0);
    pref_xor_nums[0] = arr[0];
    for (int i = 1; i < pref_xor_nums.size(); ++i) {
        pref_xor_nums[i] = pref_xor_nums[i-1] ^ arr[i];
    }

    for (int i = 0; i < queries.size(); ++i) {
        int l = queries[i][0];
        int r = queries[i][1];
        int cur_answ = pref_xor_nums[r];
        if(l - 1 >= 0)
            cur_answ ^= pref_xor_nums[l - 1];
        result[i] = cur_answ;
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    vector<vector<int>> queries(m, vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];}

    for (int i = 0; i < m; ++i) {
        cin >> queries[i][0] >> queries[i][1];}

    vector<int> result = xorQueries(nums, queries);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }

    return 0;
}
