#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    int ID;
    char nama[50];
    char tgllahir[11];
    char kelamin;
    long long gaji;
} Pegawai;

void input(Pegawai *pegawai, int Jp)
{
    for (int i = 0; i < Jp; i++)
    {    
        while (getchar() != '\n');

        printf("\nData pegawai ke - %d\n", i + 1);

        pegawai[i].ID = i + 1;

        printf("\nNama: ");
        fgets(pegawai[i].nama, sizeof(pegawai[i].nama), stdin);
        char *newline = strchr(pegawai[i].nama, '\n');
        if (newline != NULL)
            *newline = '\0';
        
        printf("\nTanggal lahir(dd-mm-yy): ");
        fgets(pegawai[i].tgllahir, sizeof(pegawai[i].tgllahir), stdin);
        // Remove newline character if present
        newline = strchr(pegawai[i].tgllahir, '\n');
        if (newline != NULL)
            *newline = '\0';
        
        printf("\nJenis Kelamin(L/P):");
        scanf(" %c", &pegawai[i].kelamin);
        
        printf("\nGaji/Bln:");
        scanf("%lld", &pegawai[i].gaji);
    }
}
void tampil(Pegawai *pegawai, int Jp)
{
    printf("\nData pegawai yang telah diinputkan\n");
    for (int i = 0; i < Jp; i++)
    {
        printf("\nNo id: %d", pegawai[i].ID);
        printf("\nNama: %s", pegawai[i].nama);
        printf("\nTanggal lahir: %s", pegawai[i].tgllahir);
        printf("\nJenis Kelamin: %c", pegawai[i].kelamin);
        printf("\nGaji/Bln: %'lld", pegawai[i].gaji);
        printf("\n\n");
    }
}
int main()
{

    int Jp;
    setlocale(LC_NUMERIC, "");
    printf("\nData Pegawai\n\n");
    printf("Berapa Jumlah Pegawai:");
    scanf("%d", &Jp);
    

    Pegawai pegawai[Jp];

    input(pegawai, Jp);
    tampil(pegawai, Jp);
    printf("\n\n");
    return 0;
}