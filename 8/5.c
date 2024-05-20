#include <stdio.h>

int faktorial(int);
int permutasi(int, int);
int kombinasi(int, int);

int main()
{
    int n, r;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    printf("Masukkan nilai r: ");
    scanf("%d", &r);
    
    printf("Permutasi dari %d dan %d adalah %d\n", n, r, permutasi(n, r));
    printf("Kombinasi dari %d dan %d adalah %d\n", n, r, kombinasi(n, r));

    return 0;
}

int faktorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * faktorial(n - 1);
}

int permutasi(int n, int r)
{
    return faktorial(n) / faktorial(n - r);
}

int kombinasi(int n, int r)
{
    return faktorial(n) / (faktorial(r) * faktorial(n - r));
}
