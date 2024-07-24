#include <iostream>

using namespace std;

int main()
{
    int arr[3]{1,1,2};
    int n;
    cin >> n;
    if(n<2)
        cout << arr[n];
    else
    {
        for (int i = 2; i <= n; ++i) {
            arr[2] = (arr[1] + arr[0]) % 10;
            arr[0] = arr[1];
            arr[1] = arr[2];
        }
        cout << arr[2];
    }

    return 0;
}
