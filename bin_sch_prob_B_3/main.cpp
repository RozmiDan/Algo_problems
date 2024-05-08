#include <iostream>
#include <vector>
#include <algorithm>

bool is_ok(std::vector<int>& arr, long long cur_sum_val, int sections)
{
    long long cur_sections = 1;
    long long sum_of_section = 0;

    for (int index = 0; index < arr.size(); ++index) {
        if(arr[index] + sum_of_section <= cur_sum_val)
        {
            sum_of_section += arr[index];
        }
        else {
            sum_of_section = arr[index];
            ++cur_sections;
        }

    }

    if(cur_sections <= sections)
        return true;
    return false;
}

int main()
{
    int quant_val, quant_section;
    std::cin >> quant_val >> quant_section;
    std::vector<int> arr(quant_val);

    for (int index = 0; index < quant_val; ++index) {
        std::cin >> arr[index];
    }

    long long result = 0;
    long long left_bound = *std::max_element(arr.begin(), arr.end());
    long long right_bound = 10e14;

    while(left_bound <= right_bound)
    {
        long long middle_bound = (right_bound + left_bound) / 2;
        if(is_ok(arr, middle_bound, quant_section))
        {
            right_bound = middle_bound - 1;
            result = middle_bound;
        } else {
            left_bound = middle_bound + 1;
        }
    }

    std::cout << result;

    return 0;
}
