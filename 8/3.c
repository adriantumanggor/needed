#include <stdio.h>
#include <string.h>

void balikkan(char *kata, int akhir);

int main() {
    char kata[100];

    printf("Masukkan kalimat: ");
    fgets(kata, sizeof(kata), stdin);

    if (kata[strlen(kata) - 1] == '\n') {
        kata[strlen(kata) - 1] = '\0';
    }

    balikkan(kata, strlen(kata));
    
    printf("\n");

    return 0;
}

void balikkan(char *kata, int akhir) {
    if (akhir == 0) {
        printf("%c", kata[akhir]);
        return;
    }

    printf("%c", kata[akhir]);
    balikkan(kata, akhir - 1);
}
