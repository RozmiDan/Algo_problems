#include <iostream>
#include <vector>
//#include <iterator>


template <typename T>
void Duplicate(std::vector<T>& vec)
{
    typename std::vector<T>::iterator it;
    size_t vec_size = vec.size();
    for (unsigned count = 0 ; count < vec_size; count++) {
        it = vec.begin() + count;
        vec.push_back(*it++);
    }
}

template <typename Iter>
Iter Unique(Iter first, Iter last)
{

    if(first == last)
        return last;

    Iter result = first;
    typename std::iterator_traits<Iter>::value_type value = *first;

    while(true)
    {
        while(*first == value && first != last)
            ++first;

        if(first == last)
            break;

        ++result;
        value = *first;

        if(result == first && first != last)
            continue;

        *result = *first;
    }
    return ++result;
}

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix)
{
    std::pair<size_t, size_t> max_index{0,0};

    for (std::vector<std::vector<int>>::const_iterator it = matrix.begin(); it < matrix.end(); ++it)
    {
        for (std::vector<int>::const_iterator it2 = it->begin(); it2 < it->end(); ++it2)
        {
            if(*it2 > matrix[max_index.first][max_index.second])
            {
                max_index.first = static_cast<size_t>(it - matrix.begin());
                max_index.second = static_cast<size_t>(it2 - it->begin());
            }
        }
    }

    return max_index;
}

[[nodiscard]]std::vector<std::string> Split(const std::string& str, char delimiter)
{
    std::vector<std::string> result;
    std::string tmp = "";

//    size_t counter = 0;
//    while(true)
//    {
//        if(counter == str.size())
//        {
//            result.push_back(tmp);
//            break;
//        }

//        if(str[counter] == delimiter)
//        {
//            if(str[counter - 1] == delimiter)
//            {
//                tmp = "";
//                result.push_back(tmp);
//            }
//            tmp = "";
//            counter++;
//            continue;
//        }
//        else
//        {
//            tmp += str[counter];
//        }

//        counter++;
//    }

    for (size_t index = 0; index < str.size(); index++) {

        if(str[index] == delimiter)
        {
            if(str[index - 1] == delimiter)
            {
                tmp = "";
            }
            result.push_back(tmp);
            tmp = "";
            continue;
        }

        tmp += str[index];
    }

    result.push_back(tmp);

    return result;
}

template <typename ...Args>
void emplace_back(const Args&... args)
{
   //new (ptr) T(args);
}

int main()
{
//    vector<int> a {5, 5, 3, 2, 2, 5, 9, 1};
//    for(auto b = 0; b < a.size(); b++)
//        cout << a[b] << " " ;
//    cout << endl;
//    vector<int>::iterator it1 = a.begin();
//    vector<int>::iterator it2 = a.end();

//    vector<int>::iterator it4 = Unique(it1,it2);
//    cout << " gfdg"<<endl;
//    for(auto b = it1; b < it4; b++)
//        cout << *b << " " ;
//    cout <<endl;

//    char av = 'f';
//    if(av == '')
    std::vector<std::string> a = Split("-",'-');

    for(auto b = 0; b < a.size(); b++)
        std::cout << a[b] << std::endl ;
}
