/*
 *
 * Program for https://leetcode.com/problems/sliding-window-maximum/
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <assert.h>
#include <assert.h>

int *deque;
int front = -1, rear = -1;
int size;

// Return 1 if the deque is empty, else return 0
// Time Complexity: O(1)
int is_empty()
{
    return front == -1;
}

// Return 1 if the deque is full, else return 0
// Time Complexity: O(1)
int is_Full()
{
    return ((front == 0 && rear == size - 1) ||
            front == rear + 1);
}

// Adds a new element to the front of the deque
// Time Complexity: O(1)
void pushFront(int value)
{
    assert(!is_Full());

    //first insertion
    if (is_empty())
    {
        front = 0;
        rear = 0;
    }
    else
        front = front - 1;

    if (front < 0)
        front = size - 1;

    deque[front] = value;
}

// Adds a new element to the back of the deque
// Time Complexity: O(1)
void pushBack(int value)
{
    assert(!is_Full());

    //first insertion
    if (is_empty())
    {
        front = 0;
        rear = 0;
    }
    else
        rear = (rear + 1) % size;

    deque[rear] = value;
}

// Remove and return the element at the front of the deque.
// Time Complexity: O(1)
int popFront()
{
    //deque is not empty;
    assert(!is_empty());

    int temp = deque[front];

    //resetting deque to empty
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    return temp;
}

// Remove and return the element at the back of the deque.
// Time Complexity: O(1)
int popBack()
{
    //deque is not empty;
    assert(!is_empty());

    int temp = deque[rear];

    //resetting deque to empty
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        rear--;
    }
    if (rear < 0)
        rear = size - 1;

    return temp;
}

// Return but not remove the element at the front of the deque.
// Time Complexity: O(1)
int Front()
{
    assert(!is_empty()); //deque is not empty;

    return deque[front];
}

// Return but not remove the element at the back of the deque.
// Time Complexity: O(1)
int Back()
{
    assert(!is_empty() && rear >= 0); //deque is not empty;

    return deque[rear];
}

/*
 * Keep a monotonincally decreasing deque and move window of size k
 */
int *maxSlidingWindow(int *nums, int numsSize, int k, int *returnSize)
{
    size = k;
    front = rear = -1;
    deque = (int *)malloc(sizeof(int) * k);
    int *ans = (int *)malloc(sizeof(int) * (numsSize - k + 1));
    *returnSize = numsSize - k + 1;

    for (int i = 0; i < numsSize; i++)
    {
        //removing indices out of current window
        while (!is_empty() && Front() <= (i - k))
            popFront();

        //removing the smaller elements than this element in window
        while (!is_empty() && nums[i] >= nums[Back()])
            popBack();

        //pushing the new index
        pushBack(i);

        //if we have processed k elements till now
        if (i >= (k - 1))
            ans[i - (k - 1)] = nums[Front()];
    }

    return ans;
}