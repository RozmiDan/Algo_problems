#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int main()
{
    int n, k;
    long long result = 0;
    cin >> n >> k;
    vector<int> arr(n);
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];}

    int l_ptr = 0;
    for (int r_ptr = 0; r_ptr < arr.size(); ++r_ptr) {
        //добавляем новый элемент в мапу
        if(map.find(arr[r_ptr]) != map.end())
        {
            map[arr[r_ptr]] += 1;
        } else {
            map[arr[r_ptr]] = 1;
        }

        //проверка на условие k уникальных элементов
        while(!(map.size() <= k))
        {
            // передвигаем левую границу
            map[arr[l_ptr]] -= 1;
            if(map[arr[l_ptr]] <= 0)
                map.erase(arr[l_ptr]);
            ++l_ptr;
        }

        result += r_ptr - l_ptr + 1;
    }

    cout << result;

    return 0;
}
