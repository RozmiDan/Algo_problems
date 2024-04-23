#include <iostream>

using namespace std;

bool palinrom(int x)
{
    bool res = false;

    // remove options with minus n xxx0
    if(x < 0 || ((x%10 == 0) && x != 0))
    {}
    //
    else
    {
        //saving value x to compare in the end
        int origin_x = x;
        int palindrome = 0;

        while(x != 0)
        {
            int tmp_end = x % 10;
            x /= 10;
            palindrome =  palindrome * 10 + tmp_end;
        }

        palindrome == origin_x ? res = true : res = false;
    }
    return res;
}

int main()
{
    cout << palinrom(4340);
//    cout << "Hello World!" << endl;
    return 0;
}
