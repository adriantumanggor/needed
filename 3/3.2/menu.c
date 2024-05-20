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
void last();
void bebaskan(Node *);
void cekdata();

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

    printf("\n\n");

    switch (pilih)
    {
    case 1:
        input();
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

    printf("\n\n");

    switch (pilih)
    {
    case 1:
        insertawal();
        break;
    case 2:
        insertakhir();
        break;
    case 3:
        cekdata();
        before();
        break;
    case 4:
        cekdata();
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

    cekdata();

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

void after()
{
    Node *temp = head;
    int key;

    printf("\ndata ingin dimasukkan sesudah Node berapa?");
    scanf("%d", &key);

    cekdata();

    while (temp->no != key)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            puts("Tidak ada data");
            exit(1);
        }
    }

    p->next = temp->next;
    temp->next = p;
}

void before()
{
    Node *temp = head, *pbef = NULL;
    int key;

    printf("\ndata ingin dimasukkan sebelum Node berapa?");
    scanf("%d", &key);

    cekdata();

    if (temp->no == key)
    {
        insertawal();
    }

    else
    {
        while (temp->no != key)
        {
            pbef = temp;
            temp = temp->next;
            if (temp == NULL)
            {
                puts("Tidak ada data");
                exit(1);
            }
        }

        p->next = temp;
        pbef->next = p;
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

void delawal()
{
    Node *temp = head;
    puts("Menghapus data posisi awal...");

    if (temp->next == NULL)
    {
        last();
        puts("Data habis");
    }
    else
    {
        head = temp->next;
        bebaskan(temp);
    }
}

void delakhir()
{
    Node *temp = head, *pbef = NULL;
    puts("Menghapus data posisi akhir...");

    if (temp->next == NULL)
    {
        last();
        puts("Data habis");
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
}

void deltertentu()
{
    Node *temp = head, *pbef = NULL;
    int key;

    printf("Data yang ingin dihapus?:");
    scanf("%d", &key);

    printf("\n");

    if (temp->next == NULL)
    {
        last();
        puts("Data habis");
    }

    else
    {
        if (temp->no == key)
        {
            pbef = head;
            head = temp->next;
            bebaskan(pbef);
        }

        else
        {
            while (temp->no != key)
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
}

void last()
{
    free(head);
    head = NULL;
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
    }
}