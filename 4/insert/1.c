    #include <stdio.h>
    #include <stdlib.h>

    typedef struct Node
    {
        int data;
        struct Node *prev;
        struct Node *next;
    } Node;

    Node *head, *p;

    void input();
    void insertawal();
    void tampil();

    int main()
    {
        char jwb;

        puts("DLL INSERT AWAL");

        do
        {
            puts("");

            input();

            printf("Mau lagi(y/t):");
            scanf(" %c", &jwb);
        } while (jwb != 't');

        tampil();

        return 0;
    }

    void input()
    {

        int data;

        printf("masukkan data:");
        scanf("%d", &data);

        p = (Node *)malloc(sizeof(Node));
        p->data = data;
        p->prev = NULL;
        p->next = NULL;

        insertawal();
    }

    void insertawal()
    {
        if (head != NULL)
        {
            p->next = head;
            head->prev = p;
        }
        head = p;
    }

    void tampil()
    {
        Node *tampil = head;

        while (tampil != NULL)
        {
            printf("%d ", tampil->data);
            tampil = tampil->next;
        }
        puts("");
    }