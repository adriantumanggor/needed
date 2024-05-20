#include <stdio.h>
#include <stdlib.h>

struct StudentDOB {
    int day;
    int month;
    int year;
};
void input(struct StudentDOB *stud, int *indeks);
int isYoung(struct StudentDOB stud1, struct StudentDOB stud2);

int main() {
    struct StudentDOB stud1, stud2;
    int x=1;
    input(&stud1,&x);
    input(&stud2,&x);
    if(isYoung(stud1, stud2))
    {
        printf("\nstud1 is younger than stud2\n");
    }
    else
    {
        printf("\nstud2 is younger than stud1\n");
    }
    return 0;
}

void input(struct StudentDOB *stud, int *indeks){
    printf("\nstudent %d\n",*indeks);
    printf("\nTanggal: ");
    scanf("%d", &stud->day);
    printf("\nBulan: ");
    scanf("%d", &stud->month);
    printf("\nTahun: ");
    scanf("%d", &stud->year);
    (*indeks)++;
}

int isYoung(struct StudentDOB stud1, struct StudentDOB stud2)
{
    if (stud1.year =! stud2.year)
    {
        return stud1.year > stud2.year;
    }
    if (stud1.month =! stud2.month)
    {
        return stud1.month > stud2.month;
    }
    return stud1.day > stud2.day;
}