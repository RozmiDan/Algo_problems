#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long maxSum(vector<int>& nums, int m, int k) {

    unordered_map<int, int> uniq_elem;
    long long result = 0;
    long long summ_of_window = 0;

    for (int i = 0; i < k; ++i) {
        if(uniq_elem.find(nums[i]) != uniq_elem.end())
            ++uniq_elem[nums[i]];
        else
            uniq_elem[nums[i]] = 1;
        summ_of_window += nums[i];
    }

    if(uniq_elem.size() >= m)
        result = summ_of_window;

    for (int i = k; i < nums.size(); ++i) {

        summ_of_window += nums[i] - nums[i-k];
        --uniq_elem[nums[i-k]];

        if(uniq_elem[nums[i-k]] == 0)
            uniq_elem.erase(nums[i-k]);

        if(uniq_elem.find(nums[i]) != uniq_elem.end())
            ++uniq_elem[nums[i]];
        else
            uniq_elem[nums[i]] = 1;

        if(uniq_elem.size() >= m)
            result = max(summ_of_window, result);
    }

    return result;
}

int main()
{
    int sz, dist_elements, length_window;
    cin >> sz;

    std::vector<int> nums(sz);
    for (int i = 0; i < nums.size(); ++i) {
        cin >> nums[i];
    }

    cin >> dist_elements >> length_window;

    cout << maxSum(nums, dist_elements, length_window);


    return 0;
}
