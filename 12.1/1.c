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
int size = 10;

void isiData();
void cetakData();
int menuPengurutan();
int modeUrut();
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
    int pilihan_pengurutan, mode, berdasarkan;

    do
    {
        pilihan_pengurutan = menuPengurutan();

        if (pilihan_pengurutan == 7)
            break;

        mode = modeUrut();

        berdasarkan = jenisUrut();

        urutkan(pilihan_pengurutan, mode, berdasarkan);

        cetakData();
    } while (1);

    return 0;
}

int jenisUrut()
{
    int pilihan;

    printf("\nUrutkan Berdasarkan\n");
    printf("1. No\n");
    printf("2. Nama\n");
    printf("3. Nilai\n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);

    return pilihan;
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
        bubbleSort(mode, berdasarkan);
        break;
    case 4:
        shellSort(mode, berdasarkan);
        break;
    case 5:
        mergeSort(Data, 0, size - 1, berdasarkan, mode);
        break;
    case 6:
        quickSort(Data, 0, size - 1, berdasarkan, mode);
        break;
    default:
        exit(0);
    }
}

void isiData()
{
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

int menuPengurutan()
{
    int pilihan;

    printf("\nMENU METODE SORTING\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Bubble sort\n");
    printf("4. Shell sort\n");
    printf("5. Merge Sort\n");
    printf("6. Quick Sort\n");
    printf("7. Keluar\n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);

    return pilihan;
}

int modeUrut()
{
    int pilihan;

    printf("Pengurutan yang dipilih:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
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
