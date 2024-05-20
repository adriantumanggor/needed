#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef char Karakter;
typedef struct stack
{
    Karakter ekspresi[max];
    int count;
} stack;

void inisiasi(stack *);
void push(Karakter, stack *);
Karakter pop(stack *);
void postfix(stack *, Karakter *);
int penuh(stack *);
int kosong(stack *);
int prioritas(Karakter);

int main()
{
    stack notasi;

    char jwb;

    char infix[max];

    inisiasi(&notasi);

    puts("\nMengubah notasi infix menjadi postfix");
    puts("Dengan memanfaatkan Struktur Stack");

    do
    {
        printf("\nMasukkan ekspresi dalam notasi infix :");
        scanf("%s", &infix);

        postfix(&notasi, infix);

        printf("\nlagi(y/t)?");        
        scanf(" %c", &jwb);
    } while (jwb != 't');

    puts("");

    return 0;
}

void inisiasi(stack *s)
{
    s->count = 0;
}

void push(Karakter ekspresi, stack *s)
{
    if (!penuh(s))
    {
        s->ekspresi[s->count] = ekspresi;

        s->count++;
    }
    else
    {
        puts("Penuh, tidak bisa push");
        exit(1);
    }
}

Karakter pop(stack *s)
{
    if (!kosong(s))
    {
        s->count--;

        return s->ekspresi[s->count];
    }
    else
    {
        puts("Kosong, tidak bisa pop");
        exit(1);
    }
}

void postfix(stack *s, Karakter *infix)
{
    Karakter temp;
    int i;

    for (i = 0; i < strlen(infix); i++)
    {
        temp = infix[i];

        switch (temp)
        {
        case '(':
            push(temp, s);
            break;
        case ')':
            while (!kosong(s) && s->ekspresi[s->count - 1] != '(')
            {
                printf("%c", pop(s));
            }
            if (!kosong(s) && s->ekspresi[s->count - 1] == '(')
            {
                pop(s);
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!kosong(s) &&  prioritas(temp) <= prioritas(s->ekspresi[s->count - 1]))
            {
                printf("%c", pop(s));
            }
            
            push(temp, s);
            break;
        default:
            printf("%c", temp);
            break;
        }
    }

    while (!kosong(s))
    {
        printf("%c", pop(s));
    }
}

int prioritas(Karakter operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int penuh(stack *s)
{
    return (s->count == max ? 1 : 0);
}

int kosong(stack *s)
{
    return (s->count == 0 ? 1 : 0);
}