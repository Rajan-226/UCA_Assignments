#include <stdlib.h>
#include <stdbool.h>
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    Node *dummy = head;
    Node *prev = NULL;

    while (dummy)
    {
        //denotes if this node is present at least two times in the list or not
        bool isDuplicate = 0;
        while (dummy->next && dummy->next->val == dummy->val)
        {
            Node *toRelease = dummy->next;
            dummy->next = dummy->next->next;
            free(toRelease);
            isDuplicate = 1;
        }

        //present in the least at least two times
        if (isDuplicate)
        {
            dummy = dummy->next;

            //if even the value of head node of the list was duplicated
            if (!prev)
                head = NULL;
            else
                prev->next = dummy;
        }
        else
        {
            //if no head till now, then dummy will be new head node now as it is not repeated
            if (!head)
                head = dummy;

            prev = dummy;
            dummy = dummy->next;
        }
    }
    return head;
}