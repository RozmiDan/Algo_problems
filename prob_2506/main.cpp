#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    std::unordered_map<int, int> map;
    int k, result = 0;
    std::cin >> k;

    std::vector<std::string> words(k);
    for (int i = 0; i < words.size(); ++i) {
        std::cin >> words[i];
    }


    for(const std::string& word : words) {
        int lett_in_word = 0;
        for(const char& letter : word) {
            lett_in_word = lett_in_word | (1 << (letter - 'a'));
        }

        if(map.find(lett_in_word) == map.end())
            map[lett_in_word] = 1;
        else
            ++map[lett_in_word];
    }

    for(const auto& it : map)
    {
        int k = it.second;
        result += k * (k-1) / 2;
    }

    std::cout << result;

    return 0;
}

