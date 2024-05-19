#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    long long sum, result = 0;
    cin >> n >> sum;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];}

    int l_ptr = 0;
    long long cur_sum = 0;
    for (int r_ptr = 0; r_ptr < arr.size(); ++r_ptr) {
        cur_sum += arr[r_ptr];
        while(cur_sum - arr[l_ptr] >= sum)
        {
            cur_sum -= arr[l_ptr];
            ++l_ptr;
        }
        if(cur_sum >= sum)
            if(l_ptr == 0)
                result += 1;
            else
                result += r_ptr - (r_ptr - l_ptr) + 1;
    }

    cout << result;

    return 0;
}
