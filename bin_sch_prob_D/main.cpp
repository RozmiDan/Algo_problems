#include <iostream>
#include <algorithm>
#include <vector>

size_t left_bound_search(std::vector<int>& arr, int value)
{
    size_t result = 0;
    int left_bound = 0;
    int righ_bound = static_cast<int>(arr.size() - 1);

    while (left_bound <= righ_bound) {
        int middle_bound = (righ_bound + left_bound)/2;

        if(arr[static_cast<size_t>(middle_bound)] >= value)
        {
            righ_bound = middle_bound - 1;
            result = static_cast<size_t>(middle_bound);
        }
        else {
            left_bound = middle_bound + 1;
        }
    }

    return result;
}

size_t right_bound_search(std::vector<int>& arr, int value)
{
    size_t result = 0;
    int left_bound = 0;
    int righ_bound = static_cast<int>(arr.size() - 1);

    while (left_bound <= righ_bound) {
        int middle_bound = (righ_bound + left_bound)/2;

        if(arr[static_cast<size_t>(middle_bound)] <= value)
        {
            left_bound = middle_bound + 1;
            result = static_cast<size_t>(middle_bound);
        }
        else {
            righ_bound = middle_bound - 1;
        }
    }

    return result;
}

int main()
{
    size_t n, k;
    std::cin >> n;
    std::vector<int> arr(n);

    for (size_t index = 0; index < n; ++index) {
        std::cin >> arr[index];
    }

    std::sort(arr.begin(), arr.end());

    std::cin >> k;
    std::vector<int> res(k);

    for (size_t index = 0; index < k; ++index) {
        int l, r;
        std::cin >> l >> r;
        size_t R = right_bound_search(arr, r);
        size_t L = left_bound_search(arr, l);
        if(arr[L] >= l && arr[R] <= r)
            res[index] = static_cast<int>(R - L + 1);
        else
            res[index] = 0;
    }

    for (size_t index = 0; index < k; ++index) {
        std::cout << res[index] << " ";
    }

    return 0;
}
