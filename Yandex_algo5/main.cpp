#include <iostream>

int main()
{
    using namespace std;

    const short raws = 10, columns = 10;

    short arr_x[4]{1, -1, 0, 0};
    short arr_y[4]{0, 0, -1, 1};

    // делаем поле с границами
    short chess_desk[raws][columns]{};
    for (size_t i = 0; i < raws; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if(i == 0 || j == 0 || i == 9 || j == 9)
                chess_desk[i][j] = -28;
            else
                chess_desk[i][j] = 0;
        }
    }

    // принимаем данные и вставляем в поле, подсчитывая соседей
    short N , x , y, result;
    short P_figure = 0;
    cin >> N;
    for (int index = 0; index < N; index++)
    {
        cin >> x >> y;
        chess_desk[x][y] = 55;
        short quant_of_neighb = 0;
        //для каждой клетки смотрим соседей
        for (int i = 0; i < 4; i++) {
            if(chess_desk[x + arr_x[i]][y + arr_y[i]] == 55)
                quant_of_neighb++;

        }
        //формула зависимости периметра от количества соседей
        P_figure += 4 - (2 * quant_of_neighb);
        result = P_figure;
    }

    cout << result;
    return 0;
}


//#include <iostream>
//#include <fstream>

//int main()
//{
//    using namespace std;

//    int num_of_days, days_hold;
//    cin >> num_of_days >> days_hold;

//    int* arr = new int [num_of_days];
//    cin >> arr[0];

//    //сделали массив прироста стоимости по дням
//    int value;
//    for (int i = 1; i < num_of_days; i++) {
//        cin >> value;
//        arr[i] = value - arr[0];
//        arr[0] = value;
//    }

//    int max_profit = 0;
//    //бежим окном по массиву
//    for (int i = 1; i < num_of_days; i++) {
//        if(arr[i] <= 0)
//            continue;

//        if(arr[i] > max_profit)
//            max_profit = arr[i];

//        int sum_of_day = arr[i];
//        for (int j = 1; j < days_hold; j++) {
//            if(i + j >= num_of_days)
//                continue;
//            sum_of_day += arr[i + j];
//            if(sum_of_day > max_profit)
//                max_profit = sum_of_day;
//        }
//    }

//    cout << max_profit;

//    return 0;
//}
