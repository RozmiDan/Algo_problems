#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(m);
    vector<long long> c(m);
    long long res = 0;

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    int i = 0;
    for (int j = 0; j < b.size(); ++j)
    {
        long long count = 0;
        while(i < a.size() && a[i] <= b[j])
        {
            if(a[i] == b[j])
                count += 1;
            ++i;
        }
        if(j > 0 && b[j] == b[j-1]){
            c.push_back(c[c.size() - 1]);
        } else {
            c.push_back(count);
        }
    }

    for (int i = 0; i < c.size(); ++i) {
        res += c[i];
    }

    cout << res;

    return 0;
}

