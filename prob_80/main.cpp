#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int l_ptr = 0, counter = 0;

    for (int r_ptr = 0; r_ptr < nums.size(); ++r_ptr) {

        if(nums[r_ptr] == nums[l_ptr] && counter <= 2){
            l_ptr = r_ptr;
            counter++;}

        else if(nums[r_ptr] == nums[l_ptr] && counter > 2) {

        }
    }
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
