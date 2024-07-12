#include <stdio.h>
#include <stdlib.h>
#define M 1000000
#define MAX 10
#define MAX_NODES 100

typedef struct data stack;
struct data
{
    int datarute[MAX_NODES];
    int count;
} simpanRute;

void menu(int[][MAX], int[][MAX], int[][MAX]);
void input(int[][MAX], int[][MAX], int[][MAX]);
void algoritmaWarshall(int[][MAX], int[][MAX], int[][MAX]);
void tampilQPR(int mode, int[][MAX], int[][MAX], int[][MAX]);
void fungsiTampil(int[][MAX], int ordo);
void inisiasistack();
void pushStack(int data);
int popStack();
void cariRuteTercepat(int asal, int tujuan, int[][MAX], int[][MAX], int[][MAX]);
void menucariRute(int[][MAX], int[][MAX], int[][MAX]);

int ordo;

int main()
{
    int bebanQ[MAX][MAX], jalurP[MAX][MAX], ruteR[MAX][MAX];
    menu(bebanQ, jalurP, ruteR);
}

void menu(int bebanQ[][MAX], int jalurP[][MAX], int ruteR[][MAX])
{
    input(bebanQ, jalurP, ruteR);
    algoritmaWarshall(bebanQ, jalurP, ruteR);
    menucariRute(bebanQ, jalurP, ruteR);
}

void input(int bebanQ[][MAX], int jalurP[][MAX], int ruteR[][MAX])
{
    int beban;
    printf("Masukkan ordo matriks [1 = 1x1, 2 = 2x2, max %d]: ", MAX);
    scanf("%d", &ordo);
    if (ordo > MAX)
        exit(0);
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            if (i == j)
            {
                bebanQ[i][j] = M;
                jalurP[i][j] = 0;
                ruteR[i][j] = M;
            }
            else
            {
                printf("Masukkan beban dari node %d ke node %d: ", i + 1, j + 1);
                scanf("%d", &beban);
                if (beban == 0)
                {
                    bebanQ[i][j] = M;
                    jalurP[i][j] = 0;
                    ruteR[i][j] = M;
                }
                else
                {
                    bebanQ[i][j] = beban;
                    jalurP[i][j] = 1;
                    ruteR[i][j] = 0;
                }
            }
        }
    }
}

void algoritmaWarshall(int bebanQ[][MAX], int jalurP[][MAX], int ruteR[][MAX])
{
    tampilQPR(0, bebanQ, jalurP, ruteR);
    for (int k = 0; k < ordo; k++)
    {
        for (int i = 0; i < ordo; i++)
        {
            for (int j = 0; j < ordo; j++)
            {
                if (bebanQ[i][j] > (bebanQ[i][k] + bebanQ[k][j]))
                {
                    bebanQ[i][j] = (bebanQ[i][k] + bebanQ[k][j]);
                    if (ruteR[k][j] == 0)
                        ruteR[i][j] = k + 1;
                    else
                        ruteR[i][j] = ruteR[k][j];
                }
                jalurP[i][j] = (jalurP[i][j] || (jalurP[i][k] && jalurP[k][j]));
            }
        }
    }
    tampilQPR(1, bebanQ, jalurP, ruteR);
}

void tampilQPR(int mode, int bebanQ[][MAX], int jalurP[][MAX], int ruteR[][MAX])
{
    if (mode == 0)
        puts("\nMatriks Q P R Asal: ");
    else
        puts("\nMatriks Q P R Baru: ");
    puts("Matriks beban(Q)");
    fungsiTampil(bebanQ, ordo);
    puts("\nMatriks jalur(P)");
    fungsiTampil(jalurP, ordo);
    puts("\nMatriks Rute(R)");
    fungsiTampil(ruteR, ordo);
}

void fungsiTampil(int tampilin[][MAX], int ordo)
{
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            if (tampilin[i][j] == M)
                printf("M ");
            else
                printf("%d ", tampilin[i][j]);
        }
        printf("\n");
    }
}

void inisiasistack()
{
    simpanRute.count = 0;
}

void pushStack(int data)
{
    simpanRute.datarute[simpanRute.count] = data;
    simpanRute.count++;
}

int popStack()
{
    simpanRute.count--;
    return simpanRute.datarute[simpanRute.count];
}

void cariRuteTercepat(int asal, int tujuan, int bebanQ[][MAX], int jalurP[][MAX], int ruteR[][MAX])
{
    int ambilRute, beban;
    if (jalurP[asal][tujuan] != 1)
        printf("\nTidak ada rute dari %d ke %d\n", asal + 1, tujuan + 1);
    else
    {
        inisiasistack();
        pushStack(tujuan);
        ambilRute = ruteR[asal][tujuan];
        while (ambilRute != 0)
        {
            pushStack(ambilRute - 1);
            ambilRute = ruteR[asal][ambilRute - 1];
        }
        pushStack(asal);
        printf("\nRute tercepat dari %d ke %d: ", asal + 1, tujuan + 1);
        while (simpanRute.count > 0)
            printf("%d ", popStack() + 1);
        beban = bebanQ[asal][tujuan];
        printf("\nbeban: %d\n", beban);
    }
}

void menucariRute(int bebanQ[][MAX], int jalurP[][MAX], int ruteR[][MAX])
{
    int asal, tujuan;
    char jawaban;
    do
    {
        printf("\nMasukkan asal : ");
        scanf("%d", &asal);
        asal--;
        printf("Masukkan tujuan : ");
        scanf("%d", &tujuan);
        tujuan--;
        cariRuteTercepat(asal, tujuan, bebanQ, jalurP, ruteR);
        fflush(stdin);
        printf("\nMau lagi? [y/t]: ");
        scanf(" %c", &jawaban); 
        
    } while (jawaban != 'T' && jawaban != 't');
}
