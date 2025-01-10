#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *sorter(ListNode *l1, ListNode *l2)
{
    ListNode res;
    ListNode *curr = &res;

    res.next = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }

        // point current to latest inserted element

        curr = curr->next;
    }

    if (l1 != NULL)
    {
        curr->next = l1;
    }
    else if (l2 != NULL)
    {
        curr->next = l2;
    }

    return res.next;
}

int main()
{
    // Initialize two sorted lists
    ListNode l1, l2, l3, l4, l5, l6, *res;
    l1.val = 1;
    l2.val = 3;
    l3.val = 5;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = NULL;

    l4.val = 2;
    l5.val = 4;
    l6.val = 6;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = NULL;

    // Merge the two sorted lists
    res = sorter(&l1, &l4);

    // Print the merged list
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
    return 0;
}