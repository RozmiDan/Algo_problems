#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {

        if(numRows == 1)
            return {{1}};

        vector<vector<int>> result{{1}, {1, 1}};
        vector<int> cur_dp {1, 1};
        vector<int> prev_dp;

        for(int i = 2; i < numRows; ++i) {
            prev_dp.resize(cur_dp.size());
            prev_dp.swap(cur_dp);
            cur_dp.resize(prev_dp.size() + 1);
            cur_dp[0] = 1;
            cur_dp[cur_dp.size()-1] = 1;

            for(int j = 1; j < cur_dp.size()-1; ++j)
                cur_dp[j] = prev_dp[j-1] + prev_dp[j];

            result.push_back(cur_dp);
        }
        return result;
    }

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
