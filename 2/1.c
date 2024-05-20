#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL, *p;

void input(int);

void awal();

void tampil();

int main()
{
    char jwb;
    int data;
    do
    {
        printf("\nmasukkan int:");
        scanf("%d", &data);

        input(data);

        printf("masukkan data lagi(y/t):");
        scanf(" %c", &jwb);
    } while (jwb != 't');

    tampil();
    return 0;
}

void input(int data)
{
    p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    awal();
}

void awal()
{
    if (head != NULL)
        p->next = head;
    head = p;
}

void tampil()
{
    Node *temp = head;
    puts("Single link list - insert awal");
    while (temp != NULL)
    {   
        printf("\n%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
