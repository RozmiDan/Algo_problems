#include <iostream>

using namespace std;

int main()
{
    int n;
    long long coars, result = 0;
    cin >> n >> coars;
    string str;
    cin >> str;

    long long l_ptr = 0, cntr_a = 0, cntr_b = 0, cur_coars = 0;

    for (long long r_ptr = 0; r_ptr < n; ++r_ptr) {

        if(str[r_ptr] == 'a')
            ++cntr_a;
        else if(str[r_ptr] == 'b') {
            cur_coars += cntr_a;
            ++cntr_b; }

        while (cur_coars > coars) {

            if(str[l_ptr] == 'a'){
                --cntr_a;
                cur_coars -= cntr_b;}

            else if(str[l_ptr] == 'b')
                --cntr_b;
            ++l_ptr;
        }

        if(cur_coars <= coars)
            result = max(result, r_ptr - l_ptr + 1);
    }

    cout << result;
    return 0;
}
