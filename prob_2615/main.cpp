#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<long long> distance(vector<int>& nums) {

    vector<long long> res(nums.size());

    //создаем контейнер, для значений которые находятся правее текущего i
    //в pair первое значение будет хранить сумму индексов, второе кол-во элементов
    map<int, pair<long long, int>> right_map;
    map<int, pair<long long, int>> left_map;

    //подсчитываем кол-во всех значений и сумму для итогового прохода
    for (int i = 0; i < nums.size(); ++i) {
        if(right_map.find(nums[i]) != right_map.end()){
            right_map[nums[i]].first += i;
            right_map[nums[i]].second += 1;}
        else {
            right_map[nums[i]].first = i;
            right_map[nums[i]].second = 1;}
    }

    for (int i = 0; i < nums.size(); ++i) {
        long long left_sum = 0, right_sum = 0;

        // вычитаем из правых чисел, текущий индекс, чтобы не учитывать его
        right_map[nums[i]].first -= i;
        right_map[nums[i]].second -= 1;

        right_sum = right_map[nums[i]].first - (right_map[nums[i]].second * i);
        left_sum = left_map[nums[i]].second * i - left_map[nums[i]].first;

        res[i] = left_sum + right_sum;

        // перемещаем текущий индекс в левую часть, т.к. для следущего значения он уже будет левее
        if(left_map.find(nums[i]) != left_map.end()){
            left_map[nums[i]].first += i;
            left_map[nums[i]].second += 1;}
        else {
            left_map[nums[i]].first = i;
            left_map[nums[i]].second = 1;}
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];}

    vector<long long> res = distance(nums);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";}

    return 0;
}



//vector<long long> distance(vector<int>& nums) {

//    using int_pair = std::pair<int,int>;

//    unordered_multimap<int, int> map_pos;
//    vector<long long> res(nums.size());

//    for (int i = 0; i < nums.size(); ++i) {
//        map_pos.insert(int_pair(nums[i], i));
//    }

//    for (int i = 0; i < nums.size(); ++i) {
//        long long cur_sum = 0;
//        auto range = map_pos.equal_range(nums[i]);
//        for (auto it = range.first; it != range.second; ++it)
//        {
//            if(it->second != i)
//                cur_sum += abs(i-it->second);
//        }
//        res[i] = cur_sum;
//    }

//    return res;
//}
