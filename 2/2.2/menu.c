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
void insertakhir();
void input();
void tampil();
void before();
void after();
int menu();

int main()
{
    int jwb;
    do
    {
        jwb = menu();
        printf("\n");
        tampil();
    } while (jwb != 0);
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
    input();
    if (head != NULL)
    {
        p->next = head;
    }
    head = p;
}
void insertakhir()
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
void after()
{
    int key;
    printf("ingin memasukkan data setelah nomor berapa:");
    scanf("%d", &key);
    input();
    Node *temp = head;
    while (temp->no != key)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nData tidak ada\n");
            return;
        }
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