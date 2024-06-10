#include <iostream>

using namespace std;

bool isPalindrome(string s) {

    int l_ptr = 0;
    int r_ptr = s.size() - 1;

    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] > 64 && s[i] < 91)
            s[i] = s[i] + 32;
        else if((s[i] > 96 && s[i] < 123) || (s[i] > 47 && s[i] < 58))
            continue;
        else
            s[i] = ' ';
    }

    for (int i = 0; i < s.size(); ++i)
        cout << s[i];

    while(l_ptr < r_ptr)
    {
        if(s[l_ptr] == ' ') {
            ++l_ptr;
            continue; }
        else if(s[r_ptr] == ' ') {
            --r_ptr;
            continue; }
        else
            if(s[l_ptr] != s[r_ptr])
                return false;
        ++l_ptr;
        --r_ptr;
    }
    return true;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
