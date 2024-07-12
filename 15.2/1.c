#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 
#include <string.h>
#define M INT_MAX
#define MAX 5

typedef struct{
   int data[MAX];
   int count;
} stack;

typedef struct{
    int data[MAX];
    int count, front, rear;
} queue;

int jumlah_node;

void tampil(int [MAX][MAX]);
void input(int [MAX][MAX]);

void djikstra(int [MAX][MAX], int [MAX], int [MAX], int, int);
void membaca_rute(int [MAX], int [MAX][MAX], int [MAX]);

void inisialisasi_stack(stack *);
int stack_kosong(stack *);
int stack_penuh(stack *);
void push(stack *, int);
int pop(stack *);

void inisialisasi_queue(queue *);
int queue_kosong(queue *);
int queue_penuh(queue *);
void enqueue(int, queue *);
int dequeue(queue *);
int in_queue(queue *, int);

int main(){
    int beban[MAX][MAX];
    int beban_baru[MAX];
    int rute[MAX];
    int i;

    puts("\nGraph - Djikstra\n");

    puts("Input Matriks Beban (Q)\x1b[0m (dipisahkan dengan spasi)\n");
    input(beban);

    puts("\nMatriks Q-P-R asal");
    tampil(beban);

    membaca_rute(rute, beban, beban_baru);
}

void tampil(int Q[MAX][MAX]){
    int i, j;

    puts("\nMatriks Beban (Q)");
    for (i = 0; i < jumlah_node; i++) {
        for (j = 0; j < jumlah_node; j++) {
            if (Q[i][j] == M) 
                printf("%-3c ", 'M');
            else 
                printf("%-3d ", Q[i][j]);
        }
        puts("");
    }
}

void input(int Q[MAX][MAX]){
    int i, j, temp;
    char nilai[10];

    printf("Masukkan jumlah node: ");
    scanf("%d", &jumlah_node);
    puts("");

    for(i = 0; i < jumlah_node; i++){
        printf("Baris ke-%-3d : ", i+1);
        for (j = 0; j < jumlah_node; j++) {
            scanf("%s", nilai);
            if (strcmp(nilai, "M") == 0){
                Q[i][j] = M;
            }
            else {
                sscanf(nilai, "%d", &temp);
                Q[i][j] = temp;
            }
        }
    }
}

void djikstra(int Q[MAX][MAX], int TQ[MAX], int R[MAX], int asal, int tujuan){
    queue antrian;
    int current_node, i;

    for (i = 0; i < jumlah_node; i++) {
        TQ[i] = M;
        R[i] = -1;
    }

    TQ[asal] = 0;
    inisialisasi_queue(&antrian);
    enqueue(asal, &antrian);

    while(!queue_kosong(&antrian)){
        current_node = dequeue(&antrian);
        for(i = 0; i < jumlah_node; i++){
            if(Q[current_node][i] != M){
                if(Q[current_node][i] + TQ[current_node] < TQ[i]){
                    TQ[i] = Q[current_node][i] + TQ[current_node];
                    R[i] = current_node;
                    if(i != asal && i != tujuan && !in_queue(&antrian, i))
                        enqueue(i, &antrian);
                }
            }
        }
    }
}

void membaca_rute(int R[MAX], int Q[MAX][MAX], int TQ[MAX]){
    stack tumpukan;
    int cek, temp, asal, tujuan, i;

    printf("\nMasukkan Asal\t : ");
    scanf("%d", &asal);
    fflush(stdin);
    printf("Masukkan Tujuan\t : ");
    scanf("%d", &tujuan);
    fflush(stdin);
    printf("\nRute yang terpendek adalah : ");

    asal--;
    tujuan--;

    djikstra(Q, TQ, R, asal, tujuan);

    cek = tujuan;
    inisialisasi_stack(&tumpukan);

    while(R[cek] != -1 && R[cek] != 0 && !stack_penuh(&tumpukan)){
        push(&tumpukan, cek);
        cek = R[cek];
    }

    printf("%d ", asal+1);
    while(!stack_kosong(&tumpukan)){
        temp = pop(&tumpukan);

        if (temp == M)
            printf("- \n\n"); 
        else
            printf("%d - ", temp); 
    }
    printf("%d ", tujuan+1);

    printf("\nBeban = ");
    if (TQ[tujuan] == M)
        printf("\n\n"); 
    else
        printf("%d\n\n", TQ[tujuan]);

    printf("Matriks TQ\t : ");
    for(i = 0; i < jumlah_node; i++){
        if (TQ[i] == M)
            printf("%2s ", "M"); 
        else
            printf("%2d ", TQ[i]);
    }
    printf("\nMatriks R\t : ");
    for(i = 0; i < jumlah_node; i++){
        if (R[i] == M)
            printf("%2s ", "M"); 
        else
            printf("%2d ", R[i]);
    }
    puts("\n");
}

void inisialisasi_stack(stack *s){
    s->count = 0;
}

int stack_kosong(stack *s){
    return (s->count == 0) ? 1: 0;
}

int stack_penuh(stack *s){
    return (s->count == MAX) ? 1 : 0;
}

void push(stack *s, int x){
    if(stack_penuh(s))
        puts("\nStack stack_penuh, tidak bisa melakukan push\n");
    else {
        s->data[s->count] = x;
        s->count++;
    }
}

int pop(stack *s){
    int temp;

    if(stack_kosong(s)){
        puts("\nStack stack_kosong, tidak bisa melakukan pop\n");
    } else {
        --s->count;
        temp = s->data[s->count];
        return temp;
    }
}

void inisialisasi_queue(queue *q){
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int queue_kosong(queue *q){
    return (q->count == 0) ? 1: 0;
}

int queue_penuh(queue *q){
    return (q->count == MAX) ? 1 : 0;
}

void enqueue(int x, queue *q){
    if(queue_penuh(q))
        puts("\nQueue stack_penuh, tidak bisa melakukan Enqueue");
    else {
        q->data[q->rear] = x;
        q->rear = (q->rear+1)%MAX;
        q->count++;
    }
}

int dequeue(queue *q){
    int temp;

    if(queue_kosong(q))
        puts("Queue stack_kosong, tidak bisa melakukan Dequeue\n");
    else {
        temp = q->data[q->front];
        q->front = (q->front+1)%MAX;
        q->count--;
    }

    return temp;
}

int in_queue(queue *q, int x){
    int i;

    for(i = q->front; i <= q->rear; i++){
        if(q->data[i] == x)
            return 1;
    }
    return 0;
}