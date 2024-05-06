#include <iostream>

bool is_ok(size_t width, size_t len, size_t num, long long cur_X)
{
    bool result = false;

    double val = (double)(cur_X/len)*(cur_X/width);

    if( val >= num)
        result = true;

    return result;
}

long long binary_search(size_t width, size_t len, size_t num)
{
    long long val_of_X = 0;
    long long left_bound = 0;
    long long right_bound = 1e18;

    while(left_bound <= right_bound)
    {
        long long middle_bound = (left_bound + right_bound) / 2;
        if(is_ok(width, len, num, middle_bound))
        {
            val_of_X = middle_bound;
            right_bound = middle_bound - 1;
        }
        else
            left_bound = middle_bound + 1;
    }

    return val_of_X;
}

int main()
{
    size_t width, len, num;
    std::cin >> width >> len >> num;

    std::cout << binary_search(width, len, num);

    return 0;
}
