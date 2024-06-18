#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {

    ListNode* fst_ptr = nullptr;
    ListNode* scnd_ptr = head;

    while (scnd_ptr != nullptr)
    {
        ListNode* next = scnd_ptr->next;
        scnd_ptr->next = fst_ptr;
        fst_ptr = scnd_ptr;
        scnd_ptr = next;
    }
    return fst_ptr;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
