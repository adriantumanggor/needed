#include <stdio.h>
#include <stdlib.h>

#define M 100
#define batas 5

typedef struct data stack;
struct data
{
    int datarute[batas];
    int count;
} simpanRute;

void algoritmaWarshall();
void cetakMatriks(int mat[][5], int size);
void inisiasiStack();
void pushStack(int data);
int popStack();
void cariRuteTercepat();

int bebanQ[5][5] = {
    {M, 1, 3, M, M},
    {M, M, 1, M, 5},
    {3, M, M, 2, M},
    {M, M, M, M, 1},
    {M, M, M, M, M}};


int jalurP[5][5] = {
    {0, 1, 1, 0, 0},
    {0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}};
    
int ruteR[5][5] =
    {
        {M, 0, 0, M, M},
        {M, M, 0, M, 0},
        {0, M, M, 0, M},
        {M, M, M, M, 0},
        {M, M, M, M, M}};

int main()
{
    printf("Sebelum algoritma Warshall:\n");
    printf("Beban Q:\n");
    cetakMatriks(bebanQ, 5);
    printf("\nJalur P:\n");
    cetakMatriks(jalurP, 5);
    printf("\nRute R:\n");
    cetakMatriks(ruteR, 5);

    algoritmaWarshall();

    printf("\nSetelah algoritma Warshall:\n");
    printf("Beban Q:\n");
    cetakMatriks(bebanQ, 5);
    printf("\nJalur P:\n");
    cetakMatriks(jalurP, 5);
    printf("\nRute R:\n");
    cetakMatriks(ruteR, 5);

    cariRuteTercepat();

    return 0;
}

void algoritmaWarshall()
{
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
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
}

void cetakMatriks(int mat[][5], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (mat[i][j] == M)
                printf("M ");
            else
                printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void inisiasiStack()
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

void cariRuteTercepat()
{
    int asal, tujuan, temp;

    printf("\nMasukkan titik asal : ");
    scanf("%d", &asal);
    asal--;

    printf("Masukkan titik tujuan : ");
    scanf("%d", &tujuan);
    tujuan--;

    if (jalurP[asal][tujuan] != 1)
        printf("Tidak ada rute dari %d ke %d\n", asal + 1, tujuan + 1);
    else
    {
        inisiasiStack();
        pushStack(tujuan);
        temp = ruteR[asal][tujuan];

        while (temp != 0)
        {
            pushStack(temp - 1);
            temp = ruteR[asal][temp - 1];
        }

        pushStack(asal);

        printf("Rute tercepat dari %d ke %d: ", asal + 1, tujuan + 1);

        while (simpanRute.count > 0)
        {
            temp = popStack();
            printf("%d ", temp + 1);
        }
        printf("\n");
    }
}
