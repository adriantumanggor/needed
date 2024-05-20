#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} DNode;

DNode *head, *p;

void input();
void insertawal();
void insertakhir();
void after();
void before();
void tampil();
void menu();
void menuinsert();
void menudelete();
void deltertentu();
void delakhir();
void delawal();
void bebaskan(DNode *);
int cekdata(DNode *);

int main()
{
    int hasil;
    do
    {
        printf("\n\n");
        menu();
        tampil();
    } while (hasil != 1);

    return 0;
}

void menu()
{
    int pilih;

    puts("MENU SLL");
    puts("1. INSERT");
    puts("2. DELETE");
    puts("3. KELUAR");
    printf("pilih:");
    scanf("%d", &pilih);
    printf("\n");

    switch (pilih)
    {
    case 1:
        menuinsert();
        break;
    case 2:
        menudelete();
        break;
    case 3:
        exit(0);

    default:
        break;
    }
}

void menuinsert()
{
    int pilih;
    int key;

    puts("MENU INSERT");
    puts("1. AWAL");
    puts("2. AKHIR");
    puts("3. SEBELUM");
    puts("4. SESUDAH");
    printf("pilih:");
    scanf("%d", &pilih);
    printf("\n");

    input();

    switch (pilih)
    {
    case 1:
        insertawal();
        break;
    case 2:
        insertakhir();
        break;
    case 3:
        before();
        break;
    case 4:
        after();
        break;

    default:
        break;
    }
}

void menudelete()
{
    int pilih;

    puts("MENU DELETE");
    puts("1. AWAL");
    puts("2. AKHIR");
    puts("3. TERTENTU");
    printf("pilih:");
    scanf("%d", &pilih);
    printf("\n\n");


    switch (pilih)
    {
    case 1:
        delawal();
        break;
    case 2:
        delakhir();
        break;
    case 3:
        deltertentu();
        break;

    default:
        break;
    }
}

void input()
{
    int data;

    p = (DNode *)malloc(sizeof(DNode));

    printf("nilai yang akan disimpan:");
    scanf("%d", &data);

    p->data = data;
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
    DNode *temp = head;

    if (temp == NULL)
    {
        insertawal();
    }

    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        p->prev = temp;
        temp->next = p;
    }
}

void after()
{
    DNode *after = head;

    int key;

    cekdata(after);
    
    printf("masukkan setelah data? ");
    scanf("%d", &key);

    if (after->data == key && after->next == NULL)
    {
        insertakhir();
    }

    else
    {

        while (after->data != key)
        {
            after = after->next;
            if (after == NULL)
            {
                puts("Tidak ada data");
                return;
            }
        }

        p->next = after->next;
        p->prev = after;
        if (after->next != NULL)
        {
            after->next->prev = p;
        }
        after->next = p;
    }
}

void before()
{
    DNode *before = head;

    int key;

    cekdata(before);

    printf("masukkan sebelum data? ");
    scanf("%d", &key);

    if (before->data == key)
    {
        insertawal();
    }

    else
    {
        while (before->data != key)
        {
            before = before->next;
            if (before == NULL)
            {
                puts("Tidak ada data");
                return;
            }
        }

        p->next = before;
        p->prev = before->prev;
        before->prev->next = p;
        before->prev = p;
    }
}

void tampil()
{
    DNode *temp = head;
    puts("ISI SLL");
    cekdata(temp);

    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delawal()
{
    DNode *hapus = head;
    if (hapus->next == NULL)
    {
        head = NULL;
        puts("Data habis");
    }
    else
    {
        head = hapus->next;
        hapus->next->prev = NULL;
        bebaskan(hapus);
        
    }
}

void delakhir()
{
    DNode *temp = head;

    if (temp->next == NULL)
    {
        head = NULL;
        puts("Data habis");
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


void deltertentu()
{
    DNode *temp = head;
    int key, hasil;

    printf("\nMasukkan data yang ingin dihapus:");
    scanf("%d", &key);

    if (temp->data == key && temp->next == NULL)
    {
        head = NULL;
        puts("Data habis");
    }
    else
    {
        if (temp->data == key)
        {
            head = temp->next;
            temp->next->prev = NULL;
        }
        else
        {

            while (temp->data != key)
            {
                temp = temp->next;
                hasil = cekdata(temp);
                {
                if (hasil == 1)
                    return;
                }
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        bebaskan(temp);
    }
}

void bebaskan(DNode *x)
{
    free(x);
    x = NULL;
}

int cekdata(DNode *y)
{
    if (y == NULL)
    {
        printf("\ntidak ada data\n");
        return 1;
    }
    return 0;
}