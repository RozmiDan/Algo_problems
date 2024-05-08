#include <iostream>
#include <vector>

bool is_ok(std::vector<int>& arr, long long val_of_dist, int q_cows)
{
    long long cur_coord = 0;
    long long cur_cows = 1;

    for (int right_coord = 1; right_coord < arr.size(); ++right_coord)
    {
        if(arr[right_coord] - arr[cur_coord] < val_of_dist)
            continue;
        else {
            ++cur_cows;
            cur_coord = right_coord;
        }
    }
    return cur_cows >= q_cows;
}

int main()
{
    int quant_places, quant_of_cows;
    std::cin >> quant_places >> quant_of_cows;
    std::vector<int> arr_coordin(quant_places);

    for (int index = 0; index < quant_places; ++index) {
        std::cin >> arr_coordin[index];
    }

    long long result = 0;
    long long left_bound = 0;
    long long right_bound = 10e9;

    while (left_bound <= right_bound)
    {
        long long middle_bound = (right_bound + left_bound) / 2;
        if(is_ok(arr_coordin, middle_bound, quant_of_cows))
        {
            left_bound = middle_bound + 1;
            result = middle_bound;
        } else {
            right_bound = middle_bound - 1;
        }
    }

    std::cout << result;

    return 0;
}
