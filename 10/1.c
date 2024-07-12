#include <stdio.h>

void insertionSort(int[], int, int *);
void cetak(int[], int, int);
void input(int[], int);

int main()
{
    int n, i, pembanding = 0;

    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    int arr[n];

    input(arr, n);

    insertionSort(arr, n, &pembanding);

    cetak(arr, n, pembanding);

    return 0;
}

void insertionSort(int arr[], int n, int *pembanding)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1; //0
        (*pembanding)++;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];

            j = j - 1;

            (*pembanding)++;
        }
        arr[j + 1] = key;
        cetak(arr, n, *pembanding);
    }
}

void cetak(int arr[], int n, int pembanding)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nJumlah perbandingan: %d\n", pembanding);
}

void input(int arr[], int n)
{
    printf("Masukkan %d elemen array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
