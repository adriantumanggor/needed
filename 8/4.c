#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long int rekursi(unsigned long long int);
unsigned long long int iterasi(unsigned long long int);
unsigned long long int rekursi_tail(unsigned long long int, unsigned long long int);

void hitung_faktorial(int pilihan, unsigned long long int n);
void print_menu();

int main()
{
    int pilihan;
    unsigned long long int n;

    while (1)
    {
        print_menu();

        printf("Pilihan: ");
        scanf("%d", &pilihan);

        if (pilihan == 4)
            break;

        printf("Masukkan n (menghitung faktorial): ");
        scanf("%llu", &n);

        hitung_faktorial(pilihan, n);
    }

    return 0;
}

void print_menu()
{
    printf("Pilih cara menghitung faktorial:\n");
    printf("1. Rekursi biasa\n");
    printf("2. Iterasi\n");
    printf("3. Rekursi ekor\n");
    printf("4. Keluar\n");
}

void hitung_faktorial(int pilihan, unsigned long long int n)
{
    unsigned long long int hasil;
    clock_t start, end;
    double waktu_komputasi;

    start = clock();

    switch (pilihan)
    {
    case 1:
        hasil = rekursi(n);
        break;
    case 2:
        hasil = iterasi(n);
        break;
    case 3:
        hasil = rekursi_tail(n, 1);
        break;
    default:
        printf("Pilihan tidak valid.\n");
        return;
    }

    end = clock();
    waktu_komputasi = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nHasil: %llu\n", hasil);
    printf("Waktu komputasi: %lf detik\n", waktu_komputasi);
}

unsigned long long int rekursi(unsigned long long int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * rekursi(n - 1);
    }
}

unsigned long long int iterasi(unsigned long long int n)
{
    unsigned long long int hasil = 1;

    for (unsigned long long int i = 1; i <= n; i++)
    {
        hasil = hasil * i;
    }

    return hasil;
}

unsigned long long int rekursi_tail(unsigned long long int n, unsigned long long int hasil)
{
    if (n == 0 || n == 1)
        return hasil;
    else
        return rekursi_tail(n - 1, n * hasil);
}
