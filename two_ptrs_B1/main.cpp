#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> res(m);

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    int i = 0, j = 0;
    while(i < a.size() || j < b.size())
    {
        if(j == b.size() || (i < a.size() && a[i] < b[j]))
        {
            ++i;
        } else {
            res[j] = i;
            ++j;
        }
    }

    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";

    return 0;
}
