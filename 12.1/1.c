#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa
{
    int NO;
    char Nama[50];
    int Nilai;
} siswa;

struct siswa Data[10];
int size;

void isiData();
void cetakData();
int menu();
int mode();
int jenisUrut();
void insertionSort(int, int);
void selectionSort(int, int);
void bubbleSort(int, int);
void shellSort(int, int);
void mergeSort(struct siswa[], int, int, int, int);
void quickSort(struct siswa[], int, int, int, int);
void urutkan(int, int, int);
int comparator(struct siswa, struct siswa, int, int);

int main()
{
    isiData();
    int pilihan, bentukdata;

    do
    {
        pilihan = menu();

        if (pilihan == 3)
            break;

        bentukdata = mode();

        urutkan(pilihan, bentukdata);

        cetakData();
    } while (1);

    return 0;
}

void urutkan(int pilihan, int mode, int berdasarkan)
{
    switch (pilihan)
    {
    case 1:
        insertionSort(mode, berdasarkan);
        break;
    case 2:
        selectionSort(mode, berdasarkan);
        break;
    case 3:
        exit(0);
    default:
        break;
    }
}

void isiData()
{
    printf("Enter the number of students: ");
    scanf("%d", &size);

    Data = (siswa *)malloc(size * sizeof(siswa));

    for (int i = 0; i < size; i++)
    {
        printf("Masukkan data siswa ke-%d\n", i + 1);

        printf("NO: ");
        scanf("%d", &Data[i].NO);
        getchar();

        printf("Nama: ");
        fgets(Data[i].Nama, sizeof(Data[i].Nama), stdin);
        Data[i].Nama[strcspn(Data[i].Nama, "\n")] = '\0';

        printf("Nilai: ");
        scanf("%d", &Data[i].Nilai);
    }
}

void cetakData()
{
    printf("NO\tNama\tNilai\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\t%s\t%d\n", Data[i].NO, Data[i].Nama, Data[i].Nilai);
    }
}

int menu()
{
    int pilihan;

    printf("\nMenu Search\n");
    printf("1. Tampilkan data\n");
    printf("2. Sequential search\n");
    printf("3. Keluar\n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);

    return pilihan;
}

int mode()
{
    int pilihan;

    printf("Bentuk data:\n");
    printf("1. tidak terurut\n");
    printf("2. Terurut berdasarkan no\n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);

    return pilihan;
}

void insertionSort(int mode, int berdasarkan)
{
    int i, j;
    struct siswa key;
    for (i = 1; i < size; i++)
    {
        key = Data[i];
        j = i - 1;

        while (j >= 0 && comparator(Data[j], key, berdasarkan, mode) > 0)
        {
            Data[j + 1] = Data[j];
            j = j - 1;
        }
        Data[j + 1] = key;
    }
}

void selectionSort(int mode, int berdasarkan)
{
    int i, j, kecil;
    struct siswa temp;

    for (i = 0; i < size - 1; i++)
    {
        kecil = i;
        for (j = i + 1; j < size; j++)
        {
            if (comparator(Data[j], Data[kecil], berdasarkan, mode) < 0)
            {
                kecil = j;
            }
        }
        temp = Data[kecil];
        Data[kecil] = Data[i];
        Data[i] = temp;
    }
}

void bubbleSort(int mode, int berdasarkan)
{
    int i, j;
    struct siswa temp;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (comparator(Data[j], Data[j + 1], berdasarkan, mode) > 0)
            {
                temp = Data[j];
                Data[j] = Data[j + 1];
                Data[j + 1] = temp;
            }
        }
    }
}

void shellSort(int mode, int berdasarkan)
{
    int i, j, jarak;
    struct siswa temp;

    for (jarak = size / 2; jarak > 0; jarak /= 2)
    {
        for (i = jarak; i < size; i++)
        {
            temp = Data[i];
            for (j = i; j >= jarak && comparator(Data[j - jarak], temp, berdasarkan, mode) > 0; j -= jarak)
            {
                Data[j] = Data[j - jarak];
            }
            Data[j] = temp;
        }
    }
}

void merge(struct siswa arr[], int left, int mid, int right, int berdasarkan, int mode) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct siswa L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (comparator(L[i], R[j], berdasarkan, mode) <= 0) {
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

void mergeSort(struct siswa arr[], int left, int right, int berdasarkan, int mode) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, berdasarkan, mode);
        mergeSort(arr, mid + 1, right, berdasarkan, mode);

        merge(arr, left, mid, right, berdasarkan, mode);
    }
}

int partition(struct siswa arr[], int low, int high, int berdasarkan, int mode) {
    struct siswa pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (comparator(arr[j], pivot, berdasarkan, mode) < 0) {
            i++;
            struct siswa temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    struct siswa temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(struct siswa arr[], int low, int high, int berdasarkan, int mode) {
    if (low < high) {
        int pi = partition(arr, low, high, berdasarkan, mode);

        quickSort(arr, low, pi - 1, berdasarkan, mode);
        quickSort(arr, pi + 1, high, berdasarkan, mode);
    }
}

int comparator(struct siswa a, struct siswa b, int berdasarkan, int mode)
{
    int result = 0;
    switch (berdasarkan)
    {
    case 1:
        result = a.NO - b.NO;
        break;
    case 2:
        result = strcmp(a.Nama, b.Nama);
        break;
    case 3:
        result = a.Nilai - b.Nilai;
        break;
    default:
        return 0;
    }

    if (mode == 2)
    {
        result = -result;
    }

    return result;
}
