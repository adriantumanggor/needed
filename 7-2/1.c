#include <stdio.h>
#define MAX_SIZE 5

typedef char itemtype;

typedef struct
{
    int front;
    int rear;
    itemtype items[MAX_SIZE];
} Queue;

void createQueue(Queue *);
int kosong(Queue *);
int penuh(Queue *);
void display(Queue *);
void enqueue(Queue *, itemtype);
itemtype dequeue(Queue *);
void minmax(Queue *);
void cari(Queue *);

int main()
{
    Queue q;
    createQueue(&q);
    int choice, data;

    do
    {
        printf("\nMenu:\n");
        printf("1. Tambah data (enqueue)\n");
        printf("2. Hapus data (dequeue)\n");
        printf("3. Tampilkan data min & max\n");
        printf("4. cari data\n");
        printf("5. Menampilkan isi queue\n");
        printf("6. Keluar\n");
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
            printf("data %c telah diambil dari Queue\n", dequeue(&q));
            break;
        case 3:
            minmax(&q);
            break;
        case 4:
            cari(&q);
            break;
        case 5:
            display(&q);
            break;
        case 6:
            printf("Program berakhir.\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (choice != 6);

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

void enqueue(Queue *q, itemtype value)
{
    if (penuh(q))
    {
        printf("Queue penuh. Tidak dapat menambahkan data %c\n", value);
    }
    else
    {
        if (kosong(q))
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("data %c telah dimasukkan ke dalam Queue\n", value);
    }
}

itemtype dequeue(Queue *q)
{
    int removed = q->items[q->front];

    if (kosong(q))
    {
        printf("Queue kosong\n");
        return '\0';
    }
    
    else
    {
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front++;
        }
        return removed;
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

void minmax(Queue *q)
{
    char min = q->items[q->front];
    char max = min;

    if (kosong(q))
    {
        printf("Queue kosong\n");
    }

    else
    {
        for (int i = q->front + 1; i <= q->rear; i++)
        {
            if (q->items[i] < min)
                min = q->items[i];
            if (q->items[i] > max)
                max = q->items[i];
        }

        printf("Nilai minimum: %c\n", min);
        printf("Nilai maksimum: %c\n", max);
    }
}

void cari(Queue *q)
{
    char target;
    int dapat = 0;
        
    if (kosong(q))
    {
        printf("Queue kosong\n");
    }
    else
    {
        printf("Masukkan data yang ingin dicari: ");
        scanf(" %c", &target);
        for (int i = q->front; i <= q->rear; i++)
        {
            if (q->items[i] == target)
            {
                printf("Data %c ditemukan pada indeks %d\n", target, i);
                dapat = 1;
                break;
            }
        }
        if (!dapat)
        {
            printf("Data %c tidak ditemukan dalam queue\n", target);
        }
    }
}
