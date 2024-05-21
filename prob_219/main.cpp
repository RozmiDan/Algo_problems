#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    unordered_set<int> st;

    for (int i = 0; i < nums.size(); ++i) {
        if(i > k)
            st.erase(nums[i-(k+1)]);
        if(st.find(nums[i]) != st.end())
            return true;
        else
            st.insert(nums[i]);
    }

    return false;
}


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << containsNearbyDuplicate(arr, k);
    return 0;
}
