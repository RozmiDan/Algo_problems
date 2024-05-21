#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> distance(vector<int>& nums) {

    vector<long long> res(nums.size());

    res[i] = cur_sum;

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];}

    vector<long long> res = distance(nums);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";}

    return 0;
}



//vector<long long> distance(vector<int>& nums) {

//    using int_pair = std::pair<int,int>;

//    unordered_multimap<int, int> map_pos;
//    vector<long long> res(nums.size());

//    for (int i = 0; i < nums.size(); ++i) {
//        map_pos.insert(int_pair(nums[i], i));
//    }

//    for (int i = 0; i < nums.size(); ++i) {
//        long long cur_sum = 0;
//        auto range = map_pos.equal_range(nums[i]);
//        for (auto it = range.first; it != range.second; ++it)
//        {
//            if(it->second != i)
//                cur_sum += abs(i-it->second);
//        }
//        res[i] = cur_sum;
//    }

//    return res;
//}
