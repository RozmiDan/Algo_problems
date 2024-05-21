#include <iostream>
#include <map>

using namespace std;

bool isAnagram(string s, string t) {
    map<char, int> mp;
    for(int i = 0; i < s.size(); ++i)
    {
        if(mp.find(s[i]) == mp.end())
            mp[s[i]] = 1;
        else
            mp[s[i]] += 1;
    }

    for(int i = 0; i < t.size(); ++i)
    {
        if(mp.find(t[i]) == mp.end())
            return false;
        else
            mp[t[i]] -= 1;
            if(mp[t[i]] == 0)
                mp.erase(t[i]);
    }
    if(mp.size() > 0)
        return false;
    return true;
}

int main()
{
    string str_s, str_t;
    cin >> str_s >> str_t;
    cout << isAnagram(str_s, str_t);
    return 0;
}
