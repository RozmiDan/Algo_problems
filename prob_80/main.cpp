#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int l_ptr = 1;
    for (int r_ptr = 1; r_ptr < nums.size(); ++r_ptr) {
        if(l_ptr == 1 || nums[r_ptr] != nums[r_ptr - 2])
            nums[l_ptr++] = nums[r_ptr];
    }
    return l_ptr;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums);

    for (int i = 0; i <= k; ++i) {
        cout << nums[i] << " ";
    }

    cout << "Hello World!" << endl;
    return 0;
}
