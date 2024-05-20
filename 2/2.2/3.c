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
void insertakhir();
void input();
void tampil();
void after();
int main()
{
    char jwb;
    do
    {
        insertakhir();
        printf("ada data lagi(y/t):");
        scanf(" %c", &jwb);
        printf("\n");
    } while (jwb != 't');
    printf("\ningin memasukkan data setelah data ttt(y/t)");
    scanf(" %c", &jwb);
    if (jwb == 'y')
    {
        after();
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
void insertakhir()
{
    {
        input();
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
}
void after()
{
    int key;
    input();
    printf("ingin memasukkan data setelah nomor berapa:");
    scanf("%d", &key);
    Node *temp = head;
    while (temp->no != key)
    {
        if (temp == NULL)
        {
            printf("\nData tidak ada\n");
            return;
        }

        temp = temp->next;
    }
    p->next = temp->next;
    temp->next = p;
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