#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int quant_vert, quant_edge;
    cin >> quant_vert;
    vector<pair<int,int>> coord_vert(quant_vert);
    vector<vector<int>> graph(quant_vert);
    vector<int> weight;

    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < quant_vert; ++j) {
            if(j != i)
                graph[i].push_back(j);
        }
    }



    for (int i = 0; i < coord_vert.size(); ++i) {
        cin >> coord_vert[i].first >> coord_vert[i].second;
    }

    cin >> quant_edge;


    return 0;
}
