#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p, *q;
    p = (int *)malloc(sizeof(int));
    q = (int *)malloc(sizeof(int));
    *p = 3;
    *q = *p;
    printf("\n%d %d\n", *p, *q);
    printf("\n%p %p\n", *p, *q);
    return 0;
}