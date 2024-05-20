#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAX 30000

void insertionSort(int[], int, int *, int);
void selectionSort(int[], int, int *, int);
void bubbleSort(int[], int, int *, int);
void shellSort(int[], int, int *, int);
void mergeSort(int[], int, int, int, int *);
void quickSort(int[], int, int, int, int *);
void cetak(int[], int);
void generate(int[], int);
void swap(int *, int *);
int tampilkanMenuSorting();
int tampilkanMenuUrutan();
void pilihan(int[], int, int *, int, int, double *);

int main()
{
    int n = MAX, pembanding = 0, pilihan_sorting, pilihan_urutan;
    double waktu;

    int arr[MAX];
    generate(arr, n);

    while (1)
    {
        pilihan_sorting = tampilkanMenuSorting();
        pilihan_urutan = tampilkanMenuUrutan();

        int arr_copy[MAX];
        memcpy(arr_copy, arr, sizeof(arr)); 

        pilihan(arr_copy, n, &pembanding, pilihan_sorting, pilihan_urutan, &waktu);

        printf("\nWaktu yang dibutuhkan untuk komputasi: %f detik\n", waktu);
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
            swap(&arr[j + 1], &arr[j]);
            j = j - 1;
            (*pembanding)++;
        }
        arr[j + 1] = key;
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
        swap(&arr[indeks], &arr[i]);
    }
}

void bubbleSort(int arr[], int n, int *pembanding, int pilihan_urutan)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            (*pembanding)++;
            if ((pilihan_urutan == 1 && arr[j] > arr[j + 1]) || (pilihan_urutan == 2 && arr[j] < arr[j + 1]))
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void shellSort(int arr[], int n, int *pembanding, int pilihan_urutan)
{
    int jarak, i, j, temp;
    for (jarak = n / 2; jarak > 0; jarak /= 2)
    {
        for (i = jarak; i < n; i += 1)
        {
            temp = arr[i];
            for (j = i; j >= jarak && ((pilihan_urutan == 1 && arr[j - jarak] > temp) || (pilihan_urutan == 2 && arr[j - jarak] < temp)); j -= jarak)
            {
                arr[j] = arr[j - jarak];
                (*pembanding)++;
            }
            arr[j] = temp;
        }
    }
}

void merge(int arr[], int left, int mid, int right, int pilihan_urutan, int *pembanding) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        (*pembanding)++;
        if ((pilihan_urutan == 1 && L[i] <= R[j]) || (pilihan_urutan == 2 && L[i] >= R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right, int pilihan_urutan, int *pembanding) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, pilihan_urutan, pembanding);
        mergeSort(arr, mid + 1, right, pilihan_urutan, pembanding);

        merge(arr, left, mid, right, pilihan_urutan, pembanding);
    }
}

int partition(int arr[], int low, int high, int pilihan_urutan, int *pembanding) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*pembanding)++;
        if ((pilihan_urutan == 1 && arr[j] < pivot) || (pilihan_urutan == 2 && arr[j] > pivot)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int pilihan_urutan, int *pembanding) {
    if (low < high) {
        int pi = partition(arr, low, high, pilihan_urutan, pembanding);

        quickSort(arr, low, pi - 1, pilihan_urutan, pembanding);
        quickSort(arr, pi + 1, high, pilihan_urutan, pembanding);
    }
}

void cetak(int arr[], int n)
{
    printf("\nElemen setelah pengurutan:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void generate(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int tampilkanMenuSorting()
{
    int pilihan_sorting;

    printf("\nPilih algoritma pengurutan:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Shell Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Quick Sort\n");
    printf("7. Keluar\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan_sorting);

    if (pilihan_sorting == 7)
    {
        exit(0);
    }

    return pilihan_sorting;
}

int tampilkanMenuUrutan()
{
    int pilihan_urutan;

    printf("\nPilih urutan pengurutan:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan_urutan);

    return pilihan_urutan;
}

void pilihan(int arr[], int n, int *pembanding, int pilihan_sorting, int pilihan_urutan, double *waktu)
{
    clock_t start, end;

    start = clock();

    switch (pilihan_sorting)
    {
    case 1:
        insertionSort(arr, n, pembanding, pilihan_urutan);
        break;
    case 2:
        selectionSort(arr, n, pembanding, pilihan_urutan);
        break;
    case 3:
        bubbleSort(arr, n, pembanding, pilihan_urutan);
        break;
    case 4:
        shellSort(arr, n, pembanding, pilihan_urutan);
        break;
    case 5:
        mergeSort(arr, 0, n - 1, pilihan_urutan, pembanding);
        break;
    case 6:
        quickSort(arr, 0, n - 1, pilihan_urutan, pembanding);
        break;
    default:
        printf("Pilihan tidak valid.\n");
        return;
    }

    end = clock();

    *waktu = ((double)(end - start)) / CLOCKS_PER_SEC;
}
