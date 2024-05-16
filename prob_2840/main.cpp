#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkStrings(string s1, string s2) {

    vector<char> even_s1;
    vector<char> even_s2;
    vector<char> odd_s1;
    vector<char> odd_s2;

    for (int i = 0; i < s1.size(); ++i) {
        if(i%2 == 0)
            even_s1.push_back(s1[i]);
        else
            odd_s1.push_back(s1[i]);
    }

    for (int i = 0; i < s2.size(); ++i) {
        if(i%2 == 0)
            even_s2.push_back(s2[i]);
        else
            odd_s2.push_back(s2[i]);
    }

    sort(even_s1.begin(), even_s1.end());
    sort(odd_s1.begin(), odd_s1.end());
    sort(even_s2.begin(), even_s2.end());
    sort(odd_s2.begin(), odd_s2.end());

    return (even_s1 == even_s2 && odd_s1 == odd_s2);

}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << checkStrings(s1,s2);

    return 0;
}
