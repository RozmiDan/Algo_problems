#include <iostream>
#include <vector>
#include <iomanip>

bool is_ok(std::vector<int>& arr, int res_quan, double cur_value)
{
    int cur_result = 0;

    for (size_t index = 0; index < arr.size(); ++index) {
        cur_result += (int)(arr[index] / cur_value);
    }

    if(cur_result >= res_quan)
        return true;
    return false;
}

double binary_search(std::vector<int>& arr, int res_quan)
{
    double result = 0;
    double left_bound = 0;
    double right_bound = 1e8;

    for (size_t index = 0; index < 100; ++index)
    {
        double middle_bound = (left_bound + right_bound) / 2;
        if(is_ok(arr, res_quan, middle_bound))
        {
            result = middle_bound;
            left_bound = middle_bound ;
        }
        else {
            right_bound = middle_bound ;
        }
    }

    return result;
}

int main()
{
    size_t quan;
    int res_quan;
    std::cin >> quan >> res_quan;
    std::vector<int> arr(quan);

    for (size_t index = 0; index < quan; ++index) {
        std::cin >> arr[index];
    }

    std::cout << std::setprecision(20) <<binary_search(arr, res_quan);

    return 0;
}



