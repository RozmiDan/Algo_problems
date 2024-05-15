#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int, int> map;
    vector<int> res_vec(2);

    for(int i = 0; i < nums.size(); ++i)
    {
        int result = target - nums[i];
        if(map.find(result) != map.end())
        {
            res_vec[0] = i;
            res_vec[1] = map[result];
            break;
        }
        else
        {
            map[nums[i]] = i;
        }
    }

    return res_vec;
}

int main()
{
    int k, target;
    cin >> k >> target;
    vector<int> nums(k);

    for (int i = 0; i < k; ++i) {
        cin >> nums[i];
    }

    cout << twoSum(nums, target)[0] << " " << twoSum(nums, target)[1];

    return 0;
}
