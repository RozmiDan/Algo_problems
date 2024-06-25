#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    multimap<int, ListNode*> mp;

    for(ListNode* it : lists)
        if(it)
            mp.insert({it->val, it});

    ListNode* strt_node = nullptr;
    ListNode* cur_node = nullptr;

    while (!mp.empty())
    {
        // вытаскиваем наименьшую по значению node связываем ее с итоговым списком
        if(!strt_node) {
            strt_node = mp.begin()->second;
            cur_node = strt_node;
        }
        else {
            cur_node->next = mp.begin()->second;
            cur_node = cur_node->next;
        }
        // переходим в next и если он существ - добавляем в мапу, удаляем mp.begin()
        ListNode* tmp = nullptr;

        if(mp.begin()->second->next)
            tmp = mp.begin()->second->next;
        mp.erase(mp.begin());
        if(tmp)
            mp.insert({tmp->val,tmp});
    }
    return strt_node;

}

int main()
{
    map<int, ListNode*> mp;
    ListNode* a = new ListNode (23);
    mp.insert({a->val, a});

    cout << "Hello World!" << endl;
    return 0;
}
