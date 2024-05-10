#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

bool is_ok(int ppl, const std::vector<long long>& start_point,
           const std::vector<long long>& speed, double time)
{
    std::vector<double> left_distances(ppl);
    std::vector<double> right_distances(ppl);

    //находим левую и правую максимальную точку которой может достигнуть чел за время t
    for (int i = 0; i < ppl; ++i) {
        right_distances[i] = start_point[i] + (speed[i] * time);
        left_distances[i] = start_point[i] - (speed[i] * time);
    }

    // найдем максимальную левую границу и минимальную правую
    // если правая граница меньше левой, значит общая точка отсутствует
    double left = *std::max_element(left_distances.begin(), left_distances.end());
    double right = *std::min_element(right_distances.begin(), right_distances.end());

    if(right - left >= 0)
        return true;
    return false;
}

int main()
{
    int quant_ppl;
    std::cin >> quant_ppl;
    std::vector<long long> coord_ppl(quant_ppl);
    std::vector<long long> speed_ppl(quant_ppl);

    for (int index = 0; index < quant_ppl; ++index) {
        std::cin >> coord_ppl[index] >> speed_ppl[index];
    }

    double result = 0;
    double left_bound = 0;
    double right_bound = 10e9;
    for (int i = 0; i < 100; ++i)
    {
        double middle_bound = (right_bound + left_bound) / 2;
        if(is_ok(quant_ppl, coord_ppl, speed_ppl, middle_bound))
        {
            result = middle_bound;
            right_bound = middle_bound;

        } else {
            left_bound = middle_bound;
        }
    }

    std::cout << std::setprecision(20) << result;

    return 0;
}
