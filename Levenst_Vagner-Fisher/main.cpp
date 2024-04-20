#include <iostream>

using std::string, std::endl, std::cout, std::cin;

int& levenst_algo(string& a, string& b)
{
    //create array
    int** arr_table = new int* [a.length()+1];
    for (unsigned int i = 0; i < (a.length()+1); i++)
    {
        arr_table[i] = new int [b.length()+1]{};
    }

    for (unsigned int i = 0; i <= a.length(); i++) {
        arr_table[i][0] = i;}

    for (unsigned int i = 1; i <= b.length(); i++) {
        arr_table[0][i] = i;}

    for (unsigned int i = 1; i <= a.length(); i++) {
        for (unsigned int j = 1; j <= b.length(); j++) {

            if(a[i-1] == b[j-1]) // если рассматриваемые буквы идентичны, расстояние будет зависеть от предыдущих
                arr_table[i][j] = arr_table[i-1][j-1];
            else {
                arr_table[i][j] = std::min(std::min(arr_table[i][j-1],arr_table[i-1][j]),arr_table[i-1][j-1])+1;
            }
        }
    }

    return arr_table[a.length()][b.size()];
}

int main()
{

    string fst_word, scnd_word;
    cin >> fst_word >> scnd_word;
    cout << levenst_algo(fst_word, scnd_word);
    return 0;
}
