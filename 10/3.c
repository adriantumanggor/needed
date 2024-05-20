#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void insertionSort(int[], int, int *, int);
void selectionSort(int[], int, int *, int);
void cetak(int[], int, int);
void input(int[], int);
int tampilkanMenuSorting();
int tampilkanMenuUrutan();
void pilihan(int[], int, int *, int, int);

int main()
{
    int n, pembanding = 0, pilihan_sorting, pilihan_urutan;

    while (1)
    {
        pilihan_sorting = tampilkanMenuSorting();
        pilihan_urutan = tampilkanMenuUrutan();

        printf("Masukkan jumlah elemen: ");
        scanf("%d", &n);

        int arr[n];

        input(arr, n);

        pilihan(arr, n, &pembanding, pilihan_sorting, pilihan_urutan);
    
        cetak(arr, n, pembanding);
    }

    return 0;
}

void insertionSort(int arr[], int n, int *pembanding, int pilihan_urutan)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        (*pembanding)++;
        while (j >= 0 && ((pilihan_urutan == 1 && arr[j] > key) || (pilihan_urutan == 2 && arr[j] < key)))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*pembanding)++;
        }
        arr[j + 1] = key;
        cetak(arr, n, *pembanding);
    }
}

void selectionSort(int arr[], int n, int *pembanding, int pilihan_urutan)
{
    int i, j, indeks;
    for (i = 0; i < n - 1; i++)
    {
        indeks = i;
        for (j = i + 1; j < n; j++)
        {
            (*pembanding)++;
            if ((pilihan_urutan == 1 && arr[j] < arr[indeks]) || (pilihan_urutan == 2 && arr[j] > arr[indeks]))
            {
                indeks = j;
            }
        }
        int temp = arr[indeks];
        arr[indeks] = arr[i];
        arr[i] = temp;
        cetak(arr, n, *pembanding);
    }
}

void cetak(int arr[], int n, int pembanding)
{
    printf("\nElemen setelah pengurutan:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nJumlah perbandingan: %d\n", pembanding);
}

int tampilkanMenuSorting()
{
    int pilihan_sorting;

    printf("Pilih algoritma pengurutan:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Keluar\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan_sorting);

    if (pilihan_sorting == 3)
    {
        exit(0);
    }

    return pilihan_sorting;
}

int tampilkanMenuUrutan()
{
    int pilihan_urutan;

    printf("Pilih urutan pengurutan:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan_urutan);

    return pilihan_urutan;
}

void input(int arr[], int n)
{
    printf("Masukkan %d elemen array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void pilihan(int arr[], int n, int *pembanding, int pilihan_sorting, int pilihan_urutan)
{
    switch (pilihan_sorting)
    {
    case 1:
        insertionSort(arr, n, pembanding, pilihan_urutan);
        break;
    case 2:
        selectionSort(arr, n, pembanding, pilihan_urutan);
        break;
    default:
        printf("Pilihan tidak valid.\n");
        return;
    }
}
