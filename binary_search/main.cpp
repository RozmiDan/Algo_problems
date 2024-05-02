#include <iostream>

using namespace std;

//Шаблон бин. поиска который нужно запомнить
bool is_ok(int mid, int val, int* arr)
{
    if(arr[mid] <= val)
        return true;
    return false;
}

int binary_search_template(int* arr, size_t size, int val)
{
    int left_bound = 0;
    int right_bount = size - 1;
    int result = 0;

    while(left_bound <= right_bount)
    {
        int middle_val = (right_bount + left_bound)/2;
        if(is_ok(middle_val, val, arr))
        {
            //if we want to find minimum, we have to push right_bound to the left
            left_bound = middle_val + 1;
            result = middle_val ;
        }
        else
        {
            //
            right_bount = middle_val - 1;
        }

    }

    return result;
}

int main()
{
    const int N = 6;
    int arr[N] = {1,1,3,4,7,8};

    cout << "position " << binary_search_template(arr, N, -12) << endl;
    cout << "value " << arr[binary_search_template(arr, N, -12)];

    return 0;
}
