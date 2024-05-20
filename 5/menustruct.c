#include <stdio.h>
#include <stdlib.h>

typedef struct siswa
{
    int no;
    char nama[20];
    float nilai;
    struct siswa *next;
} Node;

Node *head = NULL, *p;

void menu();
void tampil();
void insert();
void input();
void delete();
void cari();
void rata();
void bebaskan(Node *);

int main()
{
    puts("INSERT DELETE SLL");

    do
    {
        menu();
        tampil();
    } while (1);

    return 0;
}

void menu()
{
    int pilih;

    puts("PILIH MENU\n");
    puts("1.Penambahan secara terurut");
    puts("2.Pencarian data");
    puts("3.Penghapusan data");
    puts("4.Rata-rata");
    puts("5.Keluar");

    printf("Masukkan pilihan:");
    scanf("%d", &pilih);

    switch (pilih)
    {
    case 1:
        input();
        insert();
        break;
    case 2:
        cari();
        break;
    case 3:
        delete ();
        break;
    case 4:
        rata();
        break;

    default:
        exit(0);
    }
}

void rata()
{
    Node *nilai = head;
    float jumlahnilai, hasil = 0;

    while (nilai != NULL)
    {
        hasil += nilai->nilai;
        jumlahnilai++;
        nilai = nilai->next;
    }

    hasil = hasil / jumlahnilai;
    printf("\nNilai rata-ratanya adalah: %g\n", hasil);
}

void cari()
{
    Node *cari = head;
    int key, jumlah = 0;

    printf("Masukkan data yang ingin dicari:");
    scanf("%d", &key);

    if (cari->next == NULL && cari->no == key)
    {
        jumlah++;
    }
    else
    {
        while (cari != NULL)
        {
            if (cari->no == key)
            {
                jumlah++;
            }
            cari = cari->next;
        }
    }
    if (jumlah == 0)
    {
        printf("\nData %d tidak ada dalam LL\n", key);
    }
    else
    {

        printf("\nData %d ketemu sebanyak %d kali\n", key, jumlah);
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
        printf("\n%d\t%s\t%g\n",
               temp->no,
               temp->nama,
               temp->nilai);
        temp = temp->next;
    }
    printf("\n");
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

void insert()
{
    Node *temp = head, *bef;

    if (temp == NULL)
    {
        head = p;
    }
    else
    {
        if (temp->next == NULL)
        {
            if (p->no >= temp->no)
            {
                temp->next = p;
            }
            else
            {
                p->next = temp;
                head = p;
            }
        }

        else
        {

            while (p->no > temp->no && temp->next != NULL)
            {
                bef = temp;
                temp = temp->next;
            }

            if (p->no >= temp->no)
            {
                p->next = temp->next;
                temp->next = p;
            }
            else
            {
                p->next = temp;
                bef->next = p;
            }
        }
    }
}

void delete()
{
    Node *temp = head, *pbef = NULL;
    int key;

    printf("Data yang ingin dihapus?:");
    scanf("%d", &key);

    printf("\n");

    if (temp->next == NULL && temp->no == key)
    {
        head = NULL;
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

void bebaskan(Node *x)
{
    free(x);
    x = NULL;
}
