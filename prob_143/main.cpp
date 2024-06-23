#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) {
    // merge right n left pieces
    ListNode* mid_ptr = head;
    ListNode* scnd_ptr = head;

    // find the middle of the list
    while(scnd_ptr->next && scnd_ptr->next->next)
    {
        mid_ptr = mid_ptr->next;
        scnd_ptr = scnd_ptr->next->next;
    }

    // reorder right piece of list
    ListNode* rght_half = nullptr;
    scnd_ptr = mid_ptr->next;
    mid_ptr->next = nullptr;

    while(scnd_ptr)
    {
        ListNode* tmp = scnd_ptr->next;
        scnd_ptr->next = rght_half;
        rght_half = scnd_ptr;
        scnd_ptr = tmp;
    }

    //rght_half - right head, head - left head, mid_ptr - middle
    while(rght_half != nullptr)
    {
        ListNode* tmp_left = head->next;
        ListNode* tmp_rght = rght_half->next;
        head->next = rght_half;
        rght_half->next = tmp_left;
        head = tmp_left;
        rght_half = tmp_rght;
    }
}

int main()
{

    cout << "Hello World!" << endl;
    return 0;
}
