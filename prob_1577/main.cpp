#include <iostream>
#include <vector>
#include <map>

using namespace std;

int numTriplets(vector<int>& nums1, vector<int>& nums2) {

    map<long long, int> mp1;
    map<long long, int> mp2;
    int result = 0;

    for (int i = 0; i < nums1.size(); ++i) {
        for (int j = i + 1; j < nums1.size(); ++j) {
            long long cur_multipl = (long long)nums1[i] * nums1[j];

            if(mp1.find(cur_multipl) != mp1.end())
                mp1[cur_multipl] += 1;
            else
                mp1[cur_multipl] = 1;
        }
    }

    for (int i = 0; i < nums2.size(); ++i) {
        for (int j = i + 1; j < nums2.size(); ++j) {
            long long cur_multipl = (long long)nums2[i] * nums2[j];

            if(mp2.find(cur_multipl) != mp2.end())
                mp2[cur_multipl] += 1;
            else
                mp2[cur_multipl] = 1;
        }
    }

    for (int i = 0; i < nums1.size(); ++i) {
        long long mult = (long long)nums1[i]*nums1[i];
        if(mp2.find(mult) != mp2.end())
            result += mp2[mult];
    }

    for (int i = 0; i < nums2.size(); ++i) {
        long long mult = (long long)nums2[i]*nums2[i];
        if(mp1.find(mult) != mp1.end())
            result += mp1[mult];
    }

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for (int i = 0; i < n; ++i)
        cin >> nums1[i];
    for (int i = 0; i < m; ++i)
        cin >> nums2[i];

    cout << numTriplets(nums1, nums2);

    return 0;
}
