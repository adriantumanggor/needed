#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct siswa
{
    int NO;
    char Nama[50];
    int Nilai;
};

struct siswa Data[3];
int size = 3;

void isiData();
void cetakData();
int menuPengurutan();
int modeUrut();
int jenisUrut();
void insertionSort(int, int);
void selectionSort(int, int);
void bubbleSort(int, int);
void shellSort(int, int);
void urutkan(int, int, int);
int comparator(struct siswa, struct siswa, int, int);

int main()
{
    isiData();
    int pilihan_pengurutan, mode, berdasarkan;

    do
    {
        pilihan_pengurutan = menuPengurutan();

        if (pilihan_pengurutan == 5)
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
    printf("5. Keluar\n");
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

        if (mode == 2)
        {
            result = -result;
        }

        return result;
    }
}