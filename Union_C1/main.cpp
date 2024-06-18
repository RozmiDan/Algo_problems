#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int parent;
    int size;
    int sum;

    Node(int x, int y, int z) : parent(x), size(y), sum(z) {}
};

pair<int, int> union_find(int cur_val, vector<Node>& my_set)
{
    if(cur_val == my_set[cur_val].parent)
        return {cur_val, 0};
    pair<int,int> ans = union_find(my_set[cur_val].parent, my_set);
    my_set[cur_val].parent = ans.first;
    my_set[cur_val].sum += ans.second;
    return {my_set[cur_val].parent, my_set[cur_val].sum};
}

void union_set(int fst_val, int scnd_val, vector<Node>& my_set)
{
    int parent_fst = union_find(fst_val, my_set).first;
    int parent_scnd = union_find(scnd_val, my_set).second;

    if(parent_fst != parent_scnd) {
        if(my_set[parent_fst].size > my_set[parent_scnd].size)
        {
            my_set[parent_scnd].sum -= my_set[parent_fst].sum;
            my_set[parent_scnd].parent = parent_fst;
            my_set[parent_fst].size += my_set[parent_scnd].size;
        }
        else
        {
            my_set[parent_fst].sum -= my_set[parent_scnd].sum;
            my_set[parent_fst].parent = parent_scnd;
            my_set[parent_scnd].size += my_set[parent_fst].size;
        }
    }
}

void add(int cur_val, vector<Node>& my_set)
{
    int par = union_find(cur_val, my_set).first;

}

int main()
{
    int quant_players, quant_req;
    cin >> quant_players >> quant_req;

    vector<Node> my_set;
    vector<int> answer;

    for (int i = 0; i < quant_players; ++i) {
        my_set.push_back(Node(i, 1, 0));
    }

    for (int i = 0; i < quant_req; ++i) {
        string request;
        int fst, scnd;
        cin >> request;
        if(request == "add")
        {
            cin >> fst >> scnd;
            --fst;
            int par = union_find(fst, my_set).first;
            my_set[par].sum += scnd;
        }
        else if (request == "join") {
            cin >> fst >> scnd;
            --fst;
            --scnd;
            union_set(fst, scnd, my_set);
        }
        else {
            cin >> fst;
            --fst;
            pair<int, int> res = union_find(fst, my_set);
            answer.push_back(my_set[res.first].sum + res.second);
        }
    }

    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << endl;
    }

    return 0;
}
