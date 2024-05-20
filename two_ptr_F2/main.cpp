#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n;
    long long k, result = 0;
    cin >> n >> k;
    vector<long long> arr(n);
    multiset<long long> dict;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];}

    int l_ptr = 0;
    for (int r_ptr = 0; r_ptr < arr.size(); ++r_ptr) {
        dict.insert(arr[r_ptr]);

        while (*prev(dict.end(),1) - *dict.begin()  > k)
        {
            dict.erase(dict.find(arr[l_ptr]));
            ++l_ptr;
        }

        result += r_ptr - l_ptr + 1;
    }

    cout << result;

    return 0;
}


//template <typename T>
//struct Debug
//{
//    Debug(T) = delete;
//};

//    for (int i = 0; i < n; ++i) {
//        dict.insert(arr[i]);}

//    cout << dict.size() << endl;

//    dict.erase(dict.find(6));
//    dict.erase(6);

//    cout << dict.size() << endl;

//    for (auto& it : dict) {
//        cout << it << " ";
//    }

//  Debug<decltype(it)> a;
