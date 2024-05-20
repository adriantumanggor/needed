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
void tampil();
void deleteawal();
void bebaskan(Node *);
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
        printf("Lanjutkan (menghapus data dari posisi awal) ?:");
        scanf(" %c", &jwb);
        if (jwb == 't')
        {
            break;
        }
        deleteawal();
        tampil();

    } while (1);

    return 0;
}

void deleteawal()
{
    Node *hapus = head;
    if (hapus->next == NULL)
    {
        head = NULL;
        puts("Data habis");
        exit(0);
    }
    else
    {
        head = hapus->next;
        hapus->next->prev = NULL;
        bebaskan(hapus);
        
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