#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20000

void swap(int *, int *);
void bubbleSort(int[], int, int);
void shellSort(int[], int, int);
int mode_urut();
void generate(int[]);
void cetak(int[], int);
void menu_sorting(int arr[], int n);

int C, S, M;

int main()
{
    clock_t start, end;

    srand(time(NULL));

    int arr[MAX];

    generate(arr);

    int n = MAX;

    menu_sorting(arr, n);

    return 0;
}

void menu_sorting(int arr[], int n)
{
    int choice;

    do
    {
        printf("\nMenu Sorting:\n");
        printf("1. Bubble Sort\n");
        printf("2. Shell Sort\n");
        printf("0. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2)
        {
            int pilihan = mode_urut();
            clock_t start_time = clock();

            if (choice == 1)
                bubbleSort(arr, n, pilihan);
            else
                shellSort(arr, n, pilihan);

            clock_t end_time = clock();

            double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            printf("Waktu Komputasi: %.6f detik\n", total_time);
        }
    } while (choice != 0);
}

int mode_urut()
{
    int pilihan;

    printf("\nPilih urutan pengurutan:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

    return pilihan;
}

void bubbleSort(int arr[], int n, int pilihan)
{
    int index = 0, pos_akhir = n - 2;
    bool swapped = true;

    int salin[n];
    memcpy(salin, arr, n * sizeof(int));

    C = S = M = 0;

    printf("\nBubble sort:\n");

    while (swapped)
    {
        swapped = false;

        for (int i = 0; i <= pos_akhir; i++)
        {
            C++;

            if ((pilihan == 1 && salin[i] > salin[i + 1]) ||
                (pilihan == 2 && salin[i] < salin[i + 1]))
            {
                swap(&salin[i], &salin[i + 1]);
                swapped = true;
            }
        }

        index++;

        if (!swapped)
        {
            break;
        }
    }

    printf("\nTotal perbandingan (C): %d\nTotal swap (S): %d\nTotal pergeseran (M): %d\n", C, S, M);
}

void shellSort(int arr[], int n, int pilihan)
{
    bool swapped;
    int jarak = n;

    printf("\nShell sort:\n");

    int salin[n];
    memcpy(salin, arr, n * sizeof(int));

    while (jarak > 1)
    {
        jarak = jarak / 2;
        swapped = true;

        while (swapped)
        {
            swapped = false;

            for (int i = 0; i < n - jarak; i++)
            {
                C++;

                if ((pilihan == 1 && salin[i] > salin[i + jarak]) ||
                    (pilihan == 2 && salin[i] < salin[i + jarak]))
                {
                    swap(&salin[i], &salin[i + jarak]);
                    swapped = true;
                }
            }
        }
    }
    printf("\nTotal perbandingan (C): %d\nTotal swap (S): %d\nTotal pergeseran (M): %d\n", C, S, M);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    S++;
    M += 3;
}

void cetak(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void generate(int x[])
{
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < MAX; i++)
        x[i] = rand() % 1000; // Generate random numbers between 0 and 999
}
