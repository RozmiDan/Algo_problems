#include <iostream>

bool funk(std::string nick)
{
    bool length_flag, num_flag, cap_let_flag, upcase_let_flag, result;
    length_flag = num_flag = cap_let_flag = upcase_let_flag = result = false;

    for (size_t index = 0; index < nick.size(); ++index)
    {
        if(nick[index] > 47 && nick[index] < 58)
            num_flag = true;

        if(nick[index] > 64 && nick[index] < 91)
            cap_let_flag = true;

        if(nick[index] > 96 && nick[index] < 123)
            upcase_let_flag = true;

        if(index == 7)
            length_flag = true;

        if(length_flag && num_flag && upcase_let_flag && cap_let_flag)
            break;
    }

    if(length_flag && num_flag && upcase_let_flag && cap_let_flag)
        result = true;

    return result;
}

int main()
{
    std::string nickname;
    std::cin >> nickname;

    if(funk(std::move(nickname)) == true)
    {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
