#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *sorter(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }

    if (l2 == NULL)
    {
        return l1;
    }

    if (l1->val <= l2->val)
    {
        l1->next = sorter(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = sorter(l1, l2->next);
        return l2;
    }
}

int main()
{
    // Initialize two sorted lists
    // refer: https://www.youtube.com/watch?v=bdWOmYL5d1g
    ListNode l1, l2, l3, l4, l5, l6, *res;
    l1.val = 1;
    l2.val = 2;
    l3.val = 4;
    l1.next = &l2;
    l2.next = &l3;
    l3.next = NULL;

    l4.val = 1;
    l5.val = 3;
    l6.val = 4;
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
}