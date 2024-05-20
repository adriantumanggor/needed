#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL, *p;

void input(int);
void insertakhir();
void tampil();

int main()
{
    puts("Single linked list - insert akhir");
    int data;
    char jwb;
    do
    {
        printf("\nmasukkan data:");
        scanf("%d", &data);
        
        input(data);

        printf("lagi(y/t)?:");
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
    insertakhir();
}

void insertakhir()
{
    if (head == NULL)
    {
        head  = p;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}
void tampil()
{
    Node *temp = head;
    puts("\nHasil data:");
    while (temp != NULL)
    {
        printf("\n%d\n", temp->data);
        temp = temp->next;
    }
}