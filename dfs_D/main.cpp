#include <iostream>
#include <vector>

using namespace std;

static bool flag = false;

void dfs_persons(int num, bool color, vector<vector<int>>& person, vector<int>& paint)
{
    paint[num] = color;
    for(int it : person[num])
    {
        if(paint[it] == 3)
            dfs_persons(it, !color, person, paint);
        else if(paint[it] == color)
        {
            flag = true;
            break;
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>());
    vector<int> color(N + 1, 3);    // 0 - fst color, 1 - scnd color
    int fst_pers, scnd_pers;

    for (int i = 0; i < M; ++i) {
        cin >> fst_pers >> scnd_pers;
        graph[fst_pers].push_back(scnd_pers);
        graph[scnd_pers].push_back(fst_pers);
    }

    for (int i = 1; i < color.size(); ++i) {
        if(color[i] == 3)
        {
            dfs_persons(i, 1, graph, color);
        }
    }

    if(flag)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}
