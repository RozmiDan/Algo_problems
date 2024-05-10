#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

bool is_ok(double cur_x, double result_x)
{
    double cur_res = (cur_x * cur_x) + sqrt(cur_x);
    if(cur_res <= result_x)
        return true;
    return false;
}

int main()
{
    double result_val;
    std::cin >> result_val;

    double left_bound = 0;
    double right_bound = 10e8;
    double res = 0;

    for (int i = 0; i < 100; ++i)
    {
        double middle_bound = (right_bound + left_bound) / 2;
        if(is_ok(middle_bound, result_val))
        {
            res = middle_bound;
            left_bound = middle_bound;
        } else {
            right_bound = middle_bound;
        }
    }

    cout << std::setprecision(20) << res << endl;
    return 0;
}
