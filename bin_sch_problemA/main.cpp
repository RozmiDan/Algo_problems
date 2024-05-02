#include <iostream>
#include <vector>

using namespace std;

bool binary_search(vector<int>& arr, int value)
{
    int left_bound = 0;
    int right_bound = static_cast<int>(arr.size() - 1);
    int res_pos = 0;

    while(left_bound <= right_bound)
    {
        int middle_bound = (right_bound + left_bound) / 2;
        if(arr[static_cast<size_t>(middle_bound)] <= value)
        {
            left_bound = middle_bound + 1;
            res_pos = middle_bound;
        }
        else
            right_bound = middle_bound - 1;
    }
    if(arr[static_cast<size_t>(res_pos)] == value)
        return true;
    return false;
}

int main()
{
    size_t n,k;
    std::cin >> n >> k;
    vector<int> arr(n);
    int request ;

    for (size_t index = 0; index < n; ++index) {
        cin >> arr[index];
    }

    for (size_t index = 0; index < k; ++index) {
        cin >> request;
        if(binary_search(arr, request))
            std::cout << "YES" << endl;
        else
            std::cout << "NO" << endl;
    }

    //binary_search(arr, request);
    return 0;
}
