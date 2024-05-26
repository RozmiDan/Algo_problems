#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

    sort(nums.begin(), nums.end());

    vector<int> pref_nums(nums.size() + 1, 0);
    vector<int> answer(queries.size());

    for (int i = 1; i < pref_nums.size(); ++i) {
        pref_nums[i] = pref_nums[i-1] + nums[i-1]; }

    for (int i = 0; i < queries.size(); ++i) {

        int left_bount = 0;
        int result = 0;
        int right_bound = pref_nums.size() - 1;
        while(left_bount <= right_bound)
        {
            int mid_bound = (right_bound + left_bount) / 2;
            if(pref_nums[mid_bound] <= queries[i])
            {
                left_bount = mid_bound + 1;
                result = mid_bound;
            }
            else {
                right_bound = mid_bound - 1;
            }
        }
        answer[i] = result;
    }
    return answer;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n), queries(m);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i]; }
    for (int i = 0; i < m; ++i) {
        cin >> queries[i]; }

    vector<int> result = answerQueries(nums, queries);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " "; }

    return 0;
}
