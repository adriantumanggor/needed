#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa
{
    int no;
    char nama[20];
    float nilai;
    struct siswa *next;
} Node;

Node *head = NULL, *p;

void input();
void insertawal();
void tampil();

int main()
{
    char jwb;
    
    puts("Linked list Data Struct");
    puts("Insert Awal");

    printf("\n");
    do
    {
        insertawal();
    
        printf("Ada data lagi(y/t):");
        scanf(" %c", &jwb);
    
        printf("\n");
    } while (jwb != 't');

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
    input();
    if (head != NULL)
    {
        p->next = head;
    }
    head = p;
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