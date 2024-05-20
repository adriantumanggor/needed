// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     // int *angka = (int *)10;
//     // char *namakota[] = {"Batu", "ngewe", "malam"};
//     // for (int i = 0; i < 3; i++)
//     // {
//     //     printf("%s\n", namakota[i]);
//     // }
//     // printf("%d\n", angka);
//     // char *strPtr = "Hello";
//     // printf("%c\n", *strPtr);

//     int day, month, year;

//     printf("Enter date of birth (dd-mm-yy): ");
//     scanf("%d-%d-%d", &day, &month, &year);

//     printf("Date of birth: %02d-%02d-%02d\n", day, month, year);

//     return 0;
// }
#include <stdio.h>
#include <locale.h>

int main() {
    // Set locale to get the correct thousands separator for the current environment
    setlocale(LC_NUMERIC, "");
    long long number;

    // Input number
    printf("Enter a number: ");
    scanf("%lld", &number);

    // Output number with thousands separator
    printf("Formatted number: %'lld\n", number);
    // int x, *ptr, *ptrr;
    // x = 5;
    // ptr = &x;
    // printf("\nx = %d\n", x);
    // printf("\nptr = %d\n", *ptr);
    // printf("\nptr = \n");
    // scanf("%d", &ptrr);
    // printf("\nptrr = %d\n", *ptrr);
    return 0;
}
// #include <stdio.h>

// int main() {
//     int x, *ptr, *ptrr;
//     x = 5;
//     ptr = &x;
//     printf("x = %d\n", x);
//     printf("ptr = %d\n", *ptr);
//     printf("Enter a value: ");
//     scanf("%d", ptr); // Provide the address of the variable, not just the pointer
//     printf("ptr = %d\n", *ptr);
//     printf("Enter another value: ");
//     scanf("%d", &ptrr); // Provide the address of the variable, not just the pointer
//     printf("ptrr = %d\n", *ptrr);
//     return 0;
// }

