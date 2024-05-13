#include <iostream>
#include <vector>

int main()
{
    int n, result;
    std::cin >> n;
    std::vector<int> pref_arr(n+1, 0);

    for (int i = 1; i <= n; ++i) {
        pref_arr[i] = i + pref_arr[i-1];
    }

    for (int i = 1; i < pref_arr.size(); ++i) {
        if(pref_arr[i] == pref_arr[n] - pref_arr[i-1]){
            std::cout << i;return 0;}
    }
    std::cout << "-1";


}
