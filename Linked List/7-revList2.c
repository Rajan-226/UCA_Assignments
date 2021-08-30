#include <stdlib.h>
#include <stdbool.h>

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode *reverseBetween(struct ListNode *head, int left, int right)
{
    if (left == right)
        return head;

    Node *dummy = (Node *)malloc(sizeof(Node));
    dummy->next = head;
    Node *dummyHead = dummy;
    int count = right - left + 1; //count of nodes to be reversed

    //traversing the list until previous of node starting position
    while (left > 1)
    {
        dummy = dummy->next;
        left--;
    }

    Node *start = dummy;
    Node *end = dummy->next;

    Node *prev = dummy;
    dummy = dummy->next;
    //reversing middle of the list
    while (count--)
    {
        Node *nextNode = dummy->next;
        dummy->next = prev;
        prev = dummy;
        dummy = nextNode;
    }
    end->next = dummy;  //linking the end of reversed list to next node
    start->next = prev; //linking the starting point to head of reversed list

    return dummyHead->next;
}