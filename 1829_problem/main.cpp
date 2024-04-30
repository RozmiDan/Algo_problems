#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

unsigned findMaxK(unsigned x, int maxBit)
{
    for (size_t i = 0; i < maxBit; ++i) {
        if(x & (1<<i))
            x &= ~(1 << i);
        else
            x |= (1 << i);
    }
    return x;
}

vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
{
    size_t N = nums.size();
    vector<int> result(N, 0);
    vector<int> prefix_xor(N, 0);

    // create array of prefix xor elements
    prefix_xor[0] = nums[0];
    for (size_t index = 1; index < prefix_xor.size(); ++index) {
        prefix_xor[index] = nums[index] ^ prefix_xor[index-1];
    }

    // going through xor array and calculate max k
    for (int index = N - 1; index >= 0; --index) {
        result[N-1-index] = findMaxK(prefix_xor[index], maximumBit);
    }

    for (size_t index = 0; index < result.size(); ++index) {
        cout << result[index];
    }

    return result;
}

int main()
{
    vector<int> nums {0,1,1,3};
    getMaximumXor(nums,2);
    //cout << invertor(2,3);
    return 0;
}
