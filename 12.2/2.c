#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct siswa
{
    int NO;
    char Nama[50];
    int Nilai;
} siswa;

siswa *Data;
int size;

void isiData();
void cetakData(int modeTampil);
int menu();
void insertionSort(siswa *arr);
int sequentialSearch(int berdasarkan, int kunciInt, char *kunciStr);
int binarySearch(int berdasarkan, int kunciInt, char *kunciStr);
void inputPencarian(int *berdasarkan, int *kunciInt, char *kunciStr);
void pilihan(int);

int main()
{
    isiData();
    int pilihan_menu;

    do
    {
        pilihan_menu = menu();
        pilihan(pilihan_menu);

    } while (1);

    return 0;
}

void isiData()
{
    printf("Masukkan jumlah siswa: ");
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

void cetakData(int modeTampil)
{
    printf("NO\tNama\tNilai\n");

    if (modeTampil == 1)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d\t%s\t%d\n", Data[i].NO, Data[i].Nama, Data[i].Nilai);
        }
    }
    else if (modeTampil == 2)
    {
        insertionSort(Data);
        for (int i = 0; i < size; i++)
        {
            printf("%d\t%s\t%d\n", Data[i].NO, Data[i].Nama, Data[i].Nilai);
        }
    }
}

int menu()
{
    int pilihan;

    printf("\nMenu Search\n");
    printf("1. Tampilkan data (tidak terurut)\n");
    printf("2. Tampilkan data (terurut berdasarkan NO)\n");
    printf("3. Sequential search\n");
    printf("4. Binary search\n");
    printf("5. Keluar\n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);

    return pilihan;
}

void insertionSort(siswa *arr)
{
    int i, j;
    siswa key;

    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].NO > key.NO)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int sequentialSearch(int berdasarkan, int kunciInt, char *kunciStr)
{
    for (int i = 0; i < size; i++)
    {
        if ((berdasarkan == 1 && Data[i].NO == kunciInt) || (berdasarkan == 2 && strcmp(Data[i].Nama, kunciStr) == 0))
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int berdasarkan, int kunciInt, char *kunciStr)
{
    int kiri = 0, kanan = size - 1;

    while (kiri <= kanan)
    {
        int tengah = kiri + (kanan - kiri) / 2;
        if ((berdasarkan == 1 && Data[tengah].NO == kunciInt) || (berdasarkan == 2 && strcmp(Data[tengah].Nama, kunciStr) == 0))
        {
            return tengah;
        }
        else if ((berdasarkan == 1 && Data[tengah].NO < kunciInt) || (berdasarkan == 2 && strcmp(Data[tengah].Nama, kunciStr) < 0))
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }

    return -1;
}

void inputPencarian(int *berdasarkan, int *kunciInt, char *kunciStr)
{
    printf("Pilih kriteria pencarian:\n");
    printf("1. NO\n");
    printf("2. Nama\n");
    printf("Pilihan: ");
    scanf("%d", berdasarkan);

    if (*berdasarkan == 1)
    {
        printf("Masukkan NO: ");
        scanf("%d", kunciInt);
    }
    else if (*berdasarkan == 2)
    {
        printf("Masukkan Nama: ");
        getchar();
        fgets(kunciStr, sizeof(kunciStr), stdin);
        kunciStr[strcspn(kunciStr, "\n")] = '\0';
    }
}

void pilihan(int pilihan)
{
    int berdasarkan, kunciInt;
    char kunciStr[50];

    switch (pilihan)
    {
    case 1:
        cetakData(1);
        break;
    case 2:
        cetakData(2);
        break;
    case 3:
        inputPencarian(&berdasarkan, &kunciInt, kunciStr);
        printf("Hasil pencarian:\n");
        if (sequentialSearch(berdasarkan, kunciInt, kunciStr) != -1)
            printf("Data %d ditemukan di indeks %d\n", kunciInt, sequentialSearch(berdasarkan, kunciInt, kunciStr));
        else
            printf("Data tidak ditemukan.\n");
        break;
    case 4:
        inputPencarian(&berdasarkan, &kunciInt, kunciStr);
        printf("Hasil pencarian:\n");
        if (binarySearch(berdasarkan, kunciInt, kunciStr) != -1)
            printf("Data %s ditemukan di indeks %d\n", kunciStr ,binarySearch(berdasarkan, kunciInt, kunciStr));
        else
            printf("Data tidak ditemukan.\n");
        break;
    case 5:
        exit(0);
    default:
        printf("Pilihan tidak valid.\n");
    }
}
