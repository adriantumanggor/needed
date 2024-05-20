#include <stdio.h>
#include <stdlib.h>

int fibonaci(int);
void tampilkanderet(int x);

int main()
{
    int n;

    printf("Masukkan n(deret fibonaci): ");
    scanf("%d", &n);

    tampilkanderet(n);

    return 0;
}

int fibonaci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    
    else
    {
        return fibonaci(n - 1) + fibonaci(n - 2);
    }
}

void tampilkanderet(int n)
{
    puts("Deret fibonaci:");

    for (int i = 0; i < n; i++)
    {
        printf("\n%d", fibonaci(i));
    }

    puts("");
}