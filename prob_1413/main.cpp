#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    std::vector<int> prefix_nums(nums.size() + 1, 0);

    for (int i = 0; i < nums.size(); ++i) {
        std::cin >> nums[i];
    }

    for (int i = 1; i < prefix_nums.size(); ++i) {
        prefix_nums[i] = prefix_nums[i-1] + nums[i-1];
    }

    int result = *std::min_element(prefix_nums.begin(), prefix_nums.end());
    if(result >= 0)
        std::cout << 1;
    else {
        std::cout << abs(result) + 1;
    }

    return 0;
}
