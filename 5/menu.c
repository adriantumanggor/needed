#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL, *p;

void menu();
void tampil();
void insert();
void input();
void delete();
void cari();
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

    puts("\nPILIH MENU\n");
    puts("1.Penambahan secara terurut");
    puts("2.Pencarian data");
    puts("3.Penghapusan data");
    puts("4.Keluar");

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
        delete();
        break;
    default:
        exit(0);
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

void input()
{
    int data;

    printf("\nMasukkan data:");
    scanf("%d", &data);

    p = (Node *)malloc(sizeof(Node));
    p->data = data;
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
            if (p->data >= temp->data)
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
            if (p->data < temp->data)
            {
                p->next = head;
                head = p;
            }
            else
            {

                while (p->data > temp->data && temp->next != NULL)
                {
                    bef = temp;
                    temp = temp->next;
                }

                if (p->data >= temp->data)
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
}

void cari()
{
    Node *cari = head;
    int key, jumlah = 0;

    printf("Masukkan data yang ingin dicari:");
    scanf("%d", &key);

    if (cari->next == NULL && cari->data == key)
    {
        jumlah++;
    }
    else
    {
        while (cari != NULL)
        {
            if (cari->data == key)
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

void delete()
{
    Node *temp = head, *pbef = NULL;
    int key;

    printf("Data yang ingin dihapus?:");
    scanf("%d", &key);

    printf("\n");

    if (temp->next == NULL && temp->data == key)
    {
        head = NULL;
        puts("Data habis");
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
                    printf("Data %d Tidak ada dalam LL\n", key);
                    return;
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
