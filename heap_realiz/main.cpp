#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int  main()
{
    int N, cur_val, strt_val, fin_val;
    cin >> N;
    vector<vector<int>> graph(N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> cur_val;
            if(cur_val == 1)
                graph[i].push_back(j);
        }
    }
    cin >> strt_val >> fin_val;
    --strt_val;
    --fin_val;

    queue<int> q;
    vector<int> dist(N, -1);

    dist[strt_val] = 0;
    q.push(strt_val);

    while (!q.empty()) {
        int cur_val = q.front();
        q.pop();
        for (int it : graph[cur_val]) {
            if(dist[it] == -1) {
                dist[it] = dist[cur_val] + 1;
                q.push(it);
            }
        }
    }
    cout << dist[fin_val];

}


//void dfs(vector<bool>& counted, int cur_friend, vector<vector<int>>& graph, int& res_cnt)
//{
//    counted[cur_friend] = true;
//    ++res_cnt;
//    for (int i : graph[cur_friend]) {
//        if(!counted[i]){
//            dfs(counted, i, graph, res_cnt);
//        }
//    }
//}

//int  main()
//{
//    int N, S, val;
//    cin >> N >> S;
//    vector<vector<int>> graph(N);
//    vector<bool> is_counted(N, false);
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            cin >> val;
//            if(val == 1)
//                graph[i].push_back(j);
//        }
//    }
//    int res = 0;
//    dfs(is_counted, S - 1, graph, res);
//    cout << res - 1;

//}
//    int n, k;
//    cin >> n >> k;

//    vector<int> arr(n);
//
//    int res_cnt = 0;

//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];

//    int scnd_p = 0;
//    for (int fst_p = 0; fst_p < n; ++fst_p) {

//        while (scnd_p < n && hashtbl.size() <= k) {
//            hashtbl[arr[scnd_p]] += 1;
//            ++scnd_p;
//        }
//        res_cnt += scnd_p - fst_p + 1;
//        hashtbl[arr[fst_p]] -= 1;
//        if(hashtbl[arr[fst_p]] <= 0)
//            hashtbl.erase(hashtbl[arr[fst_p]]);
//    }
//    cout << res_cnt;

//long long  n;
//long long s;
//cin >> n >> s;
//vector<long long> arr(n);

//for (long long  i = 0; i < n; ++i)
//    cin >> arr[i];

//long long cur_sum = 0;
//long long  res_cnt = 0;
//long long  scnd_p = 0;

//for (long long  fst_p = 0; fst_p < n; ++fst_p) {
//    while(scnd_p < arr.size() && arr[scnd_p] + cur_sum < s) {
//        cur_sum += arr[scnd_p];
//        ++scnd_p;
//    }
//    res_cnt += arr.size() - scnd_p;
//    cur_sum -= arr[fst_p];
//}

//cout << res_cnt;
//return 0;

//int main()
//{
//    int n;
//    long long s;
//    cin >> n >> s;
//    vector<int> arr(n);

//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];

//    long long cur_sum = 0;
//    int res_len = 0;
//    int scnd_p = 0;
//    for (int fst_p = 0; fst_p < n; ++fst_p) {
//        while(scnd_p < arr.size() && cur_sum + arr[scnd_p] <= s) {
//            cur_sum += arr[scnd_p];
//            ++scnd_p;
//        }
//        res_len = max(res_len, scnd_p - fst_p);
//        cur_sum -= arr[fst_p];
//    }

//    cout << res_len;
//    return 0;
//}


//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<int> first_str(n);
//    vector<int> scnd_str(m);

//    for (int i = 0; i < n; ++i)
//        cin >> first_str[i];
//    for (int i = 0; i < m; ++i)
//        cin >> scnd_str[i];

//    int fst_ptr = 0;
//    long long res_counter = 0;
//    long long cycle_cntr = 0;
//    for (int scnd_ptr = 0; scnd_ptr < scnd_str.size(); ++scnd_ptr) {
//        if(scnd_str[scnd_ptr] == scnd_str[scnd_ptr-1] && scnd_ptr > 0) {
//            res_counter += cycle_cntr;
//            continue;
//        }
//        cycle_cntr = 0;
//        while (first_str[fst_ptr] <= scnd_str[scnd_ptr] && fst_ptr < first_str.size()) {
//            if(first_str[fst_ptr] == scnd_str[scnd_ptr])
//                ++cycle_cntr;
//            ++fst_ptr;
//        }
//        res_counter += cycle_cntr;

//    }
//    cout << res_counter;
//    return 0;
//}
