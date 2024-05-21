#include <iostream>
#include <unordered_map>

using namespace std;

bool isIsomorphic(string s, string t)
{
    unordered_map<char, int> mp(26);
    unordered_map<char, int> mp_t(26);
    for (int i = 0; i < s.size(); ++i) {

        if(mp.find(s[i]) != mp.end())

            if(mp[s[i]] != s[i] - t[i])
                return false;
            else
                continue;
        else
            mp[s[i]] = s[i] - t[i];

        if(mp_t.find(t[i]) != mp_t.end())

        if(mp_t[t[i]] != t[i] - s[i])
            return false;
        else
            continue;
    else
        mp_t[t[i]] = t[i] - s[i];
    }

    return true;
}

int main()
{
    string s_str, t_str;
    cin >> s_str >> t_str;

    if(isIsomorphic(s_str, t_str))
        cout << "true";
    else {
        cout << "false";
    }
    return 0;
}
