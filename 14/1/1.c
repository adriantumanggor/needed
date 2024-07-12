#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node *root = NULL;
Node *p = NULL;

void bentuk(char data);
void sisip(char data);
void menu_kunjungan(int *pilihan);
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);
void cari(Node *root, char key);
void input();
void kunjungan();
void caridata();

int main()
{
    input();
    kunjungan();
    caridata();

    return 0;
}

void bentuk(char data)
{
    p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
}

void sisip(char data)
{
    Node *current;
    Node *parent;

    if (root == NULL)
    {
        bentuk(data);
        root = p;
    }
    else
    {
        current = root;
        parent = NULL;

        while (current != NULL)
        {
            parent = current;
            if (data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        bentuk(data);
        
        if (data < parent->data)
        {
            parent->left = p;
        }
        else
        {
            parent->right = p;
        }
    }
}

void menu_kunjungan(int *pilihan)
{
    printf("Pilih Penelusuran Tree\n");
    printf("1. Preorder\n");
    printf("2. PostOrder\n");
    printf("3. Inorder\n");
    printf("Pilihan : ");
    scanf("%d", pilihan);
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

void cari(Node *root, char key)
{
    if (root == NULL)
    {
        printf("Data '%c' tidak ditemukan di tree.\n", key);
        return;
    }
    if (root->data == key)
    {
        printf("Data '%c' ditemukan di tree.\n", key);
        return;
    }
    if (key < root->data)
    {
        cari(root->left, key);
    }
    else
    {
        cari(root->right, key);
    }
}

void input()
{
    char input[100];
    printf("MEMBENTUK SEBUAH TREE\n");
    printf("Ketikkan data/infonya, pisahkan dengan spasi: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (!isspace(input[i]))
        {
            sisip(input[i]);
        }
    }
}

void kunjungan()
{
    char lagi;

    do
    {
        int pilihan;
        menu_kunjungan(&pilihan);

        switch (pilihan)
        {
        case 1:
            printf("Hasil penelusuran menggunakan Preorder :\n");
            preorder(root);
            break;
        case 2:
            printf("Hasil penelusuran menggunakan PostOrder :\n");
            postorder(root);
            break;
        case 3:
            printf("Hasil penelusuran menggunakan Inorder :\n");
            inorder(root);
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }

        printf("\nMau mencoba metode penelusuran lain? (y/t): ");
        scanf(" %c", &lagi);
    } while (lagi == 'y');
}

void caridata()
{
    char lagi;
    char cari_data;

    do
    {
        printf("\nMasukkan data yang ingin dicari: ");
        scanf(" %c", &cari_data);

        cari(root, cari_data);

        printf("Mau mencari data lain? (y/t): ");
        scanf(" %c", &lagi);
    } while (lagi == 'y');
}
