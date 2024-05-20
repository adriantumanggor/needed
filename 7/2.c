#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode
{
    char data;
    struct QueueNode *next;
} QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

void createQueue(Queue *);
int kosong(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);
void display(Queue *);

int main()
{
    Queue q;
    createQueue(&q);
    int choice, element;

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
            printf("Masukkan elemen yang ingin dimasukkan: ");
            scanf(" %c", &element);
            enqueue(&q, element);
            break;
        case 2:
            element = dequeue(&q);
            if (element != -1)
            {
                printf("Elemen %c telah diambil dari Queue\n", element);
            }
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
    q->front = NULL;
    q->rear = NULL;
}

int kosong(Queue *q)
{
    return (q->front == NULL && q->rear == NULL);
}

void enqueue(Queue *q, int value)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL)
    {
        printf("Queue penuh. Tidak dapat menambahkan elemen %c\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (kosong(q))
    {
        q->front = newNode;
    }
    else
    {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    printf("Elemen %c telah dimasukkan ke dalam Queue\n", value);
}

int dequeue(Queue *q)
{
    if (kosong(q))
    {
        printf("Queue kosong\n");
        return -1;
    }
    int removed = q->front->data;
    QueueNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    return removed;
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
        QueueNode *current = q->front;
        while (current != NULL)
        {
            printf("%c ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}