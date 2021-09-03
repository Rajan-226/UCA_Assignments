#ifndef listH
#define listH

struct listNode
{
    struct listNode *next;
    char *data;
};

int isPresent(char *);

void insert(char *);

#endif
