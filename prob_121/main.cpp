#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
        int l_ptr = 0;
        int r_ptr = 1;
        int max_profit = 0;
        while(r_ptr < prices.size())
        {
            if(prices[r_ptr] > prices[l_ptr])
                max_profit = max(prices[r_ptr] - prices[l_ptr], max_profit);
            else
                l_ptr = r_ptr;
            ++r_ptr;
        }
        return max_profit;
    }

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
