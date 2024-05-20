#include <stdio.h>
#define MAX_SIZE 10
typedef char itemtype;

typedef struct
{
    int front;
    int rear;
    itemtype items[MAX_SIZE];
    int priorities[MAX_SIZE];
} Queue;

void createQueue(Queue *);
int kosong(Queue *);
int penuh(Queue *);
void display(Queue *);
void enqueue(Queue *, itemtype, int);
itemtype dequeue(Queue *);

int main()
{
    Queue q;
    createQueue(&q);
    int choice;
    char data;
    int priority;

    do
    {
        printf("\nMenu PRIORITY:\n");
        printf("1. mengisi data (enqueue)\n");
        printf("2. mengambil data (dequeue)\n");
        printf("3. Tampilkan isi queue\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukkan data yang ingin dimasukkan: ");
            scanf(" %c", &data);
            printf("Masukkan nilai prioritas: ");
            scanf("%d", &priority);
            enqueue(&q, data, priority);
            break;
        case 2:
            printf("data %c telah diambil dari Queue\n", dequeue(&q));
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

void enqueue(Queue *q, char value, int priority)
{
    int i;

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

        for (i = q->rear; i >= q->front; i--)
        {
            if (i == q->front || priority >= q->priorities[i - 1])
            {
                q->items[i] = value;
                q->priorities[i] = priority;
                break;
            }

            else
            {
                q->items[i] = q->items[i - 1];
                q->priorities[i] = q->priorities[i - 1];
            }
        }
        printf("data %c telah dimasukkan ke dalam Queue\n", value, priority);
    }
}

itemtype dequeue(Queue *q)
{
    char removed;
    int removedPriority;

    if (kosong(q))
    {
        printf("Queue kosong\n");
        return '\0';
    }
    else
    {
        removed = q->items[q->front];
        removedPriority = removed;

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
        printf("\nData \t prioritas");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("\n%c \t %d", q->items[i], q->priorities[i]);
        }
        printf("\n");
    }
}
