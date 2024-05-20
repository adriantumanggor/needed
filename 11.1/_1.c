#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void swap(int *, int *);
void bubbleSort(int[], int);
void shellSort(int[], int);
void cetak(int[], int);


int C, S, M;


int main()
{
   int arr[] = {3, 10, 8, 7, 6, 1, 5, 2, 4, 9};
   int n = sizeof(arr) / sizeof(arr[0]);


   printf("Array awal: ");
   cetak(arr, n);


   bubbleSort(arr, n);


   shellSort(arr, n);


   return 0;
}


void bubbleSort(int arr[], int n)
{
   int index, pos_akhir;
   bool swapped;


   int salin[n];
   memcpy(salin, arr, n * sizeof(int));


   C = S = M = 0;
   pos_akhir = n - 2;
   index = 0;


   printf("\nBubble sort:\n");


   while (index <= pos_akhir && swapped)
   {
       swapped = false;


       for (int i = 0; i <= pos_akhir; i++)
       {
           C++;


           if (salin[i] > salin[i + 1])
           {
               swap(&salin[i], &salin[i + 1]);
               swapped = true;
               cetak(salin, n);
           }
       }


       index++;


       if (!swapped)
       {
           break;
       }
   }


   printf("\nTotal perbandingan (C): %d\nTotal swap (S): %d\nTotal pergeseran (M): %d\n", C, S, M);
}


void shellSort(int arr[], int n)
{
   bool swapped;
   int jarak = n;


   printf("\nShell sort:\n");


   int salin[n];
   memcpy(salin, arr, n * sizeof(int));


   while (jarak > 1)
   {
       jarak = jarak / 2;
       swapped = true;


       while (swapped)
       {
           swapped = false;


           for (int i = 0; i < n - jarak; i++)
           {
               C++;


               if (salin[i] > salin[i + jarak])
               {
                   swap(&salin[i], &salin[i + jarak]);
                   swapped = true;
                   cetak(salin, n);
               }
           }
       }
   }
   printf("\nTotal perbandingan (C): %d\nTotal swap (S): %d\nTotal pergeseran (M): %d\n", C, S, M);
}


void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
   S++;
   M += 3;
}


void cetak(int arr[], int n)
{
   for (int i = 0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
