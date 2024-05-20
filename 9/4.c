#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibonaci(int);
void tampilkanderet1(int);
void tampilkanderet2(int);
void menu(int);

int main()
{
    int n;

    printf("Masukkan n(deret fibonaci): ");
    scanf("%d", &n);

    menu(n);

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

void tampilkanderet1(int n)
{
    puts("Deret fibonaci:");

    for (int i = 0; i < n; i++)
    {
        printf("\n%d", fibonaci(i));
    }

    puts("");
}

void tampilkanderet2(int n)
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

void menu(int n)
{
    int pilih;
    clock_t t1, t2;
    double waktu;

    do
    {
        printf("\nMenu fibonaci\n");
        printf("1. Rekursi\n");
        printf("2. Iterasi\n");
        printf("3. Keluar\n");

        printf("Masukkan pilihan: ");
        scanf("%d", &pilih);

        t1 = clock();
        switch (pilih)
        {
        case 1:
            tampilkanderet1(n);
            break;
        case 2:
            tampilkanderet2(n);
            break;
        case 3:
            exit(0);
        default:
            printf("Pilihan tidak valid. Silakan masukkan pilihan yang benar.\n");
            break;
        }

        t2 = clock();
        waktu = ((double)(t2 - t1)) / CLOCKS_PER_SEC;
        printf("Waktu yang dibutuhkan: %.6f detik\n", waktu);
    } while (pilih != 3);
}
