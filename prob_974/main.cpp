#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//int main()
//{
//    int sz, k;
//    cin >> sz >> k;
//    vector<int> nums(sz);
//    vector<int> pref_nums(nums.size() + 1, 0);

//    for (int i = 0; i < nums.size(); ++i) {
//        cin >> nums[i];
//    }

//    for (int i = 1; i < pref_nums.size(); ++i) {
//        pref_nums[i] = pref_nums[i-1] + nums[i-1];
//    }

//    int result = 0;
//    for (int i = 1; i < pref_nums.size(); ++i) {
//        for (int j = i; j < pref_nums.size(); ++j) {
//            if((pref_nums[j] - pref_nums[i-1]) % k == 0)
//                ++result;
//        }

//    }

//    cout << result;

//    return 0;
//}



int subarraysDivByK(vector<int>& nums, int k)
{
    int result = 0, cur_sum = 0;
    unordered_map<int, int> remainder;
    remainder[0] = 1;

    for (int i = 0; i < nums.size(); ++i)
    {
        cur_sum += nums[i];
        int remand = cur_sum % k;
        if(remand < 0)
            remand += k;
        if(remainder.find(remand) != remainder.end())
        {
            result += remainder[remand];
            ++remainder[remand];
        }
        else {
            remainder[remand] = 1;
        }
    }

    return result;
}

int main()
{
    int sz, k;
    cin >> sz >> k;
    vector<int> nums(sz);

    for (int i = 0; i < nums.size(); ++i) {
        cin >> nums[i];
    }

    cout << subarraysDivByK(nums, k);

    return 0;
}
