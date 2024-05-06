#include <iostream>

//int main()
//{
//    int n, x, y;
//    std::cin >> n >> x >> y;

//    double l_b = 0;
//    double r_b = 20e14;
//    long long result = 0;

//    while (l_b <= r_b)
//    {
//        long long m_b = (long long)(l_b + r_b) / 2;
//        long long cur_n = (long long)((m_b/x) + (r_b/y));
//        if(cur_n >= n - 1)
//        {
//            result = m_b;
//            r_b = m_b - 1;
//        }
//        else {
//            l_b = m_b + 1;
//        }
//    }

//    if(n == 1)
//        std::cout << std::min(x,y);
//    else {
//        std::cout << result + std::min(x,y);
//    }

//    return 0;
//}

bool is_ok(long long num, unsigned short x, unsigned short y, long long mid)
{
    long long cur_num_cpy = (mid / x) + (mid / y);
    if(cur_num_cpy >= num - 1)
        return true;
    return false;
}

#include <iostream>

int main()
{
    long long num_cpy;
    unsigned short x_sec_fst, y_sec_scnd;
    std::cin >> num_cpy >> x_sec_fst >> y_sec_scnd;

    long long result = 0;
    long long left_bound = 0;
    double right_bound = 20e16;

    while(left_bound <= right_bound)
    {
        long long middle_bound = (long long)((left_bound + right_bound) / 2);
        if(is_ok(num_cpy, x_sec_fst, y_sec_scnd, middle_bound))
        {
            result = middle_bound;
            right_bound = middle_bound - 1;
        } else {
            left_bound = middle_bound + 1;
        }
    }

    if(num_cpy == 1)
        std::cout << std::min(x_sec_fst, y_sec_scnd);
    else {
        std::cout << result + std::min(x_sec_fst, y_sec_scnd);
    }

    return 0;
}


