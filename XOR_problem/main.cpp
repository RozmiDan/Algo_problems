#include <iostream>

using namespace std;

//XOR table   -   x ^ 0 -> x;
//                x ^ x -> 0;
//            x ^ x ^ y -> y

template <size_t N>
int find_number(int arr[N])
{
    int result = 0;
    std::cout << N;
    for (unsigned int index = 0; index < N; ++index)
    {
        result ^= arr[index];
    }
    return result;
}

int main()
{
    int arr[7]{3,54,3,6,23,6,23};

    cout << find_number<7>(arr) << endl;
    return 0;
}
