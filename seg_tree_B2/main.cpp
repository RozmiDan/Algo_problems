#include <iostream>
#include <vector>

using namespace std;

void build(int cur_ind, int l_b, int r_b, vector<int>& seg, vector<short>& arr)
{
    if(l_b == r_b) {
        seg[cur_ind] = arr[l_b];
        return; }
    int m_b = (l_b + r_b) / 2;
    build(cur_ind*2, l_b, m_b, seg, arr);
    build(cur_ind*2+1, m_b+1, r_b, seg, arr);
    seg[cur_ind] = seg[cur_ind*2] + seg[cur_ind*2+1];
}

void update(int cur_ind, int l_b, int r_b, int val, int ind, vector<int>& seg)
{
    if(l_b == r_b) {
        seg[cur_ind] = val;
        return; }
    int m_b = (l_b + r_b) / 2;
    if(ind <= m_b)
        update(cur_ind*2, l_b, m_b, val, ind, seg);
    else
        update(cur_ind*2+1, m_b+1, r_b, val, ind, seg);
    seg[cur_ind] = seg[cur_ind*2] + seg[cur_ind*2+1];
}

void get_res(int cur_ind, int l_b, int r_b, int& ind_k, int& answ, bool& flag, vector<int>& seg)
{
    if(l_b == r_b)
    {
        answ = l_b;
        flag = true;
        return;
    }

    int m_b = (l_b + r_b) / 2;

    if(flag)
        return;
    else {
        if(seg[cur_ind * 2] >= ind_k) {
            get_res(cur_ind*2, l_b, m_b, ind_k, answ, flag, seg); }
        else {
            ind_k -= seg[cur_ind*2];
            get_res(cur_ind*2+1, m_b+1, r_b, ind_k, answ, flag, seg); }
    }

}

int main()
{
    int n, m, fst_val, scnd_val;
    cin >> n >> m;

    vector<short> init_arr(n);
    for (int i = 0; i < n; ++i)
        cin >> init_arr[i];

    vector<int> seg_t(100000 * 4, 0);
    vector<int> res;

    build(1, 0, n-1, seg_t, init_arr);

    for (int i = 0; i < m; ++i) {
        cin >> fst_val >> scnd_val;
        if(fst_val == 1)
        {
            update(1, 0, n-1, 1 - init_arr[scnd_val],scnd_val, seg_t);
        } else {
            bool flag = false;
            int answer = -1;
            scnd_val += 1;
            get_res(1, 0, n-1, scnd_val, answer, flag, seg_t);
            res.push_back(answer);
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }

    return 0;
}



