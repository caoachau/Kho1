#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �?nh ngh?a c?u tr�c cho m?t sinh vi�n
struct Student {
    int mssv;
    char name[50];
    int age;
    struct Student *left;
    struct Student *right;
};
// H�m t?m n�t l� c� gi� tr? nh? nh?t trong c�y con b�n tr�i
struct Student *minValueNode(struct Student *node) {
    struct Student *current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}


// H�m x�a m?t sinh vi�n t? c�y
struct Student *deleteNode(struct Student *root, int mssv) {
    if (root == NULL) {
        return root;
    }

    if (mssv < root->mssv) {
        root->left = deleteNode(root->left, mssv);
    } else if (mssv > root->mssv) {
        root->right = deleteNode(root->right, mssv);
    } else {
        // N?u n�t c� 1 ho?c kh�ng c� con
        if (root->left == NULL) {
            struct Student *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Student *temp = root->left;
            free(root);
            return temp;
        }

        // N?u n�t c� 2 con, thay th? n�t b?ng n�t l� nh? nh?t t? c�y con b�n ph?i
        struct Student *temp = minValueNode(root->right);
        root->mssv = temp->mssv;
        root->right = deleteNode(root->right, temp->mssv);
    }

    return root;
}

// H�m t?o m?t n�t m?i cho c�y
struct Student *createNode(int mssv, char *name, int age) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    if (newStudent != NULL) {
        newStudent->mssv = mssv;
        strcpy(newStudent->name, name);
        newStudent->age = age;
        newStudent->left = NULL;
        newStudent->right = NULL;
    }
    return newStudent;
}

// H�m ch�n m?t sinh vi�n v�o c�y
struct Student *insert(struct Student *root, int mssv, char *name, int age) {
    if (root == NULL) {
        return createNode(mssv, name, age);
    }

    if (mssv < root->mssv) {
        root->left = insert(root->left, mssv, name, age);
    } else if (mssv > root->mssv) {
        root->right = insert(root->right, mssv, name, age);
    }

    return root;
}

// H�m t?m ki?m m?t sinh vi�n trong c�y
struct Student *search(struct Student *root, int mssv) {
    if (root == NULL || root->mssv == mssv) {
        return root;
    }

    if (mssv < root->mssv) {
        return search(root->left, mssv);
    } else {
        return search(root->right, mssv);
    }
}

// H�m xu?t th�ng tin c?a m?t sinh vi�n
void printStudent(struct Student *student) {
    if (student != NULL) {
        printf("MSSV: %d\t", student->mssv);
        printf("Name: %s\t", student->name);
        printf("Age: %d\n", student->age);
    }
}

// Duy?t c�y theo th? t? NLR (Tr�?c tr?t t?)
void traverseNLR(struct Student *root) {
    if (root != NULL) {
        printStudent(root);
        traverseNLR(root->left);
        traverseNLR(root->right);
    }
}

// Duy?t c�y theo th? t? LRN (Sau tr?t t?)
void traverseLRN(struct Student *root) {
    if (root != NULL) {
        traverseLRN(root->left);
        traverseLRN(root->right);
        printStudent(root);
    }
}

// Duy?t c�y theo th? t? LNR (Trung tr?t t?)
void traverseLNR(struct Student *root) {
    if (root != NULL) {
        traverseLNR(root->left);
        printStudent(root);
        traverseLNR(root->right);
    }
}

// H�m nh?p th�ng tin c?a m?t sinh vi�n
struct Student *inputStudent() {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    if (newStudent != NULL) {
        printf("Nhap MSSV: ");
        scanf("%d", &(newStudent->mssv));
        printf("Nhap ten: ");
        scanf("%s", newStudent->name);
        printf("Nhap tuoi: ");
        scanf("%d", &(newStudent->age));
        newStudent->left = NULL;
        newStudent->right = NULL;
    }
    return newStudent;
}

// H�m ch�nh
int main() {
    struct Student *root = NULL;

    int choice, mssv;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Chen sinh vien\n");
        printf("2. Xoa sinh vien\n");
        printf("3. Tim kiem sinh vien\n");
        printf("4. Duyet cay theo NLR (Truoc truot tu)\n");
        printf("5. Duyet cay theo LRN (Sau truot tu)\n");
        printf("6. Duyet cay theo LNR (Trung truot tu)\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Student *newStudent = inputStudent();
                if (newStudent != NULL) {
                    root = insert(root, newStudent->mssv, newStudent->name, newStudent->age);
                    printf("Sinh vien da duoc chen vao cay.\n");
                } else {
                    printf("Nhap khong hop le.\n");
                }
                break;
                   }
            
            case 2: {
                printf("Nhap MSSV cua sinh vien can xoa: ");
                scanf("%d", &mssv);
                struct Student *deletedStudent = search(root, mssv);
                if (deletedStudent != NULL) {
                    root = deleteNode(root, mssv);
                    printf("Sinh vien co MSSV %d da bi xoa khoi cay.\n", mssv);
                } else {
                    printf("Khong tim thay sinh vien co MSSV %d.\n", mssv);
                }
                break;
            }
            case 3: {
                printf("Nhap MSSV cua sinh vien can tim kiem: ");
                scanf("%d", &mssv);
                struct Student *foundStudent = search(root, mssv);
                if (foundStudent != NULL) {
                    printf("Thong tin sinh vien tim kiem:\n");
                    printStudent(foundStudent);
                } else {
                    printf("Khong tim thay sinh vien co MSSV %d.\n", mssv);
                }
                break;
            }
            case 4: {
                printf("Duyet cay theo NLR (Truoc truot tu):\n");
                traverseNLR(root);
                break;
            }
            case 5: {
                printf("Duyet cay theo LRN (Sau truot tu):\n");
                traverseLRN(root);
                break;
            }
            case 6: {
                printf("Duyet cay theo LNR (Trung truot tu):\n");
                traverseLNR(root);
                break;
            }
            case 7: {
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

                   
