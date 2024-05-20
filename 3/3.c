#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL, *p = NULL;

void input();
void insertakhir();
void tampil();
void deletetertentu();
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

    puts("Menghapus Data tertentu");
    printf("\n");

    do
    {
        cekdata();
        deletetertentu();

        printf("Lanjutkan (y/t) ?:");
        scanf(" %c", &jwb);

    } while (jwb != 't');

    return 0;
}

void deletetertentu()
{
    Node *temp = head, *pbef = NULL;
    int key;

    printf("Data yang ingin dihapus?:");
    scanf("%d", &key);

    printf("\n");

    if (temp->next == NULL && temp->data == key)
    {
        last();
        puts("Data habis");
        exit(0);
    }

    else
    {
        if (temp->data == key)
        {
            pbef = head;
            head = temp->next;
            bebaskan(pbef);
        }

        else
        {
            while (temp->data != key)
            {
                pbef = temp;
                temp = temp->next;
                if (temp == NULL)
                {
                    puts("Tidak ada data");
                    exit(1);
                }
            }
            
            pbef->next = temp->next;
            bebaskan(temp);
        }
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