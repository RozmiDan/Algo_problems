#include <iostream>

using namespace std;

int fibonachi_funk(int n)
{
    if(n <= 1)
        return n;
    else
        return fibonachi_funk(n-2) + fibonachi_funk(n-1);
}

int factorial_funk(int n)
{
    if(n == 0)
        return 1;
    else
    {
        return n * factorial_funk(n-1);
    }
}

int evklid_algo(int a, int b)
{
    int tmp = 0;
    if (b == 0)
        return a;
    else {
        tmp = b;
        b = a % b;
        a = tmp;
        return evklid_algo(a,b);
    }
}
void hanoi_algo(int start_pin, int finish_pin, int num_of_disks)
{
    int tmp = 6 - start_pin - finish_pin;

    if(num_of_disks == 1)
    {
        cout << "perekladivaem blin" << " iz " << start_pin << " v " << finish_pin << endl;
    }

    else
    {
        hanoi_algo(start_pin, tmp, num_of_disks - 1);
        cout << "perekladivaem blin" << " iz " << start_pin << " v " << finish_pin << endl;
        hanoi_algo(tmp, finish_pin, num_of_disks - 1);
    }
}

int main()
{
    int n,m;
  //  cin >> n;
   // cin >> m;
    hanoi_algo(1,2,4);
//    cout << n%m;
    return 0;
}
