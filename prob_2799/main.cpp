#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countCompleteSubarrays(vector<int>& nums) {
    int result = 0;
    unordered_set<int> count_dist;
    unordered_set<int> cur_count;

    for (int i = 0; i < nums.size(); ++i)
        count_dist.insert(nums[i]);

    for (int i = 0; i < nums.size(); ++i) {
        cur_count.clear();
        for (int j = i; j < nums.size(); ++j) {
            cur_count.insert(nums[j]);
            if(cur_count.size() == count_dist.size())
                result += 1;
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << countCompleteSubarrays(arr);

    return 0;
}
