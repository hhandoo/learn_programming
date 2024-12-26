#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *removeElements(ListNode *head, int val)
{
    if (!head)
        return nullptr;
    head->next = removeElements(head->next, val);
    return head->val == val ? head->next : head;
}

int main()
{

    ListNode l1, l2, l3, *res;
    l1.val = 1;
    l2.val = 2;
    l3.val = 4;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = NULL;

    // Merge the two sorted lists
    res = removeElements(&l1, 2);

    // Print the merged list
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}