#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int val_num, val_quer;
    std:: cin >> val_num >> val_quer;

    std::vector<int> nums(val_num), queries(val_quer);
    std::vector<int> pref_sum(val_num + 1, 0), answer(val_quer);

    for (int i = 0; i < val_num; ++i) {
        std::cin >> nums[i];
    }

    for (int i = 0; i < val_quer; ++i) {
        std::cin >> queries[i];
    }

    std::sort(nums.begin(), nums.end());

    for (int i = 1; i < pref_sum.size(); ++i) {
        pref_sum[i] = pref_sum[i-1] + nums[i-1];
    }

    for (int i = 0; i < val_quer; ++i) {
        int index = 0;
        for (int j = 0; j < pref_sum.size(); ++j) {
            if(queries[i] >= pref_sum[j])
                index = j;
            else
                break;
        }
        answer[i] = index;
    }

    for (int i = 0; i < answer.size(); ++i) {
        std::cout << answer[i] << " ";
    }

    return 0;
}
