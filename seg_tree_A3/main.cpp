#include <iostream>
#include <vector>

using namespace std;

void update(int cur_ind, int l_b, int r_b, int ind, vector<int>& seg_t)
{
    if(l_b == r_b)
    {
        seg_t[cur_ind] += 1;
        return;
    }
    int m_b = (l_b + r_b) / 2;
    if(ind <= m_b)
        update(cur_ind*2, l_b, m_b, ind, seg_t);
    else
        update(cur_ind*2+1, m_b+1, r_b, ind, seg_t);
    seg_t[cur_ind] = seg_t[cur_ind*2] + seg_t[cur_ind*2+1];
}

int get(int cur_ind, int l_b, int r_b, int req_l, int req_r, vector<int>& seg_t)
{
    if(req_l > req_r)
        return 0;

    if(l_b == req_l && r_b == req_r)
        return seg_t[cur_ind];

    int m_b = (l_b + r_b) / 2;

    int lft_res = get(cur_ind*2, l_b, m_b, req_l, min(req_r, m_b), seg_t);
    int rght_res = get(cur_ind*2+1, m_b+1, r_b, max(req_l, m_b+1), req_r, seg_t);

    return lft_res + rght_res;
}

int main()
{
    int n, val;
    cin >> n;
    vector<int> init_arr(n);
    vector<int> seg_t(n*4, 0);
    vector<int> answ;

    for (int i = 0; i < n; ++i) {
        cin >> val;
        --val;
        update(1, 0, n-1, val, seg_t);
        answ.push_back(get(1, 0, n-1, val+1, n-1, seg_t));
    }

    for (int i = 0; i < answ.size(); ++i) {
        cout << answ[i] << " ";
    }

    return 0;
}
