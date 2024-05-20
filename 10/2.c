#include <stdio.h>

void selectionSort(int[], int, int *);
void cetak(int[], int, int);
void input(int[], int);

int main()
{
    int n, i, pembanding = 0;

    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    int arr[n];

    input(arr, n);

    selectionSort(arr, n, &pembanding);

    cetak(arr, n, pembanding);

    return 0;
}

void selectionSort(int arr[], int n, int *pembanding)
{
    int i, j, kecil;
    for (i = 0; i < n - 1; i++)
    {
        kecil = i;
        for (j = i + 1; j < n; j++)
        {
            (*pembanding)++;
            if (arr[j] < arr[kecil])
                kecil = j;
        }
        int temp = arr[kecil];
        arr[kecil] = arr[i];
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

void input(int arr[], int n)
{
    printf("Masukkan %d elemen array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}