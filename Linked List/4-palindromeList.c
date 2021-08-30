#include <stdlib.h>
#include <stdbool.h>
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

//This function reverses a linked list and returns the new head
Node *reverse(Node *head)
{
    Node *previousNode = NULL;
    while (head)
    {
        Node *temp = head->next;
        head->next = previousNode;
        previousNode = head;
        head = temp;
    }
    return previousNode;
}

bool isPalindrome(struct ListNode *head)
{
    Node *slow = (Node *)malloc(sizeof(Node));
    Node *fast = (Node *)malloc(sizeof(Node));
    fast->next = head;
    slow->next = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //At this point, slow node is pointing to:
    //exact middle of the list in case of odd number of nodes
    //last node of first half of list in case of even number of nodes
    slow = slow->next;

    Node *reversedSecondHalf = reverse(slow);
    slow = head;
    while (reversedSecondHalf)
    {
        if (reversedSecondHalf->val != slow->val)
            return 0;
        reversedSecondHalf = reversedSecondHalf->next;
        slow = slow->next;
    }
    return 1;
}