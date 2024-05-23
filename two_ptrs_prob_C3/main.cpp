#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, r;
    cin >> n >> r;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    long long result = 0;
    long long count = 0;
    int l_ptr = 0;

    for (int r_ptr = 1; r_ptr < nums.size(); ++r_ptr)
    {
        ++count;

        if(nums[r_ptr] - nums[l_ptr] > r) {
            result += nums.size() - count;
            ++l_ptr; }

        else if(nums[r_ptr] - nums[l_ptr] == r){
            result += nums.size() - (count + 1);
            ++l_ptr;}

        while (nums[r_ptr] - nums[l_ptr] > r) {
            result += nums.size() - count;
            ++l_ptr;
        }
    }

    cout << result;

    return 0;
}
