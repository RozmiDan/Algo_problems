#include <iostream>
#include <vector>

using namespace std;

static int counter = 0;

void dfs_friend(int cur_ind, vector<bool>& counted, vector<vector<int>>& matr)
{
    ++counter;
    counted[cur_ind] = 1;

    for (int it : matr[cur_ind]) {
        if(!counted[it])
            dfs_friend(it, counted, matr);
    }

}

int main()
{
    int quant_ppl, num_ind;
    cin >> quant_ppl >> num_ind;
    vector<vector<int>> matrix(quant_ppl, vector<int>());
//    vector<vector<int>> graph(quant_ppl, vector<int>(quant_ppl));
    vector<bool> cntd_frnd(quant_ppl, 0);

    int cur_val;

    for (int i = 0; i < quant_ppl; ++i) {
        for (int j = 0; j < quant_ppl; ++j) {
            cin >> cur_val;
            if(cur_val == 1)
                matrix[i].push_back(j);
        }
    }

    dfs_friend(num_ind - 1, cntd_frnd, matrix);

    cout << counter - 1;

    return 0;
}
