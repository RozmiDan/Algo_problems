#include <iostream>
#include <vector>

using namespace std;

void dfs_matr(vector<vector<int>>& matr, vector<bool>& count, vector<vector<int>>& res
              , vector<int>& cap ,int cur_capital, int city)
{
    count[city] = true;
    res[cur_capital].push_back(city);
    for (auto it : matr[city]) {
        if(count[it] == false && cap[it] == 0)
        {
            dfs_matr(matr, count, res, cap, cur_capital, it);
        }
    }
}

int main()
{
    int N, M, K;
    cin >> N >> M;
    vector<vector<int>> graph(N); 
    vector<bool> is_counted(N, false);
    vector<int> cap(N, 0);
    vector<vector<int>> res(N);

    for (int i = 0; i < M; ++i) {
        int fst_val, scnd_val;
        cin >> fst_val >> scnd_val;
        graph[--fst_val].push_back(--scnd_val);
        graph[scnd_val].push_back(fst_val);
    }


    cin >> K;

    for (int i = 0; i < K; ++i) {
        int val;
        cin >> val;
        --val;
        cap[val] = 1;
    }

    for (int i = 0; i < cap.size(); ++i) {
        if(cap[i] == 1)
            dfs_matr(graph, is_counted, res, cap, i, i);
    }

    for (int i = 0; i < res.size(); ++i) {
        if(res[i].size() > 0) {
            cout << res[i].size() << endl;
            for (int j = 0; j < res[i].size(); ++j) {
                cout << res[i][j] + 1 << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
