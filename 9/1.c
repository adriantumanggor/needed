#include <stdio.h>
#include <stdlib.h>

int fpb(int, int);

int main()
{
    int n, m, hasil;

    printf("Masukkan bilangan pertama: ");
    scanf(" %d", &n);

    printf("Masukkan bilangan kedua: ");
    scanf(" %d", &m);

    hasil = fpb(n, m);

    printf("\nfpb dari bilangan %d dan %d adalah %d\n", n, m, hasil);

    return 0;
}

int fpb(int a, int b)
{
    int c;
    
    if (a < b)
    {
        c = a;
        a = b;
        b = c;
    }

    if (b == 0)
    {
        return a;
    }

    else
    {
        return fpb(b, a % b);
    }
}