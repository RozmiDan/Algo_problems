#include <iostream>
#include <vector>

using namespace std;

vector<int> shortestToChar(string s, char c) {

    vector<int> result(s.size()), index_of_c;
    int l_ptr = 0;

    for (int r_ptr = 0; r_ptr < s.size(); ++r_ptr) {
        if(s[r_ptr] == c)
            index_of_c.push_back(r_ptr);}

    for (int i = 0; i < s.size(); ++i) {
        int min_way = abs(index_of_c[0] - i);
        for (int j = 1; j < index_of_c.size(); ++j) {
            min_way = min(min_way, abs(index_of_c[j] - i));
        }
        result[i] = min_way;
    }

    return result;

}

int main()
{
    string str;
    char character;
    cin >> str >> character;

    vector<int> res = shortestToChar(str, character);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }

    return 0;
}

int l_ptr = 0, r_ptr = 0;

//for (int r_ptr = 0; r_ptr < s.size(); ++r_ptr) {
//    if(s[r_ptr] == c)
//    {
//        for (int i = l_ptr; i <= r_ptr; ++i) {
//            if(l_ptr == 0)
//                result[i] = r_ptr - i;
//            else
//                result[i] = min(r_ptr - i, i - l_ptr);
//        }

//        l_ptr = r_ptr;
//    }
//    else if(r_ptr == s.size()-1 && s[r_ptr] != 'c')
//        result[r_ptr] = r_ptr - l_ptr;
//    else {
//        result[r_ptr] = r_ptr - l_ptr;
//    }
//}
