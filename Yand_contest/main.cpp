#include <iostream>
#include <vector>
#include <forward_list>

std::string funk(std::string str)
{
    std::string result, command;
    size_t cur_index_of_result = 0;
    size_t fst_index = 0;
    size_t scnd_index = 0;

    while(true)
    {
        command = "";

        if(str[fst_index] != '<')
        {
            while(str[scnd_index] != '<')
            {
                result += str[scnd_index]; // change this to result[cur_index].erase(str[scnd_indx])
                ++scnd_index;
                ++cur_index_of_result;
            }
            fst_index = scnd_index;
            ++scnd_index;
        }

        if(str[fst_index] == '<')
        {
            while(str[scnd_index] != '>')
            {
                command += str[scnd_index];
                ++scnd_index;
            }
            fst_index = scnd_index;
            ++scnd_index;
        }

        //add new string in result string


        if(command == "")
            continue;
        else {
            if(command == "bspace") {
                str.erase(cur_index_of_result, 1);
            }
            else if (command == "left") {
                if(cur_index_of_result > 0)
                    --cur_index_of_result;
            }
            else if (command == "delete") {
                if(cur_index_of_result < result.size() - 1)
                    str.erase(cur_index_of_result + 1, 1);
            }
            else if (command == "right") {
                if(cur_index_of_result < result.size() - 1)
                    ++cur_index_of_result;
            }
        }



        if(fst_index >= str.size())
            break;
    }

    return result;
}

int main()
{

    std::string task, usr_answ;
    std::cin >> task >> usr_answ;

    if(task == funk(std::move(usr_answ)))
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}






