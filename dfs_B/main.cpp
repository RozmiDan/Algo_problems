#include <iostream>
#include <vector>

using namespace std;

static int counter;

void dfs_table(int number, vector<vector<int>>& table, vector<bool>& counted)
{
    ++counter;
    counted[number] = true;
    for (int it : table[number]) {
        if(!counted[it])
            dfs_table(it, table, counted);
    }
}

int main()
{
    bool no_flag = false;
    int quant_hrss, num_hrs;

    cin >> quant_hrss >> num_hrs;

    vector<vector<int>> comp_table(quant_hrss + 1, vector<int>());
    vector<bool> is_counted (quant_hrss + 1, false);

    int fst_hrs, scnd_hrs;
    while(true)
    {
        cin >> fst_hrs;
        if(fst_hrs == 0)
            break;
        cin >> scnd_hrs;
        comp_table[fst_hrs].push_back(scnd_hrs);
        if(scnd_hrs == num_hrs)
            no_flag = true;
    }

    if(no_flag) {
        cout << "No";
        return 0; }

    dfs_table(num_hrs, comp_table, is_counted);

    if(counter == quant_hrss)
        cout << "Yes";
    else {
        cout << "No";
    }

    return 0;
}
