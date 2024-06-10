#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {

    int count = nums.size();
    int lft_ptr = 0;
    int rght_ptr = nums.size() - 1;
    while (lft_ptr <= rght_ptr)
    {
        if(nums[lft_ptr] != val)
            ++lft_ptr;
        else if(nums[rght_ptr] == val) {
            --rght_ptr;
            --count;
        }
        else {
            nums[lft_ptr] = nums[rght_ptr];
            nums[rght_ptr] = val;
            ++lft_ptr;
            --rght_ptr;
            --count;
        }
    }
    return count ;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    int res = removeElement(vec, k);
    for (int i = 0; i < res; ++i) {
        cout << vec[i] << " ";
    }
    return 0;
}


