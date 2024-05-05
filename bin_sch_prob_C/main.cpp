#include <iostream>
#include <vector>

size_t binary_search(std::vector<int>& arr, int value)
{
    size_t result = 0;
    int left_bound = 0;
    int right_bound = static_cast<int>(arr.size() - 1);

    while (left_bound <= right_bound) {
        int middle_bound = (right_bound + left_bound)/2;
        if(arr[static_cast<size_t>(middle_bound)] >= value)
        {
            right_bound = middle_bound - 1;
            result = static_cast<size_t>(middle_bound);
        }
        else {
            left_bound = middle_bound + 1;
        }
    }

    if(value > arr[arr.size()-1])
        result = arr.size() + 1;
    else
        ++result;

    return result;
}

int main()
{
    size_t n,k;
    std::cin >> n >> k;

    std::vector<int> arr(n);

    for (size_t index = 0; index < n; ++index) {
        std::cin >> arr[index];
    }

    for (size_t index = 0; index < k; ++index) {
        int value;
        std::cin >> value;
        std::cout << binary_search(arr, value) << std::endl;
    }

    return 0;
}
