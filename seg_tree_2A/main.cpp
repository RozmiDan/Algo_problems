#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    long long max_elem = 0;
    long long prefix = 0;
    long long suffix = 0;
    long long sum = 0;
};

void reupd(int cur_ind, vector<Node>& seg_t)
{
    seg_t[cur_ind].max_elem = seg_t[cur_ind*2].max_elem;
    seg_t[cur_ind].max_elem = max(seg_t[cur_ind].max_elem, seg_t[cur_ind*2+1].max_elem);
    seg_t[cur_ind].max_elem = max(seg_t[cur_ind].max_elem, seg_t[cur_ind*2].suffix + seg_t[cur_ind*2+1].prefix);

    seg_t[cur_ind].suffix = seg_t[cur_ind*2+1].suffix;
    seg_t[cur_ind].suffix = max(seg_t[cur_ind].suffix, seg_t[cur_ind*2+1].sum + seg_t[cur_ind*2].suffix);

    seg_t[cur_ind].prefix = seg_t[cur_ind*2].prefix;
    seg_t[cur_ind].prefix = max(seg_t[cur_ind].prefix, seg_t[cur_ind*2].sum + seg_t[cur_ind*2+1].prefix);

    seg_t[cur_ind].sum = seg_t[cur_ind*2].sum + seg_t[cur_ind*2+1].sum;
}

void build_tree(int cur_ind, int l_b, int r_b, vector<Node>& seg_t, vector<long long>& arr)
{
    if(l_b == r_b)
    {
        seg_t[cur_ind].max_elem = max((long long)0, arr[l_b]);
        seg_t[cur_ind].prefix = max((long long)0, arr[l_b]);
        seg_t[cur_ind].suffix = max((long long)0, arr[l_b]);
        seg_t[cur_ind].sum = arr[l_b];
        return;
    }
    int m_b = (l_b + r_b) / 2;
    build_tree(cur_ind*2, l_b, m_b, seg_t, arr);
    build_tree(cur_ind*2+1, m_b+1, r_b, seg_t, arr);

    reupd(cur_ind, seg_t);
}

long long get_answ(vector<Node>& seg_t)
{
    return seg_t[1].max_elem;
}

void update(int cur_ind, int l_b, int r_b, int ind, long long val, vector<Node>& seg_t)
{
    if(l_b == r_b)
    {
        seg_t[cur_ind].sum = val;
        seg_t[cur_ind].prefix = max((long long)0, val);
        seg_t[cur_ind].suffix = max((long long)0, val);
        seg_t[cur_ind].max_elem = max((long long)0, val);
        return;
    }
    int m_b = (l_b + r_b) / 2;
    if(ind <= m_b)
        update(cur_ind*2, l_b, m_b, ind, val, seg_t);
    else
        update(cur_ind*2+1, m_b+1, r_b, ind, val, seg_t);

    reupd(cur_ind, seg_t);
}

int main()
{
    int n, m, fst_val;
    long long scnd_val;
    cin >> n >> m;

    vector<long long> init_arr(n);
    for (int i = 0; i < n; ++i)
        cin >> init_arr[i];

    vector<Node> seg_tree(n*4, Node());
    build_tree(1, 0, n-1, seg_tree, init_arr);

    vector<long long> answ{get_answ(seg_tree)};

    for (int i = 0; i < m; ++i) {
        cin >> fst_val >> scnd_val;
        update(1, 0, n-1, fst_val, scnd_val, seg_tree);
        answ.push_back(get_answ(seg_tree));
    }

    for (int i = 0; i < answ.size(); ++i) {
        cout << answ[i] << endl;
    }

    return 0;
}
