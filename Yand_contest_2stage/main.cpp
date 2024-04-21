#include <iostream>
#include <map>
#include <vector>

static std::map<std::pair<int, int>, char> curr_field;

bool win_check(const std::pair<int, int>& coord, char player)
{
    bool flag_of_win = false;

    std::vector<std::pair<int, int>> vec_fst  {{0,1},{1,1},{1,0},{1,-1}};
    std::vector<std::pair<int, int>> vec_scnd {{0,-1},{-1,-1},{-1,0},{-1,-1}};

    for (int it = 0; it < 4; ++it)
    {
        char streak = 0;

        for (int index = 1; index < 5; ++index) {
            std::pair<int, int> cur_coord = std::pair<int,int>{coord.first + (vec_fst[it].first * index), coord.second + (vec_fst[it].second * index)};
            if(curr_field[cur_coord] == player)
            {
                ++streak;
            }
        }

        for (size_t index = 1; index < 5; ++index) {
            std::pair<int, int> cur_coord = std::pair<int,int>{coord.first + (vec_scnd[it].first * index), coord.second + (vec_scnd[it].second * index)};
            if(curr_field[cur_coord] == player)
            {
                ++streak;
            }
        }
        if(streak >= 5)
        {
            flag_of_win = true;
            break;
        }
    }

    return flag_of_win;
}



int main()
{
    size_t N;
    char player[2] {'x', '0'};
    std::pair<int, int> coord_param;

    bool cont_game_flag = false;
    bool winner = false;

    //принимаем получаемые значения
    std::cin >> N;
    for(size_t index = 0; index < N; ++index)
    {

        std::cin >> coord_param.first >> coord_param.second;
        curr_field[coord_param] = player[index % 2];

        if(cont_game_flag)
        {
            std::cout << "Inattention";
            break;
        }

        if(win_check(coord_param, player[index % 2]))
        {
            if(index != N-1)
            {
                cont_game_flag = true;
            }
            else {
                if(index % 2)
                    std::cout << "Second";
                else
                    std::cout << "First";
            }
        }
    }
    if(!winner && !cont_game_flag)
        std::cout << "Draw";
}
