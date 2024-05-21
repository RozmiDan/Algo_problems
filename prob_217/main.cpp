#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(st.find(nums[i]) == st.end())
                st.insert(nums[i]);
            else
                return true;
        }
        return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << containsDuplicate(arr);
    return 0;
}
