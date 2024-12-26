#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *reverseLL(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *reversed = reverseLL(head->next);

    head->next->next = head;
    head->next = nullptr;
    return reversed;

    // reverseList(1) reversedRest = 5; 2->1
    // reverseList(2) reversedRest = 5; 3->2
    // reverseList(3) reversedRest = 5; 4->3
    // reverseList(4) reversedRest = 5; 5->4
    // reverseList(5) ^
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
    cout << endl;
    res = reverseLL(&l1);

    // Print the merged list
    while (res != NULL)
    {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}