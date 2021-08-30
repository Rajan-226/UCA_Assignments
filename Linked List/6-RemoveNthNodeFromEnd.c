#include <stdlib.h>
#include <stdbool.h>

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

//Single traversal with tortoise-hare optimization
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    Node *dummy = (Node *)malloc(sizeof(Node));
    dummy->next = head;
    Node *newHead = dummy;

    int mid = 0;
    Node *slow = dummy;
    Node *fast = dummy;

    while (fast && fast->next)
    {
        mid++;
        slow = slow->next;
        fast = fast->next->next;
    }

    //At this point, slow node is pointing to:
    //exact middle of the list in case of odd number of nodes
    //last node of first half of list in case of even number of nodes
    int size = mid * 2;
    if (!fast) //odd length
        size--;

    n = size - n; //position from front
    if (n >= mid)
    {
        n -= mid;
        dummy = slow;   //skipping first half of nodes
    }

    while (n--)
        dummy = dummy->next;

    Node *toFree = dummy->next;
    dummy->next = dummy->next->next;
    free(toFree);

    return newHead->next;
}