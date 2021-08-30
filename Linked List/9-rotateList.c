#include <stdlib.h>
#include <stdbool.h>

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

//returns the length of the linked list
int length(Node *head)
{
    int size = 0;
    while (head)
    {
        head = head->next;
        size++;
    }
    return size;
}

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    //no node in the list or no node is to be rotated
    if (!head || k == 0)
        return head;

    int size = length(head); //size of linked list
    k %= size;

    //no node is to be rotated
    if (k == 0)
        return head;

    int posFromFront = size - k - 1;
    Node *end; //end of the list
    Node *dummy = head;

    //traversing the list to find the ending point
    //of the rotated list and last node in the list
    while (dummy->next)
    {
        if (posFromFront == 0)
            end = dummy;
        posFromFront--;
        dummy = dummy->next;
    }

    //fixing the links of nodes
    Node *newHead = end->next;
    end->next = NULL;
    dummy->next = head;

    return newHead;
}