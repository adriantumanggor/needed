#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head, *p;

void input();
void insertakhir();
void insertawal();
void after();
void tampil();
void cekdata();

int main()
{
    char jwb;

    puts("DLL INSERT AWAL");

    do
    {
        puts("");

        input();

        insertakhir();

        printf("Mau lagi(y/t):");
        scanf(" %c", &jwb);
    } while (jwb != 't');

    tampil();
    do
    {
        input();

        after();

        printf("Mau lagi(y/t):");
        scanf(" %c", &jwb);

        tampil();
    } while (jwb != 't');

    return 0;
}

void input()
{

    int data;

    printf("masukkan data:");
    scanf("%d", &data);

    p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
}

void insertakhir()
{
    Node *temp = head;

    if (temp == NULL)
    {
        insertawal();
    }

    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        p->prev = temp;
        temp->next = p;
    }
}

void insertawal()
{
    if (head != NULL)
    {
        p->next = head;
        head->prev = p;
    }
    head = p;
}

void tampil()
{
    Node *tampil = head;

    puts("");

    while (tampil != NULL)
    {
        printf("%d ", tampil->data);
        tampil = tampil->next;
    }

    puts("");
}

void after()
{
    Node *after = head;

    int key;

    cekdata();
    
    printf("masukkan setelah data? ");
    scanf("%d", &key);

    if (after->data == key && after->next == NULL)
    {
        insertakhir();
    }

    else
    {

        while (after->data != key)
        {
            after = after->next;
            if (after == NULL)
            {
                puts("Tidak ada data");
                return;
            }
        }

        p->next = after->next;
        p->prev = after;
        if (after->next != NULL)
        {
            after->next->prev = p;
        }
        after->next = p;
    }
}

void cekdata()
{
    if (head == NULL)
    {
        printf("\ntidak ada data\n");
        exit(1);
    }
}