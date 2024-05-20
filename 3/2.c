#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head, *p;

void input();
void insertakhir();
void tampil();
void deleteakhir();
void bebaskan(Node *);
void last();
void cekdata();

int main()
{
    char jwb;
    int data, hasil;

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

    } while (1);

    return 0;
}

void deleteakhir()
{
    Node *temp = head, *pbef = NULL;

    if (temp->next == NULL)
    {
        last();
        puts("Data habis");
        exit(0);
    }
    else
    {
        while (temp->next != NULL)
        {
            pbef = temp;
            temp = temp->next;
        }

        pbef->next = NULL;
        bebaskan(temp);
        pbef = NULL;
    }
    tampil();
}

void input()
{
    int data;

    p = (Node *)malloc(sizeof(Node));

    printf("masukkan data:");
    scanf("%d", &data);

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

void last()
{
    free(head);
    head = NULL;
}

void cekdata()
{
    if (head == NULL)
    {
        printf("\ntidak ada data\n");
        exit(1);
    }
}