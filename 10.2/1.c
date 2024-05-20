#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct siswa
{
    int NO;
    char Nama[50];
    char Nilai[3];
};

struct siswa Data[10];

void isiData();
void cetakData();
int menuPengurutan();
int modeUrut();
void insertionSort(int mode);
void selectionSort(int mode);

int main()
{
    isiData();
    int pilihan_pengurutan, mode;

    do
    {
        pilihan_pengurutan = menuPengurutan();

        mode = modeUrut();

        if (pilihan_pengurutan == 1)
        {
            insertionSort(mode);
        }

        else
        {
            selectionSort(mode);
        }

        cetakData();
    } while (1);

    return 0;
}

void isiData()
{
    for (int i = 0; i < 10; i++)
    {
        printf("Masukkan data siswa ke-%d\n", i + 1);

        printf("NO: ");
        scanf("%d", &Data[i].NO);
        getchar();

        printf("Nama: ");
        fgets(Data[i].Nama, sizeof(Data[i].Nama), stdin);
        Data[i].Nama[strcspn(Data[i].Nama, "\n")] = '\0';

        printf("Nilai: ");
        scanf(" %s", &Data[i].Nilai);
    }
}

void cetakData()
{
    printf("NO\tNama\tNilai\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t%s\t%s\n", Data[i].NO, Data[i].Nama, Data[i].Nilai);
    }
}

int menuPengurutan()
{
    int pilihan;

    printf("\nMENU METODE SORTING\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Keluar\n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);

    if (pilihan == 3)
    {
        exit(0);
    }

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

void insertionSort(int mode)
{
    int i, j;
    struct siswa temp;
    for (i = 1; i < 10; i++)
    {
        temp = Data[i];
        j = i - 1;

        if (mode == 1)
        {
            while (j >= 0 && Data[j].NO > temp.NO)
            {
                Data[j + 1] = Data[j];
                j = j - 1;
            }
        }
        else if (mode == 2)
        {
            while (j >= 0 && Data[j].NO < temp.NO)
            {
                Data[j + 1] = Data[j];
                j = j - 1;
            }
        }
        Data[j + 1] = temp;
    }
}

void selectionSort(int mode)
{
    int i, j, kecil;
    struct siswa temp;

    for (i = 0; i < 10 - 1; i++)
    {
        kecil = i;
        for (j = i + 1; j < 10; j++)
        {
            if (mode == 1 && Data[j].NO < Data[kecil].NO)
            {
                kecil = j;
            }
            else if (mode == 2 && Data[j].NO > Data[kecil].NO)
            {
                kecil = j;
            }
        }
        temp = Data[kecil];
        Data[kecil] = Data[i];
        Data[i] = temp;
    }
}