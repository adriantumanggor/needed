#include <stdio.h>
#include <stdlib.h>

typedef struct siswa
{
    int no;
    char nama[20];
    float nilai;
    struct siswa *next;
} Node;

Node *head = NULL, *p = NULL;

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
        deletetertentu();

        printf("Lanjutkan (y/t) ?:");
        scanf(" %c", &jwb);

    } while (jwb != 't');

    return 0;
}

void input()
{
    p = (Node *)malloc(sizeof(Node));

    printf("No     :");
    scanf("%d", &p->no);
    getchar();

    printf("Nama   :");
    scanf("%s", &p->nama);
    getchar();

    printf("Nilai  :");
    scanf("%f", &p->nilai);
    getchar();

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

    cekdata();
    
    printf("\nData yang telah diinputkan\n");

    printf("No\tNama\tNilai");

    while (temp != NULL)
    {
        printf("\n%d\t%s\t%.2f\n",
               temp->no,
               temp->nama,
               temp->nilai);
        temp = temp->next;
    }
    printf("\n");
}

void bebaskan(Node *x)
{
    free(x);
    x = NULL;
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
    }

    tampil();
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