#include <iostream>
#include <vector>

using namespace std;

int get_union(int cur_val, vector<int>& parent)
{
    if(parent[cur_val] == cur_val)
        return cur_val;
    parent[cur_val] = get_union(parent[cur_val], parent);
    return parent[cur_val];
}

void set_union(int fst_val, int scnd_val, vector<int>& par, vector<int>& size)
{
    int fst_par = get_union(fst_val, par);
    int scnd_par = get_union(scnd_val, par);
    if(size[fst_par] > size[scnd_par]) {
        par[scnd_par] = fst_par;
        size[fst_par] += size[scnd_par];
        size[scnd_par] = size[fst_par]; }
    else {
        par[fst_par] = scnd_par;
        size[scnd_par] += size[fst_par];
        size[fst_par] = size[scnd_par];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> parent(n);
    vector<string> answers;
    for (int i = 0; i < n; ++i)
        parent[i] = i;
    vector<int> size(n, 1);

    for (int i = 0; i < m; ++i) {
        string com;
        int fst_ver, scnd_ver;
        cin >> com >> fst_ver >> scnd_ver;
        --fst_ver;
        --scnd_ver;
        if(com == "union")
        {
            if(get_union(fst_ver, parent) != get_union(scnd_ver, parent))
                set_union(fst_ver, scnd_ver, parent, size);
        }
        else {
            if(get_union(fst_ver, parent) == get_union(scnd_ver, parent))
                answers.push_back("YES");
            else
                answers.push_back("NO");
        }
    }

    for (int i = 0; i < answers.size(); ++i) {
        cout << answers[i] << endl;
    }

    return 0;
}
