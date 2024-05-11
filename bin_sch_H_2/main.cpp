#include <iostream>
#include <vector>
#include <algorithm>

bool is_ok(const int* arr_q, const int* arr_c, const int* arr_r
           , long long money, long long quant_burg)
{
    // мы должны просто сказать, можно ли будет сделать такое кол-во бургеров
    long long cost_br =  ((quant_burg * arr_r[0]) - arr_q[0]) * arr_c[0];
    long long cost_sos = ((quant_burg * arr_r[1]) - arr_q[1]) * arr_c[1];
    long long cost_ch =  ((quant_burg * arr_r[2]) - arr_q[2]) * arr_c[2];

    if(cost_br < 0)
        cost_br = 0;
    if(cost_sos < 0)
        cost_sos = 0;
    if(cost_ch < 0)
        cost_ch = 0;

    if(money - cost_br - cost_ch - cost_sos >= 0)
        return true;
    return false;
}

int main()
{
    std::string str;
    int quant_arr[3]; // br, sos, ch
    int cost_arr[3];
    int recept_arr[3]{0};
    long long money;

    std::cin >> str;
    std::cin >> quant_arr[0] >> quant_arr[1] >> quant_arr[2];
    std::cin >> cost_arr[0] >> cost_arr[1] >> cost_arr[2];
    std::cin >> money;

    for (int i = 0; i < str.size(); ++i)
    {
        if(str[i] == 'B')
            recept_arr[0] += 1;
        if (str[i] == 'S')
            recept_arr[1] += 1;
        if (str[i] == 'C')
            recept_arr[2] += 1;
    }

    long long left_bound = 0;
    long long righ_bound = 10e12;
    long long result = 0;

    while(left_bound <= righ_bound)
    {
        long long middle_bound = (left_bound + righ_bound) / 2;
        if(is_ok(quant_arr, cost_arr, recept_arr, money, middle_bound))
        {
            left_bound = middle_bound + 1;
            result = middle_bound;
        } else {
            righ_bound = middle_bound - 1;
        }
    }

    std::cout << result;

    return 0;
}
