#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int union_find(vector<int>& par_val, int cur_val)
{
    // если в массиве указателя на родителя, в ячейке значения стоит само значение,
    // значит это значение корень, если же нет, переходим по значению дальше, на обратном пути
    // обновляем родителя для данного значения

    if(par_val[cur_val] == cur_val)
        return cur_val;
    par_val[cur_val] = union_find(par_val, par_val[cur_val]);
    return par_val[cur_val];
}

void union_set(int fst_val, int scnd_val, vector<int>& size, vector<int>& verts)
{
    // найти корни обоих значений
    int parent_fst = union_find(verts, fst_val);
    int parent_scnd = union_find(verts, scnd_val);
    // найти наибольшее множество и смержить к наибольшему множеству наименьшее
    if(size[parent_fst] < size[parent_scnd]) {
        verts[parent_fst] = parent_scnd;
        size[parent_scnd] += size[parent_fst];
        size[parent_fst] = size[parent_scnd];
    }
    else
    {
        verts[parent_scnd] = parent_fst;
        size[parent_fst] += size[parent_scnd];
        size[parent_scnd] = size[parent_fst];
    }
}

int main()
{
    int quant_vert, quant_edge;
    cin >> quant_vert >> quant_edge;

    vector<pair<int,pair<int,int>>> edges;
    // массив verts будет для каждой ноды указывать на предка
    vector<int> verts(quant_vert);
    // массив size будет хранить размер множества в котором состоит нода
    vector<int> union_size(quant_vert, 1);
    int res_weight = 0;

    // изначально ноды находятся сами по себе, поэтому они будут корневыми для самих себя
    for (int i = 0; i < verts.size(); ++i)
        verts[i] = i;

    for (int i = 0; i < quant_edge; ++i) {
        int fst_vert, scnd_vert, weight_edge;
        cin >> fst_vert >> scnd_vert >> weight_edge;
        --fst_vert;
        --scnd_vert;
        edges.push_back({weight_edge,{fst_vert, scnd_vert}});
    }

    sort(edges.begin(), edges.end());

    for (auto& it : edges)
    {
        int parent_fst = union_find(verts, it.second.first);
        int parent_scnd = union_find(verts, it.second.second);
        // если встречаются два разных множества, значит нужно их смержить
        if(parent_fst != parent_scnd) {
            union_set(parent_fst, parent_scnd, union_size, verts);
            res_weight += it.first; }
    }

    cout << res_weight;

    return 0;
}
