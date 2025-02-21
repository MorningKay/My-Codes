#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct Node
{
    ElemType character;
    struct Node *next;
}Node;

int main(void)
{
    Node *header = NULL;
    ElemType Item;
    for (int i = 0; i < 6; i++)
    {
        Node *p = malloc(sizeof(Node));
        if (p == NULL)
            return 1;
        printf("Type in: ");
        scanf("%c", &Item);
        getchar();
        p->character = Item;
        p->next = NULL;
        if (header == NULL)
        {
            header = p;
        }
        else
        {
            Node *q = header;
            while (q->next != NULL)
            {
                q = q->next;
            }
            q->next = p;
        }
    }
    Node *m = header;
    while (m->next != NULL)
    {
        printf("%c-->", m->character);
        m = m->next;
    }
    printf("%c\n", m->character);
    return 0;
}
