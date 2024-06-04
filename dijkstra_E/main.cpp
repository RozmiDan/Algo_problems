#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX = 1e8;

int dijkstra_algo(vector<vector<vector<int>>>& matr, int strt_city, int fin_city)
{
    set<pair<int,int>> min_val;
    vector<int> time(matr.size(), MAX);

    time[strt_city] = 0;
    min_val.insert({time[strt_city], strt_city});

    while (!min_val.empty())
    {
        int val = min_val.begin()->second;
        min_val.erase(min_val.begin());

        for (auto& it : matr[val])
        {
            int cur_val = it[0];
            int cur_time = it[1];

            //если текущее время будет позже времени отъезда (опоздание), то даже не рассматриваем вариант
            if(cur_time < time[val])
                continue;

            // если же посчитанное до этого время больше чем текущее время прибытия в данный город
            // меняем посчитанное время на наименьшее
            if (it[2] < time[cur_val]) {
                min_val.erase({time[cur_val], cur_val});
                time[cur_val] = it[2];
                min_val.insert({time[cur_val], cur_val});
            }
        }
    }

    if(time[fin_city] < MAX)
        return time[fin_city];
    else
        return -1;
}

int main()
{
    int n, strt, fin, races;
    cin >> n >> strt >> fin >> races;
    --strt;
    --fin;

    vector<vector<vector<int>>> matrix(n);

    for (int i = 0; i < races; ++i) {
        int fst_city, strt_time, scnd_city, fin_time;
        cin >> fst_city >> strt_time >> scnd_city >> fin_time;
        --fst_city;
        --scnd_city;

        matrix[fst_city].push_back({scnd_city, strt_time, fin_time});
    }

    cout << dijkstra_algo(matrix, strt, fin);

    return 0;
}
