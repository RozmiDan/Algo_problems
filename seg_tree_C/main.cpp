#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1e10;

void reupd(int cur_ind, vector<pair<long long, int>>& tree) {
    if(tree[cur_ind*2].first == tree[cur_ind*2+1].first)
    {
        tree[cur_ind].first = tree[cur_ind*2+1].first;
        tree[cur_ind].second = tree[cur_ind*2+1].second + tree[cur_ind*2].second;
    }
    else if (tree[cur_ind*2].first > tree[cur_ind*2+1].first)
        tree[cur_ind] = tree[cur_ind*2+1];
    else
        tree[cur_ind] = tree[cur_ind*2];
}

void build_tree(int cur_ind, int l_b, int r_b, vector<long long>& arr
                , vector<pair<long long, int>>& tree)
{
    if(l_b == r_b) {
        tree[cur_ind].first = arr[l_b];
        tree[cur_ind].second = 1;
        return;
    }
    int m_b = (l_b + r_b) / 2;
    build_tree(cur_ind * 2, l_b, m_b, arr, tree);
    build_tree(cur_ind*2+1, m_b+1, r_b, arr, tree);

    reupd(cur_ind, tree);
}

void update_tree(int cur_ind, int l_b, int r_b, int ind, long long val
                 , vector<pair<long long, int>>& tree)
{
    if(l_b == r_b)
    {
        tree[cur_ind].first = val;
        tree[cur_ind].second = 1;
        return;
    }

    int m_b = (l_b + r_b)/2;
    if(m_b >= ind)
        update_tree(cur_ind*2, l_b, m_b, ind, val, tree);
    else
        update_tree(cur_ind*2+1, m_b+1, r_b, ind, val, tree);

    reupd(cur_ind, tree);
}

pair<long long,int> get_min(int cur_ind, int l_b, int r_b, int req_l, int req_r
                  , vector<pair<long long, int>>& tree)
{
    if(req_l > req_r)
        return {INF,0};

    if(l_b == req_l && r_b == req_r)
        return tree[cur_ind];

    int m_b = (l_b + r_b) / 2;
    pair<long long, int> lft_res = get_min(cur_ind*2, l_b, m_b, req_l, min(req_r, m_b), tree);
    pair<long long, int> rght_res = get_min(cur_ind*2+1, m_b+1, r_b, max(req_l, m_b+1), req_r, tree);
    pair<long long, int> res;

    if(lft_res.first == rght_res.first)
    {
        res.first = rght_res.first;
        res.second = rght_res.second + lft_res.second;
    }
    else if (lft_res.first > rght_res.first)
        res = rght_res;
    else
        res = lft_res;

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> init_arr(n);
    for (int i = 0; i < n; ++i)
        cin >> init_arr[i];
    vector<pair<long long, int>> seg_tree(n*4, {INF, 0});
    vector<pair<long long, int>> ans_arr;

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
        cout << ans_arr[i].first << " " << ans_arr[i].second << endl;
    }

    return 0;
}
