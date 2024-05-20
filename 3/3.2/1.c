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
void deleteawal();
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

        printf("Lanjutkan (menghapus data dari posisi awal) ?:");
        scanf(" %c", &jwb);

        if (jwb == 't')
        {
            tampil();
            break;
        }

        deleteawal();

    } while (1);

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

    if (temp == NULL)
    {
        printf("\nKOSONG\n");
        return;
    }

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

void deleteawal()
{
    Node *temp = head;
    if (temp->next == NULL)
    {
        last();
        puts("Data habis");
        exit(0);
    }
    else
    {
        head = temp->next;
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