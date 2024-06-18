#include <iostream>
#include <vector>

using namespace std;

struct FD
{
public:
    FD(int x, int y, int z, int j)
    {
        m_size = x;
        min_elem = y;
        max_elem = z;
        parent = j;
    }
    int m_size;
    int min_elem;
    int max_elem;
    int parent;
};

int union_get(int cur_val, vector<FD>& parent)
{
    if(cur_val == parent[cur_val].parent)
        return cur_val;
    parent[cur_val].parent = union_get(parent[cur_val].parent, parent);
    return parent[cur_val].parent;
}

void union_set(int fst_val, int scnd_val, vector<FD>& parent)
{
    if(union_get(fst_val, parent) != union_get(scnd_val, parent))
    {
        int fst_parent = union_get(fst_val, parent);
        int scnd_parent = union_get(scnd_val, parent);

        if(parent[fst_parent].m_size > parent[scnd_parent].m_size)
        {
            parent[fst_parent].m_size += parent[scnd_parent].m_size;
            parent[scnd_parent].parent = scnd_parent;
            parent[fst_parent].max_elem = max(parent[fst_parent].max_elem, parent[scnd_parent].max_elem);
            parent[fst_parent].min_elem = min(parent[fst_parent].min_elem, parent[scnd_parent].min_elem);
        }

        else
        {
            parent[scnd_parent].m_size += parent[fst_parent].m_size;
            parent[fst_parent].parent = scnd_parent;
            parent[scnd_parent].max_elem = max(parent[fst_parent].max_elem, parent[scnd_parent].max_elem);
            parent[scnd_parent].min_elem = min(parent[fst_parent].min_elem, parent[scnd_parent].min_elem);
        }
    }
}



int main()
{
    int n, m;
    cin >> n >> m;
    FD a(1,23,4,5);
    vector<FD>parent(n);
    vector<vector<int>> answer;
    for (int i = 0; i < n; ++i) {
        //FD a(1, i, i, i);
        parent[i] ;
    }

    for (int i = 0; i < m; ++i) {
        string command;
        int fst_ver, scnd_ver;
        cin >> command;
        if(command == "union")
        {
            cin >> fst_ver >> scnd_ver;
            --fst_ver;
            --scnd_ver;
            union_set(fst_ver, scnd_ver, parent);
        }
        else {
            cin >> fst_ver;
            --fst_ver;
            int res = union_get(fst_ver, parent);
            answer.push_back({parent[res].min_elem, parent[res].max_elem, parent[res].m_size});
        }

    }

    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i][0] + 1 << " " << answer[i][1] + 1 << " " << answer[i][2] + 1 << endl;
    }

    return 0;
}
