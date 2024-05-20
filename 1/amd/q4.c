#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int day;
    int month;
    int year;
} Date;

int sama(Date day, Date dayy);
void input(Date *Day);
int main()
{
    Date day1, day2;
    input(&day1);
    input(&day2);

    if (sama(day1, day2))
    {
        printf("\nSama betul\n");
    }
    else
    {
        printf("\nTidak sama\n");
    }

    printf("\n");
    return 0;
}
int sama(Date day, Date dayy)
{
    return (day.day == dayy.day && day.month == dayy.month && day.year == dayy.year);
}
void input(Date *Day)
{
    printf("\nMasukkan Tanggal:\n");
    scanf("%2d", &Day->day);
    printf("\nMasukkan Bulan:\n");
    scanf("%2d", &Day->month);
    printf("\nMasukkan Tahun:\n");
    scanf("%4d", &Day->year);
}