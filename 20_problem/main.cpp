#include <iostream>
#include <stack>

bool isValid(std::string s)
{
    std::stack<char> st;

    for(size_t index = 0; index < s.size(); index++)
    {
        if(s[index] == '{' || s[index] == '[' || s[index] == '(')
            st.push(s[index]);
        else if(!st.empty()) {
           if(s[index] == '}' && st.top() == '{')
               st.pop();
           else if(s[index] == ']' && st.top() == '[')
               st.pop();
           else if(s[index] == ')' && st.top() == '(')
               st.pop();
           else {
               st.push('X');
               break;
           }
        }
        else {
            st.push('X');
            break;
        }
    }

    return st.empty();
}

int main()
{
    std::string a {"[)]"};
    if(isValid(a))
        std::cout << "true";
    else
        std::cout << "false";
    return 0;
}
