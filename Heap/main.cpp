#include <iostream>

using namespace std;

void heapify(int* arr, int size)
{
    //do heap instead array
    for (int index = 1; index < size; index++) {
        //sift up
        while(((index - 1)/2 > -1) && (arr[index] > arr[(index - 1)/2]))
        {
            int buf = arr[index];
            arr[index] = arr[(index - 1)/2];
            arr[(index - 1)/2] = buf;
            index = (index - 1)/2;
        }
    }
    //get the biggest one and put it on lst position
    while(size != 1)
    {
        //swap (arr[0],arr[size-1]
        int buf = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = buf;

        //sift down new arr[0]
        int index = 0;
        while(true)
        {
            int cur_max_index = index;
            if((index+1 < size - 1) && (arr[index] < arr[index+1]))
                cur_max_index = index+1;
            else if((index+2 < size - 1) && (arr[index] < arr[index+2]))
                cur_max_index = index+2;
            else {
                break;
            }
            //swap
            int buf = arr[index];
            arr[index] = arr[cur_max_index];
            arr[cur_max_index] = buf;
        }

        size--;
    }
}

void arr_cout(int* arr, int quan)
{
    for (int i = 0; i < quan; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int quant = 0;
    cin >> quant;
    int* arr = new int [quant]{};
    for(int i = 0; i < quant; i++)
    {
        cin >> arr[i];
    }
    arr_cout(arr, quant);
    heapify(arr, quant);
    arr_cout(arr, quant);
    delete [] arr;
    return 0;
}
