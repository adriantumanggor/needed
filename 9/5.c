#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prima(int, int);

int main()
{
    int n;

    printf("Masukkan bilangan yang ingin dicek: ");
    scanf("%d", &n);

    int pembagi = sqrt(n);

    if (prima(n, pembagi))
    {
        printf("%d adalah bilangan prima\n", n);
    }

    else
    {
        printf("%d bukan bilangan prima\n", n);
    }

    return 0;
}

int prima(int n, int pembagi)
{
    if (n <= 1)
    {
        return 0;
    }
    if (pembagi == 1)
    {
        return 1;
    }
    if (n % pembagi == 0)
    {
        return 0;
    }

    return prima(n, pembagi - 1);
}