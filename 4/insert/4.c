#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} DNode;

DNode *head, *p;

void input();
void insertakhir();
void insertawal();
void after();
void before();
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

        before();

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

    p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
}

void insertakhir()
{
    DNode *temp = head;

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
    DNode *tampil = head;

    puts("");

    while (tampil != NULL)
    {
        printf("%d ", tampil->data);
        tampil = tampil->next;
    }

    puts("");
}

void before()
{
    DNode *before = head;

    int key;

    cekdata();

    printf("masukkan sebelum data? ");
    scanf("%d", &key);

    if (before->data == key)
    {
        insertawal();
    }

    else
    {
        while (before->data != key)
        {
            before = before->next;
            if (before == NULL)
            {
                puts("Tidak ada data");
                return;
            }
        }

        p->next = before;
        p->prev = before->prev;
        before->prev->next = p;
        before->prev = p;
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