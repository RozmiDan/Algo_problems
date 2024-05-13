#include <iostream>
#include <vector>

int main()
{
    int k, result = 0;
    std::cin >> k;
    std::vector<int> arr(k);
    std::vector<int> pref_arr(k+1, 0);

    for (int i = 0; i < arr.size(); ++i) {
        std::cin >> arr[i];
    }

    for (int i = 1; i < pref_arr.size(); ++i) {
        pref_arr[i] = pref_arr[i-1] + arr[i-1];
    }

    for (int i = 1; i < pref_arr.size(); ++i) {
        for (int j = i; j < pref_arr.size(); ++j) {
            if((j - i) % 2 == 0)
                result += pref_arr[j] - pref_arr[i-1];
        }
    }

    std::cout << result;

    return 0;
}
