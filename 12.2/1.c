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
void cetakData();
int menu();
int modeTampil();
int cari();
void insertionSort();
void sequentialSearch();
void binarySearch();
void pilihan(int, int);

int main()
{
    isiData();
    int pilihan, bentukdata;

    do
    {
        pilihan = menu();

        pilihan(pilihan, bentukdata);

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
    printf("3. Binary search\n");
    printf("4. Keluar\n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);

    return pilihan;
}

int modeTampil()
{
    int pilihan;

    printf("Bentuk data:\n");
    printf("1. Tidak terurut\n");
    printf("2. Terurut berdasarkan NO\n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);

    return pilihan;
}

int cari(){

}




void insertionSort()
{
    int i, j;
    siswa key;

    for (i = 1; i < size; i++)
    {
        key = Data[i];
        j = i - 1;

        while (j >= 0 && Data[j].NO > key.NO)
        {
            Data[j + 1] = Data[j];
            j = j - 1;
        }
        Data[j + 1] = key;
    }
}

void sequentialSearch()
{
    int key;

    printf("masukan NO : ");
    scanf("%d", &key);

    for (int i = 0; i < size; i++)
    {
        if (Data[i].NO == key)
        {
            printf("Data %d ketemu di indeks %d\n", key, i);
            return;
        }
    }
    printf("NO %d tidak ketemu.\n", key);
}

void binarySearch()
{
    int key;
    printf("masukan NO : ");

    scanf("%d", &key);

    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (Data[mid].NO == key)
        {
            printf("Data %d ketemu di indeks %d\n", key, mid);
            return;
        }
        if (Data[mid].NO < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("NO %d tidak ketemu.\n", key);
}

void pilihan(int pilihan, int bentuk) {
    switch (pilihan) {
        case 1:
            cetakData();
            break;
        case 2:
            sequentialSearch();
            break;
        case 3:
            if (pilihan == 2)
                binarySearch();
            else
                printf("Data belum diurutkan.\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Pilihan tidak valid.\n");
    }
}