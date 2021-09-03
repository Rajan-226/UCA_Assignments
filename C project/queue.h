//node of tree-linked list
struct tempNode
{
    struct tempNode *next; //pointer to next node of the list
    struct tempNode *parent;
    char *val;    //value contained by the node
    int valMoved; //value moved to occupy the empty space
};

typedef struct tempNode queueNode;

//queue node
typedef struct
{
    queueNode *front; //front of the queue
    queueNode *rear;  //rear of the queue
    int size;
} Queue;

int is_empty();

void enqueue(char *, int, queueNode *);

void dequeue();

char *frontVal();

queueNode *frontNode();

int queueSize();

void initializeQueue();

queueNode *reversePath(queueNode *head);
