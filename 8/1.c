#include <stdio.h>
#include <stdlib.h>

typedef int Itemtype;
typedef struct stack
{
    Itemtype *data;
    int count;
} stack;

void inisialisasi(stack *s);
int kosong(stack *s);
int penuh(stack *s);
void push(Itemtype, stack *s);
Itemtype pop(stack *s);

void tampil_menurun(int, stack *);

int n;

int main()
{
    stack tumpukan;

    printf("Masukkan n:");
    scanf("%d", &n);

    inisialisasi(&tumpukan);

    tampil_menurun(n, &tumpukan);
    return 0;
}

void tampil_menurun(int n, stack *s)
{
    if (n == -1)
    {
        while (!kosong(s))
        {
            printf("\n%d", pop(s));
        }
    }
    else
    {
        push(n, s);
        tampil_menurun(n - 1, s);
    }
}

void inisialisasi(stack *s)
{
    s->data = malloc(n * sizeof(int));

    s->count = 0;
}

int kosong(stack *s)
{
    return (s->count == 0 ? 1 : 0);
}

int penuh(stack *s)
{
    return (s->count == n ? 1 : 0);
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
