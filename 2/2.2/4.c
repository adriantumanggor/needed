#include <stdio.h>
#include <stdlib.h>
typedef struct siswa
{
    int no;
    char nama[20];
    float nilai;
    struct siswa *next;
} Node;
Node *head, *p;
void insertawal();
void input();
void tampil();
void before();
int main()
{
    char jwb;
    do
    {
        input();
        insertawal();
        printf("ada data lagi(y/t):");
        scanf(" %c", &jwb);
        printf("\n");
    } while (jwb != 't');
    printf("\ningin memasukkan data sebelum data ttt(y/t)");
    scanf(" %c", &jwb);
    if (jwb == 'y')
    {
        before();
    }
    tampil();
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
void insertawal()
{
    if (head != NULL)
    {
        p->next = head;
    }
    head = p;
}

void before()
{
    int key;
    printf("ingin memasukkan data sebelum nomor berapa:");
    scanf("%d", &key);
    input();
    Node *temp = head, *tempp;
    if (temp->no == key)
    {
        insertawal();
        return;
    }
    while (temp->no != key)
    {
        tempp = temp;
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nData tidak ada\n");
            return;
        }
    }
    p->next = temp;
    tempp->next = p;
}
void tampil()
{
    Node *temp = head;
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
}