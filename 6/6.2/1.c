#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef int Konversi;
typedef struct stack
{
    Konversi data[max];
    int count;
} stack;

void menu(stack *, int);
void biner(int, stack *);
void oktal(int, stack *);
void hexades(int, stack *);
void push(Konversi, stack *s);
Konversi pop(stack *);
void inisiasi(stack *);
int kosong(stack *);
int penuh(stack *);
void tampil(stack *);

int main()
{
    stack Bilangan;
    int desimal;

    inisiasi(&Bilangan);

    printf("\nMasukkan bil desimal yang ingin dikonversi:");
    scanf("%d", &desimal);

    do
    {
        menu(&Bilangan, desimal);
    } while (1);

    return 0;
}

void menu(stack *s, int desimal)
{
    int pilih;

    puts("\nMenu konversi bilangan:");
    puts("1. Biner");
    puts("2. Oktal");
    puts("3. Heksadesimal");
    puts("4. Keluar");

    printf("\nMasukkan pilihan:");
    scanf("%d", &pilih);

    switch (pilih)
    {
    case 1:
        biner(desimal, s);
        break;
    case 2:
        oktal(desimal, s);
        break;
    case 3:
        hexades(desimal, s);
        break;
    case 4:
        exit(0);

    default:
        break;
    }

    tampil(s);
}

void biner(int desimal, stack *s)
{
    int biner;

    while (desimal > 0 && !penuh(s))
    {
        biner = desimal % 2;
        push(biner, s);
        desimal = desimal / 2;
    }
}

void oktal(int desimal, stack *s)
{
    int oktal;

    while (desimal > 0 && !penuh(s))
    {
        oktal = desimal % 8;
        push(oktal, s);
        desimal = desimal / 8;
    }
}

void hexades(int desimal, stack *s)
{
    int hexa;

    while (desimal > 0 && !penuh(s))
    {
        hexa = desimal % 16;
        push(hexa, s);
        desimal = desimal / 16;
    }
}

void push(Konversi nilai, stack *s)
{
    s->data[s->count] = nilai;

    s->count++;
}

Konversi pop(stack *s)
{
    s->count--;

    return s->data[s->count];
}

void inisiasi(stack *s)
{
    s->count = 0;
}

void tampil(stack *s)
{
    Konversi tampil;

    printf("\n Hasil: ");

    while (!kosong(s))
    {
        tampil = pop(s);

        switch (tampil)
        {
        case 10:    
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;

        default:
            printf("%d", tampil);
            break;
        }
    }
}

int kosong(stack *s)
{
    return (s->count == 0);
}
int penuh(stack *s)
{
    return (s->count == max);
}
