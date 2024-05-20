#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct Itemtype
{
    int data;
    struct Itemtype *next;
} Itemtype;

typedef struct stack
{
    Itemtype *head;
    int count;
} stack;

void inisialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(int data, stack *s);
int pop(stack *s);
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
    s->head = NULL;
    s->count = 0;
}

void push(int data, stack *s)
{
    Itemtype *p;

    if (!penuh(s))
    {
        p = (Itemtype *)malloc(sizeof(Itemtype));
        p->data = data;
        p->next = s->head;
        s->head = p;
        s->count++;
    }
    else
    {
        puts("Data penuh tidak bisa isi");
    }
}

int pop(stack *s)
{
    Itemtype *pop;
    int data;

    if (!kosong(s))
    {
        pop = s->head;
        data = pop->data;

        s->head = pop->next;
        free(pop);
        s->count--;

        return data;
    }
    else
    {
        puts("Data Kosong tidak bisa mengambil");
        exit(1);
    }
}

void isi(stack *s)
{
    int data;
    printf("Masukkan Data anda:");
    scanf("%d", &data);
    push(data, s);
}

void ambil(stack *s)
{
    int data = pop(s);
    if (data != -1)
    {
        printf("\nItem yang anda ambil adalah %d\n", data);
    }
}

int kosong(stack *s)
{
    return (s->count == 0 ? 1 : 0);
}

int penuh(stack *s)
{
    return (s->count == max ? 1 : 0);
}

void tampil(stack *s)
{
    Itemtype *temp;
    if (!kosong(s))
    {
        printf("Isi stack saat ini\n");
        temp = s->head;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
    else
    {
        puts("Stack kosong");
    }
}
