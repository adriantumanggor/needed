#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node *buat()
{
    int data;
    Node *baru = (Node *)malloc(sizeof(Node));
    if (baru == NULL)
    {
        printf("\ngagal\n");
        exit(1);
    }
    printf("\nnilai yang akan disimpan:");
    scanf("%d", &data);
    baru->data = data;
    baru->next = NULL;
    return baru;
}

void insertawal();
void insertakhir();
void before();
void after();
int menu();
void tampil();

int main()
{
    int finish;
    puts("SSL king");
    printf("\n");
    do
    {
        finish = menu();
        printf("\n");
        tampil();
    } while (finish != 0);

    return 0;
}

void insertawal()
{
    Node *awal = buat();
    if (head != NULL)
        awal->next = head;
    head = awal;
}
void insertakhir()
{
    Node *akhir = buat();
    if (head == NULL)
    {
        head = akhir;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = akhir;
    }
}
void after()
{
    int key;
    Node *after = buat();
    printf("disisipkan sesudah nilai?");
    scanf("%d", &key);
    Node *temp = head;
    while (temp->data != key)
    {
        temp = temp->next;
    }
    after->next = temp->next;
    temp->next = after;
}
void before()
{
    int key;
    Node *before = buat();
    Node *temp = head, *tempp = NULL;
    printf("disisipkan sebelum nilai?");
    scanf("%d", &key);
    while (temp != NULL && temp->data != key)
    {
        tempp = temp;
        temp = temp->next;
    }
    before->next = temp;
    if (tempp == NULL)
    {
        head = before;
    }
    else
    {
        tempp->next = before;
    }
}
void tampil()
{
    Node *temp = head;
    printf("\nData SSL:");
    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int menu()
{
    char pilih;

    printf("\nPILIH MENU INSERT\n");
    printf("\n1. awal\n");
    printf("\n2. akhir\n");
    printf("\n3. sebelum\n");
    printf("\n4. sesudah\n");
    printf("\n5. keluar\n");
    printf("\npilihan:");
    scanf(" %c", &pilih);
    printf("\n");
    switch (pilih)
    {
    case '1':
        insertawal();
        return 1;
    case '2':
        insertakhir();
        return 1;
    case '3':
        if (head == NULL)
        {
            printf("SSL kosong tidak bisa meng insert before");
            return 1;
        }
        before();
        return 1;
    case '4':
        if (head == NULL)
        {
            printf("SSL kosong tidak bisa meng insert after");
            return 1;
        }
        after();
        return 1;
    case '5':
        return 0;
    }
}