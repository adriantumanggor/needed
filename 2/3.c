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
void after(int);

int main()
{
    char jwb;
    int data;

    do
    {
        printf("\nmasukan data:");
        scanf("%d", &data);
        input(data);
        insertakhir();
        printf("lagi(y/t)?:");
        scanf(" %c", &jwb);
    } while (jwb != 't');
    tampil();

    printf("nilai yang akan disimpan:");
    scanf("%d", &data);
    after(data);

    tampil();
    return 0;
}
void input(int data)
{
    p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
}
void insertakhir()
{
    if (head == NULL)
    {
        head = p;
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
void after(int data)
{
    if (head == NULL)
    {
        printf("\nSSL KOSONG TIDAK BISA INSERT AFTER\n");
    }

    int key;
    input(data);
    printf("disispkan setelah data berafah?");
    scanf("%d", &key);
    Node *temp = head;
    while (temp->data != key)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nData tidak ditemukan.\n");
            return;
        }
    }

    p->next = temp->next;
    temp->next = p;
}

