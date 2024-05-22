#include <iostream>

using namespace std;

bool backspaceCompare(string s, string t) {

    int counter = 0;
    string res_s, res_t;
    for (int i = s.size()-1; i >= 0; --i) {
        if(counter == 0 && s[i] != '#')
            res_s.push_back(s[i]);
        else if (s[i] == '#') {
            ++counter;
        }
        else {
            --counter;
        }
    }

    counter = 0;

    for (int i = t.size()-1; i >= 0; --i) {
        if(counter == 0 && t[i] != '#')
            res_t.push_back(t[i]);
        else if (t[i] == '#') {
            ++counter;
        }
        else {
            --counter;
        }
    }

    return res_s == res_t;

}

int main()
{
    string str_s, str_t;
    cin >> str_s >> str_t;


    cout << backspaceCompare(str_s, str_t);
    return 0;
}
