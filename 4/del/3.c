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
void insertawal();
void insertakhir();
void tampil();
void deleteakhir();
void tertentu();
void bebaskan(Node *);
void last();
int cekdata(Node *);

int main()
{
    char jwb;

    puts("Single Linked List - Insert di Akhir");

    do
    {
        printf("\n");

        input();

        insertakhir();

        printf("apakah ada lagi(y/t):");
        scanf(" %c", &jwb);

    } while (jwb != 't');

    tampil();

    puts("Delete tertentu");

    do
    {
        tertentu();
        tampil();

        printf("Lanjutkan ?:");
        scanf(" %c", &jwb);
        if (jwb == 't')
        {
            break;
        }

    } while (1);

    return 0;
}

void deleteakhir()
{
    Node *temp = head;

    if (temp->next == NULL)
    {
        head = NULL;
        puts("Data habis");
        exit(0);
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        bebaskan(temp);
    }
}

void tertentu()
{
    Node *temp = head;
    int key, hasil;

    printf("\nMasukkan data yang ingin dihapus:");
    scanf("%d", &key);

    if (temp->data == key && temp->next == NULL)
    {
        head = NULL;
        puts("Data habis");
        exit(0);
    }
    else
    {
        if (temp->data == key)
        {
            head = temp->next;
            temp->next->prev = NULL;
        }
        else
        {

            while (temp->data != key)
            {
                temp = temp->next;
                hasil = cekdata(temp);
                {
                if (hasil == 1)
                    return;
                }
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        bebaskan(temp);
    }
}

void input()
{
    int data;

    p = (Node *)malloc(sizeof(Node));

    printf("masukkan data:");
    scanf("%d", &data);

    p->data = data;
    p->prev = NULL;
    p->next = NULL;
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
            temp = temp->next;

        p->prev = temp;
        temp->next = p;
    }
}

void tampil()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void bebaskan(Node *x)
{
    free(x);
    x = NULL;
}

int cekdata(Node *y)
{
    if (y == NULL)
    {
        printf("\ntidak ada data\n");
        return 1;
    }
    return 0;
}