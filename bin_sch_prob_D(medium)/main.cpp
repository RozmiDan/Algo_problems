#include <iostream>
#include <vector>

long long person_possab_baloons(long long time_w, long long stamina, long long time_ch, long long cur_time)
{
    long long result = 0;

    long long block = (stamina * time_w) + time_ch;
    result = ((cur_time/block) * stamina) + (std::min((cur_time%block)/time_w ,stamina));

    return result;
}

int main()
{
    //time_work, time_chill, num_stamina
    long long num_baloons, num_helpers;
    std::cin >> num_baloons >> num_helpers;
    std::vector<long long>arr_time_work(num_helpers);
    std::vector<long long>num_stamina(num_helpers);
    std::vector<long long>time_chill(num_helpers);

    for (int index = 0; index < num_helpers; ++index) {
                        //time_work, time_chill, num_stamina
        std::cin >> arr_time_work[index] >> num_stamina[index] >> time_chill[index];
    }

    long long result = 0;
    long long left_bound = 0;
    long long right_bount = 10e16;
    while (left_bound <= right_bount)
    {
        long long count_baloons = 0;
        long long middle_bound = (right_bount + left_bound) / 2;
        for (int i = 0; i < num_helpers; ++i) {
            count_baloons += person_possab_baloons(arr_time_work[i], num_stamina[i],time_chill[i], middle_bound);
        }

        if(count_baloons >= num_baloons)
        {
            right_bount = middle_bound - 1;
            result = middle_bound;
        }
        else {
            left_bound = middle_bound + 1;
        }
    }
    std::cout << result << std::endl;

    for (int i = 0; i < num_helpers; ++i) {
        long long count = person_possab_baloons(arr_time_work[i], num_stamina[i], time_chill[i], result);
        std::cout << std::min(count, num_baloons) << " ";
        num_baloons -= count;
        if(num_baloons < 0)
            num_baloons = 0;
    }

    return 0;
}
