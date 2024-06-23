#include <iostream>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    set<ListNode*> table;
    bool flag_is_cont = false;
    ListNode* cur = head;
    while(cur != nullptr)
    {
        if(table.find(cur) == table.end()) {
            table.insert(cur);
            cur = cur->next; }
        else
        {
            flag_is_cont = true;
            break;
        }
    }

    if(!flag_is_cont)
    {
        return false;
    } else {
        return true;
    }
}

int main()
{

    return 0;
}
