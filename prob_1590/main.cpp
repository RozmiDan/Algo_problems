#include <iostream>
#include <vector>

using namespace std;

int minSubarray(vector<int>& nums, int p)
{
    vector<int> pref_nums(nums.size()+1, 0);
    for (int i = 1; i < pref_nums.size(); ++i) {
        pref_nums[i] = pref_nums[i-1] + nums[i-1];}



    return result;
}

int main()
{
    int n, p;
    cin >> n >> p;
    vector<int> nums(n);

    cout << minSubarray(nums, p);
    return 0;
}
