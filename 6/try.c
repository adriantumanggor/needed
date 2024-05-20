#include <stdio.h>
#include <string.h>

int main() {
    char string[] = "1+2\n"; // String yang akan dihitung panjangnya
    int length;

    // Menggunakan strlen() untuk menghitung panjang string
    length = strlen(string);

    // Menampilkan hasil perhitungan panjang string
    printf("string = %s", string);
    printf("Panjang string adalah: %d\n", length);

    return 0;
}
