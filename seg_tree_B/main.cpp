#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e10;

void build_tree(int cur_ind, int l_b, int r_b, vector<long long>& seg_t, vector<long long>& arr)
{
    //left_deriv = cur_ind*2 , rght_deriv = cur_ind*2+1
    if(l_b == r_b) {
        seg_t[cur_ind] = arr[l_b];
        return;
    }
    int m_b = (l_b + r_b) / 2;
    build_tree(cur_ind*2, l_b, m_b, seg_t, arr);
    build_tree(cur_ind * 2 + 1, m_b + 1, r_b, seg_t, arr);
    seg_t[cur_ind] = min(seg_t[cur_ind*2], seg_t[cur_ind*2+1]);
}

void update(int cur_ind, int l_b, int r_b, int pos, long long val, vector<long long>& seg_t)
{
    if(l_b == r_b)
    {
        seg_t[cur_ind] = val;
        return;
    }

    int m_b = (l_b + r_b) / 2;
    if(pos <= m_b)
        update(cur_ind * 2, l_b, m_b, pos, val, seg_t);
    else
        update(cur_ind * 2 + 1, m_b + 1, r_b, pos, val, seg_t);

    seg_t[cur_ind] = min(seg_t[cur_ind*2], seg_t[cur_ind*2+1]);
}

long long get_result(int cur_ind, int l_b, int r_b, int req_l, int req_r, vector<long long>& seg_t)
{
    if(req_l > req_r)
        return INF;

    int m_b = (r_b + l_b) / 2;

    if(l_b == req_l && r_b == req_r)
        return seg_t[cur_ind];

    long long lft_res = get_result(cur_ind*2, l_b, m_b, req_l, min(req_r, m_b), seg_t);
    long long rght_res = get_result(cur_ind*2+1, m_b + 1, r_b, max(req_l, m_b + 1), req_r, seg_t);

    return min(lft_res, rght_res);
}

int main()
{
    int n, m, command, fst_val;
    long long scnd_val;
    cin >> n >> m;
    vector<long long> init_arr(n);
    vector<long long> seg_tree(n * 4, INF);
    for (int i = 0; i < n; ++i) {
        cin >> init_arr[i];
    }

    vector<long long> res_cout;

    build_tree(1, 0, n - 1, seg_tree, init_arr);

    for (int i = 0; i < m; ++i) {
        cin >> command >> fst_val >> scnd_val;
        if(command == 1)
            update(1, 0, n-1, fst_val, scnd_val, seg_tree);
        else {
            res_cout.push_back(get_result(1, 0, n-1, fst_val, scnd_val-1, seg_tree));
        }
    }

    for (int i = 0; i < res_cout.size(); ++i) {
        cout << res_cout[i] << endl;
    }

    return 0;
}
