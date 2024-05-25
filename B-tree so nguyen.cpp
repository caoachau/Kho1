#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define M 5 // Ð?nh ngh?a ð? dày c?a B-tree

// Ð?nh ngh?a c?u trúc cho m?t nút B-tree
struct BTreeNode {
    int *keys; // M?ng ch?a các khóa
    int t; // Ð? dày c?a B-tree
    struct BTreeNode **children; // M?ng ch?a các con tr? t?i các nút con
    int n; // S? lý?ng khóa hi?n t?i
    int leaf; // Tr?ng thái lá c?a nút (1 n?u là lá, 0 n?u không)
};

// Hàm t?o m?t nút m?i cho B-tree
struct BTreeNode *createNode(int t, int leaf) {
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    if (newNode != NULL) {
        newNode->t = t;
        newNode->leaf = leaf;
        newNode->keys = (int *)malloc(sizeof(int) * (2 * t - 1));
        newNode->children = (struct BTreeNode **)malloc(sizeof(struct BTreeNode *) * (2 * t));
        newNode->n = 0;
    }
    return newNode;
}

void splitChild(struct BTreeNode *parent, int index, struct BTreeNode *child) {
    struct BTreeNode *newNode = createNode(child->t, child->leaf);
    newNode->n = M - 1;
    for (int i = 0; i < M - 1; i++) {
        newNode->keys[i] = child->keys[i + M];
    }
    if (!child->leaf) {
        for (int i = 0; i < M; i++) {
            newNode->children[i] = child->children[i + M];
        }
    }
    child->n = M - 1;
    for (int i = parent->n; i >= index + 1; i--) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = newNode;
    for (int i = parent->n - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }
    parent->keys[index] = child->keys[M - 1];
    parent->n++;
}
// Hàm chèn m?t khóa vào m?t nút không ð?y
void insertNonFull(struct BTreeNode *root, int key) {
    int i = root->n - 1;
    if (root->leaf) {
        while (i >= 0 && key < root->keys[i]) {
            root->keys[i + 1] = root->keys[i];
            i--;
        }
        root->keys[i + 1] = key;
        root->n++;
    } else {
        while (i >= 0 && key < root->keys[i]) {
            i--;
        }
        if (root->children[i + 1]->n == 2 * root->t - 1) {
            splitChild(root, i + 1, root->children[i + 1]);
            if (key > root->keys[i + 1]) {
                i++;
            }
        }
        insertNonFull(root->children[i + 1], key);
    }
}

// Hàm chèn m?t khóa vào B-tree
struct BTreeNode *insert(struct BTreeNode *root, int key) {
    if (root == NULL) {
        root = createNode(M, 1);
        root->keys[0] = key;
        root->n = 1;
        return root;
    }
    if (root->n == 2 * M - 1) {
        struct BTreeNode *s = createNode(M, 0);
        s->children[0] = root;
        splitChild(s, 0, root);
        int i = 0;
        if (s->keys[0] < key) {
            i++;
        }
        insertNonFull(s->children[i], key);
        return s;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

// Hàm t?m và chia m?t nút con c?a m?t nút B-tree ð? ð?y


// Hàm t?m m?t khóa trong B-tree
struct BTreeNode *search(struct BTreeNode *root, int key) {
    int i = 0;
    while (i < root->n && key > root->keys[i]) {
        i++;
    }
    if (root->keys[i] == key) {
        return root;
    }
    if (root->leaf) {
        return NULL;
    }
    return search(root->children[i], key);
}

// Hàm in các khóa trong B-tree theo th? t? tãng d?n
void traverse(struct BTreeNode *root) {
    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf) {
            traverse(root->children[i]);
        }
        printf(" %d", root->keys[i]);
    }
    if (!root->leaf) {
        traverse(root->children[i]);
    }
}

// Hàm chính
int main() {
    struct BTreeNode *root = NULL;

    int choice, key;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Chen khao vao B-tree\n");
        printf("2. Tim kiem khao trong B-tree\n");
        printf("3. In B-tree\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Nhap khao can chen: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            }
            case 2: {
                printf("Nhap khao can tim kiem: ");
                scanf("%d", &key);
                struct BTreeNode *foundNode = search(root, key);
                if (foundNode != NULL) {
                    printf("Tim thay khao trong B-tree.\n");
                } else {
                    printf("Khong tim thay khao trong B-tree.\n");
                }
                break;
            }
            case 3: {
                printf("Cay B-tree:\n");
                traverse(root);
                printf("\n");
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Lua chon khong hop le.\n");
                break;
            }
        }
    }

    return 0;
}

