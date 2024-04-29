#include <iostream>

using namespace std;

string addBinary(string a, string b)
{

    string result = "";
    short keep_in_mind = 0;

    if(a.size() < b.size())
        std::swap(a,b);

    while(b.size() < a.size())
        b.insert(0, 1, '0');

    for(size_t index = a.size(); index > 0; --index)
    {
        short cur_sum = 0;

        // Using ASCII to find value
        cur_sum += (a[index - 1] - '0') + (b[index - 1] - '0') + keep_in_mind;

        switch(cur_sum )
        {
            case 0 : result.insert(0, "0"); keep_in_mind = 0; break;
            case 1 : result.insert(0, "1"); keep_in_mind = 0; break;
            case 2 : result.insert(0, "0"); keep_in_mind = 1; break;
            case 3 : result.insert(0, "1"); keep_in_mind = 1; break;
        }
    }

    if(keep_in_mind)
        result.insert(0, "1");

    return result;
}

int main()
{
    std::cout << addBinary("1110", "111");
    string result = "av";
    result.insert(0, 1, '3');
//    char result = 'n';
//    std::cout << result - 'm';
    return 0;
}


// FIRST SOLUTION


//class Solution {
//public:
//    string addBinary(string a, string b) {
//    string result = "";
//    short keep_in_mind = 0;

//    if(a.size() < b.size())
//        std::swap(a,b);

//    while(b.size() < a.size())
//        b.insert(0, 1, '0');
//    //std::cout << b;

//    for(size_t index = a.size(); index > 0; --index)
//    {
//        short cur_sum = 0;

//        if(a[index - 1] == '1')
//            cur_sum += 1;

//        if(b[index - 1] == '1')
//            cur_sum += 1;

//        cur_sum += keep_in_mind;

//        switch(cur_sum )
//        {
//            case 0 : result.insert(0, "0"); keep_in_mind = 0; break;
//            case 1 : result.insert(0, "1"); keep_in_mind = 0; break;
//            case 2 : result.insert(0, "0"); keep_in_mind = 1; break;
//            case 3 : result.insert(0, "1"); keep_in_mind = 1; break;
//        }
//    }

//    if(keep_in_mind)
//        result.insert(0, "1");

//    return result;
//    }
//};
