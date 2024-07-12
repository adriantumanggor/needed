#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define Max 100

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Stack
{
    Node *items[Max];
    int top;
} Stack;

Node *root, *p;
Stack stOperator, stOperan;

void initStack(Stack *s);
int kosong(Stack *s);
void push(Stack *s, Node *item);
Node *pop(Stack *s);
Node *lihat(Stack *s);
void bentuk(char data);
int derajat(char op);
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);
void Tree(char *expression);
void Input(char *expression);
void subTree();
void cetak(Node *root);

int main()
{
    char S[Max];

    Input(S);

    Tree(S);

    cetak(root);

    return 0;
}

void initStack(Stack *s)
{
    s->top = -1;
}

int kosong(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, Node *item)
{
    if (s->top < Max - 1)
    {
        s->items[++s->top] = item;
    }
}

Node *pop(Stack *s)
{
    if (!kosong(s))
    {
        return s->items[s->top--];
    }
    return NULL;
}

Node *lihat(Stack *s)
{
    if (!kosong(s))
    {
        return s->items[s->top];
    }
    return NULL;
}

void bentuk(char data)
{
    p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
}

int derajat(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

void preorder(Node *root)
{
    if (root)
    {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

void Tree(char *expression)
{
    Node *operator, * right, *left;

    initStack(&stOperator);
    initStack(&stOperan);

    int N = strlen(expression);

    for (int i = 0; i < N; i++)
    {
        char R = expression[i];

        if (R == '(')
        {
            bentuk(R);
            push(&stOperator, p);
        }
        else if (isdigit(R) || isalpha(R))
        {
            bentuk(R);
            push(&stOperan, p);
        }
        else if (R == '+' || R == '-' || R == '*' || R == '/' || R == '^')
        {
            while (!kosong(&stOperator) && derajat(R) <= derajat(lihat(&stOperator)->data))
            {
                subTree();
            }
            bentuk(R);
            push(&stOperator, p);
        }
        else if (R == ')')
        {
            while (lihat(&stOperator)->data != '(')
            {
                subTree();
            }
            pop(&stOperator);
        }
    }

    while (!kosong(&stOperator))
    {
        subTree();
    }

    root = pop(&stOperan);
}

void Input(char *expression)
{
    printf("Masukkan ekspresi aritmatika dalam notasi infix: ");
    fgets(expression, Max, stdin);

    size_t length = strlen(expression);
    if (length > 0 && expression[length - 1] == '\n')
    {
        expression[length - 1] = '\0';
    }
}

void subTree()
{
    Node *operator= pop(&stOperator);
    Node *kanan = pop(&stOperan);
    Node *kiri = pop(&stOperan);

    operator->left = kiri;
    operator->right = kanan;

    push(&stOperan, operator);
}

void cetak(Node *root)
{
    printf("Preorder :");
    preorder(root);
    printf("\nInorder :");
    inorder(root);
    printf("\nPostorder :");
    postorder(root);
    printf("\n");
}
