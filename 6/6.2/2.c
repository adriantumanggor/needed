#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 50

typedef char Karakter;
typedef struct stack
{
    Karakter huruf[max];
    int count;
} stack;

void inisiasi(stack *);
void push(Karakter, stack *);
Karakter pop(stack *);
int penuh(stack *);
int kosong(stack *);
int cekPalindrom(stack *, char *);

int main()
{
    stack Palindrom;
    Karakter kalimat[max];
    char jawab;

    inisiasi(&Palindrom);

    do
    {
        printf("\nMasukkan kata yang dicek: ");
        fgets(kalimat, sizeof(kalimat), stdin);

        if (cekPalindrom(&Palindrom, kalimat))
        {
            printf("\n%s adalah palindrom.\n", kalimat);
        }
        else
        {
            printf("\n%s bukan palindrom.\n", kalimat);
        }

        printf("\nMau lagi? (y/t): ");
        scanf(" %c", &jawab);

        while (getchar() != '\n');

    } while (jawab != 't');

    return 0;
}

void inisiasi(stack *s)
{
    s->count = 0;
}

void push(Karakter item, stack *s)
{
    if (!penuh(s))
    {
        s->huruf[s->count] = item;
        s->count++;
    }
    else
    {
        printf("Stack penuh. Penambahan gagal.\n");
    }
}

Karakter pop(stack *s)
{
    if (!kosong(s))
    {
        s->count--;
        return s->huruf[s->count];
    }
    else
    {
        printf("Stack kosong. Penghapusan gagal.\n");
        return '\0';
    }
}

int penuh(stack *s)
{
    return s->count == max;
}

int kosong(stack *s)
{
    return s->count == 0;
}

int cekPalindrom(stack *s, char *str)
{
    int n = strlen(str) - 1;

    for (int i = 0; i < n; i++)
    {
        push(str[i], s);
    }

    for (int i = 0; i < n; i++)
    {
        if (str[i] != pop(s))
        {
            return 0;
        }
    }

    return 1;
}
