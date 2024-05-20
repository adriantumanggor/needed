#include <stdio.h>
#include <stdlib.h>

void tampilkanderet(int);

int main()
{
    int n;

    printf("Masukkan n(deret fibonaci): ");
    scanf("%d", &n);

    tampilkanderet(n);

    return 0;
}

void tampilkanderet(int n)
{
    int a = 0, b = 1, hasil;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            printf("\n%d", a);
        }
        else if (i == 1)
        {
            printf("\n%d", b);
        }

        else
        {
            hasil = a + b;

            printf("\n%d", hasil);

            a = b;
            b = hasil;
        }
    }
    
    puts("");
}