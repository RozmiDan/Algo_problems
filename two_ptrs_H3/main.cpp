#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n_A, m_B, max_weight, weight_A, weight_B;
    cin >> n_A >> m_B >> max_weight >> weight_A >> weight_B;
    vector<int> nums_A(n_A);
    vector<int> nums_B(m_B);
    long long result = 0;

    for (int i = 0; i < n_A; ++i) {
        cin >> nums_A[i]; }
    for (int i = 0; i < m_B; ++i) {
        cin >> nums_B[i]; }

    sort(nums_A.begin(), nums_A.end(), [](int a, int b){return a > b;});
    sort(nums_B.begin(), nums_B.end(), [](int a, int b){return a > b;});

    long long cur_sum = 0;
    long long cur_weight = 0;
    int l_ptr = -1;

    for (int i = 0; i < nums_A.size(); ++i) {
        if(cur_weight + weight_A <= max_weight) {
            cur_weight += weight_A;
            cur_sum += nums_A[i];
            ++l_ptr; }
        else
            break;
    }
    result = max(result, cur_sum);


    for (int i = 0; i < nums_B.size(); ++i) {
        cur_weight += weight_B;
        cur_sum += nums_B[i];

        while( (cur_weight > max_weight) && (l_ptr >= 0) )
        {
            cur_weight -= weight_A;
            cur_sum -= nums_A[l_ptr];
            --l_ptr;
        }

        if((cur_weight > max_weight))
            break;

        result = max(cur_sum, result);
    }

    cout << result;

    return 0;
}

//|| (l_ptr < 0)

//#include<bits/stdc++.h>
//using namespace std;

//int main() {
//    int n, m, s, A, B;
//    cin >> n >> m >> s >> A >> B;
//    vector<int> a(n), b(m);
//    for(int i=0; i<n; i++) cin >> a[i];
//    for(int i=0; i<m; i++) cin >> b[i];

//    vector<int> dp(s+1, 0);
//    for(int i=0; i<n; i++) {
//        for(int j=s; j>=A; j--) {
//            dp[j] = max(dp[j], dp[j-A] + a[i]);
//        }
//    }

//    for(int i=0; i<m; i++) {
//        for(int j=s; j>=B; j--) {
//            dp[j] = max(dp[j], dp[j-B] + b[i]);
//        }
//    }

//    cout << *max_element(dp.begin(), dp.end()) << endl;
//    return 0;
//}
