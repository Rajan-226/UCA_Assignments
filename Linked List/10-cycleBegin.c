#include <stdlib.h>
#include <stdbool.h>

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode *detectCycle(struct ListNode *head)
{
    //if number of nodes <= 1
    if (!head || !head->next)
        return NULL;

    Node *fast = head->next;
    Node *slow = head;

    //moving until slow and fast pointer becomes equal or until end of list
    while (fast && fast->next && slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (!fast || !fast->next)
        return NULL;

    fast = fast->next;
    slow = head;

    //covering same distance from front and meeting point of slow and fast
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}