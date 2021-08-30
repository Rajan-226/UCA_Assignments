#include <stdlib.h>
#include <stdbool.h>

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;

    Node *dummy = head;

    //iterating until the end of one list
    while (l1 && l2)
    {
        //adding the node which have smaller value at this point
        if (l1->val < l2->val)
        {
            dummy->next = l1;
            l1 = l1->next;
        }
        else
        {
            dummy->next = l2;
            l2 = l2->next;
        }
        dummy = dummy->next;
    }

    //adding the remaining nodes of other list
    if (l1)
        dummy->next = l1;
    else if (l2)
        dummy->next = l2;

    return head->next;
}