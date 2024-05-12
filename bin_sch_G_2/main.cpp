#include <iostream>
#include <vector>

bool is_ok(long long cur_quant_org, std::vector<long long>& arr_st_q
           , short quant_stud_in_org)
{
    long long quan_student = 0;

    for (int i = 0; i < arr_st_q.size(); ++i) {
        quan_student += std::min(cur_quant_org, arr_st_q[i]);
    }

    return quan_student >= (quant_stud_in_org * cur_quant_org);
}

int main()
{
    // будем бинарить кол-во студсоветов
    short quant_stud_org, quant_of_groups;
    std::cin >> quant_stud_org >> quant_of_groups;
    std::vector<long long> arr_stud_in_group(quant_of_groups);

    for (int i = 0; i < quant_of_groups; ++i) {
        std::cin >> arr_stud_in_group[i];
    }

    long long left_bound = 0;
    long long right_bound = 10e8;
    long long result = 0;

    while(left_bound <= right_bound)
    {
        long long middle_bound = (right_bound + left_bound) / 2;
        if(is_ok(middle_bound, arr_stud_in_group, quant_stud_org))
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
