#include <stdio.h>
#define MAX_SIZE 5

typedef struct
{
    int front;
    int rear;
    char items[MAX_SIZE];
} Queue;

void createQueue(Queue *);
int kosong(Queue *);
int penuh(Queue *);
void display(Queue *);
void enqueue(Queue *, int);
void dequeue(Queue *);

int main()
{
    Queue q;
    createQueue(&q);
    int choice, data;

    do
    {
        printf("\nMenu:\n");
        printf("1. Mengisi queue (enqueue)\n");
        printf("2. Mengambil queue (dequeue)\n");
        printf("3. Menampilkan isi queue\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukkan data yang ingin dimasukkan: ");
            scanf(" %c", &data);
            enqueue(&q, data);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            printf("Program berakhir.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (choice != 4);

    return 0;
}

void createQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int kosong(Queue *q)
{
    return (q->rear == -1 && q->front == -1);
}

int penuh(Queue *q)
{
    return (q->rear == MAX_SIZE - 1);
}

void enqueue(Queue *q, int value)
{
    if (penuh(q))
    {
        printf("Queue penuh. Tidak dapat menambahkan elemen %c\n", value);
    }
    else
    {
        if (kosong(q))
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Elemen %c telah dimasukkan ke dalam Queue\n", value);
    }
}

void dequeue(Queue *q)
{
    if (kosong(q))
    {
        printf("Queue kosong\n");
    }
    else
    {
        int removed = q->items[q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front++;
        }
        printf("Elemen %c telah diambil dari Queue\n", removed);
    }
}

void display(Queue *q)
{
    if (kosong(q))
    {
        printf("Queue kosong\n");
    }
    else
    {
        printf("Isi Queue: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%c ", q->items[i]);
        }
        printf("\n");
    }
}