#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int Itemtype;
typedef struct stack
{
    Itemtype data[MAX];
    int count;
} stack;

void inisialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(Itemtype, stack *s);
Itemtype pop(stack *s);
void ambil(stack *s);
void tampil(stack *s);
void menu(stack *s);
void isi(stack *s);

int main()
{
    stack tumpukan;

    inisialisasi(&tumpukan);

    do
    {
        menu(&tumpukan);
    } while (1);

    return 0;
}

void menu(stack *s)
{
    int pilihan;

    puts("");
    puts("Menu stack using Array");
    puts("1. Mengisi stack (push)");
    puts("2. Mengambil isi stack (pop)");
    puts("3. Menampilkan isi stack LIFO");
    puts("4. Keluar");

    printf("Masukkan pilihan anda:");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        isi(s);
        break;
    case 2:
        ambil(s);
        break;
    case 3:
        tampil(s);
        break;
    case 4:
        exit(0);

    default:
        break;
    }
}

void inisialisasi(stack *s)
{
    s->count = 0;
}

void push(Itemtype data, stack *s)
{
    s->data[s->count] = data;

    s->count++;
}

Itemtype pop(stack *s)
{
    Itemtype data;

    s->count--;

    data = s->data[s->count];

    return data;
}

void isi(stack *s)
{
    Itemtype data;

    if (!penuh(s))
    {
        printf("Masukkan Data anda:");
        scanf("%d", &data);

        push(data, s);
    }
    else
    {
        puts("Data penuh tidak bisa isi");
    }
}

void ambil(stack *s)
{
    Itemtype data;

    if (!kosong(s))
    {
        data = pop(s);
        printf("\nItem yang anda ambil adalah %d\n", data);
    }
    else
    {
        puts("Data Kosong tidak bisa mengambil");
    }
}

int kosong(stack *s)
{
    return (s->count == 0 ? 1 : 0);
}

int penuh(stack *s)
{
    return (s->count == MAX ? 1 : 0);
}

void tampil(stack *s)
{
    if (!kosong(s))
    {
        printf("Isi stack saat ini\n");
        for (int i = s->count - 1; i >= 0; i--)
        {
            printf("%d\n", s->data[i]);
        }
    }
    else
    {
        puts("Stack kosong");
    }
}
