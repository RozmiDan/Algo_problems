#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    string result = strs[0];

    for(size_t index = 1; index < strs.size(); ++index)
    {
        if(result == "" || strs[index] == "")
        {
            result = "";
            break;
        }

        size_t j = 0;

        while(result[j] == strs[index][j] && result[j] != '\0')
            j++;

        for(size_t a = result.size(); a > j; a--)
            result.erase(j,1);
    }
    return result;
}

int main()
{
    std::vector<string> strs {"flower","flower","flower","flower"};
    std::cout << longestCommonPrefix(strs) << endl;

    return 0;
}
