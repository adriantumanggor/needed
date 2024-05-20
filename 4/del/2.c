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
void bebaskan(Node *);
void last();
void cekdata();

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

    do
    {
        cekdata();
        printf("Lanjutkan (menghapus data dari posisi akhir) ?:");
        scanf(" %c", &jwb);
        if (jwb == 't')
        {
            break;
        }
        deleteakhir();
        tampil();

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

void cekdata()
{
    if (head == NULL)
    {
        printf("\ntidak ada data\n");
        exit(1);
    }
}