#include <iostream>
#include <fstream>

int main()
{
    using namespace std;

    int num_of_days, days_hold;
    cin >> num_of_days >> days_hold;

    int* arr = new int [num_of_days];
    cin >> arr[0];

    //сделали массив прироста стоимости по дням
    int value;
    for (int i = 1; i < num_of_days; i++) {
        cin >> value;
        arr[i] = value - arr[0];
        arr[0] = value;
    }

    int max_profit = 0;
    //бежим окном по массиву
    for (int i = 1; i < num_of_days; i++) {
        if(arr[i] <= 0)
            continue;

        if(arr[i] > max_profit)
            max_profit = arr[i];

        int sum_of_day = arr[i];
        for (int j = 1; j < days_hold; j++) {
            if(i + j >= num_of_days)
                continue;
            sum_of_day += arr[i + j];
            if(sum_of_day > max_profit)
                max_profit = sum_of_day;
        }
    }

    cout << max_profit;

    return 0;
}
