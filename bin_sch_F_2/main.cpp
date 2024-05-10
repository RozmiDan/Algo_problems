#include <iostream>
#include <vector>

bool is_ok(int cur_index, const std::string& orig, const std::string& res, const std::vector<int>& arr)
{
    int index_res = 0;

    std::vector<int> del_index(orig.size());
    for (int i = 0; i < cur_index; ++i) {
        del_index[arr[i] - 1] = 1;
    }

    for (int i = 0; i < orig.size(); ++i) {
        if(del_index[i])
            continue;
        if(index_res >= res.size())
            break;
        if(res[index_res] == orig[i])
            ++index_res;
    }

    return (index_res >= res.size());
}

int main()
{
    std::string origin_word, result_word;
    std::cin >> origin_word >> result_word;
    std::vector<int> arr_index(origin_word.size());

    for (int i = 0; i < arr_index.size(); ++i) {
        std::cin >> arr_index[i];
    }

    int left_bound = 0;
    int right_bound = arr_index.size() - 1;
    int result = 0;

    while(left_bound <= right_bound)
    {
        int middle_bound = (left_bound + right_bound) / 2;
        if(is_ok(middle_bound, origin_word, result_word, arr_index))
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
