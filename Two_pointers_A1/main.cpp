#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_arrays(vector<int>& a, vector<int>& b)
{
    vector<int> c(a.size() + b.size());

    int i = 0, j = 0;
    while(i < a.size() || j < b.size())
    {
        if(j == b.size() || (a[i] < b[j] && i < a.size()) ){
            c[i+j] = a[i];
            ++i;
        } else {
            c[i+j] = b[j];
            ++j;
        }
    }

    return c;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    vector<int> c = merge_arrays(a,b);
    for (int i = 0; i < c.size(); ++i) {
        cout << c[i] << " ";
    }

    return 0;
}
