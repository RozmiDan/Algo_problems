#include <iostream>
#include <vector>

using namespace std;

const long long INF = 10e10;

void build_tree(int cur_ind, int l_b, int r_b, vector<long long>& arr, vector<long long>& tree)
{
    if(l_b == r_b) {
        tree[cur_ind] = arr[l_b];
        return;
    }
    int m_b = (l_b + r_b) / 2;
    build_tree(cur_ind * 2, l_b, m_b, arr, tree);
    build_tree(cur_ind*2+1, m_b+1, r_b, arr, tree);
    tree[cur_ind] = min(tree[cur_ind*2], tree[cur_ind*2+1]);
}

void update_tree(int cur_ind, int l_b, int r_b, int ind, long long val, vector<long long>& tree)
{
    if(l_b == ind)
    {
        tree[cur_ind] = val;
        return;
    }

    int m_b = (l_b + r_b)/2;
    if(m_b >= ind)
        update_tree(cur_ind*2, l_b, m_b, ind, val, tree);
    else
        update_tree(cur_ind*2+1, m_b+1, r_b, ind, val, tree);
    tree[cur_ind] = min(tree[cur_ind*2], tree[cur_ind*2+1]);
}

long long get_min(int cur_ind, int l_b, int r_b, int req_l, int req_r, vector<long long>& tree)
{
    if(req_l > req_r)
        return INF;

    if(l_b == req_l && r_b == req_r)
        return tree[cur_ind];

    int m_b = (l_b + r_b) / 2;
    int lft_res = get_min(cur_ind*2, l_b, m_b, req_l, min(req_r, m_b), tree);
    int rght_res = get_min(cur_ind*2+1, m_b+1, r_b, max(l_b, m_b+1), req_r, tree);
    return min(lft_res, rght_res);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> init_arr(n);
    for (int i = 0; i < n; ++i)
        cin >> init_arr[i];
    vector<long long> seg_tree(n*2, INF);
    vector<long long> ans_arr;

    build_tree(1, 0, n-1, init_arr, seg_tree);

    int comm, fst_val;
    long long scnd_val;
    for (int i = 0; i < m; ++i) {
        cin >> comm >> fst_val >> scnd_val;

        if(comm == 1)
            update_tree(1, 0, n-1, fst_val, scnd_val, seg_tree);
        else
            ans_arr.push_back(get_min(1, 0, n-1, fst_val, scnd_val-1, seg_tree));
    }

    for (int i = 0; i < ans_arr.size(); ++i) {
        cout << ans_arr[i] << endl;
    }

    return 0;
}
