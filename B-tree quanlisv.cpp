#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ð?nh ngh?a c?u trúc cho m?t sinh viên
struct Student {
    int mssv;
    char name[50];
    int age;
    struct Student *left;
    struct Student *right;
};
// Hàm t?m nút lá có giá tr? nh? nh?t trong cây con bên trái
struct Student *minValueNode(struct Student *node) {
    struct Student *current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}


// Hàm xóa m?t sinh viên t? cây
struct Student *deleteNode(struct Student *root, int mssv) {
    if (root == NULL) {
        return root;
    }

    if (mssv < root->mssv) {
        root->left = deleteNode(root->left, mssv);
    } else if (mssv > root->mssv) {
        root->right = deleteNode(root->right, mssv);
    } else {
        // N?u nút có 1 ho?c không có con
        if (root->left == NULL) {
            struct Student *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Student *temp = root->left;
            free(root);
            return temp;
        }

        // N?u nút có 2 con, thay th? nút b?ng nút lá nh? nh?t t? cây con bên ph?i
        struct Student *temp = minValueNode(root->right);
        root->mssv = temp->mssv;
        root->right = deleteNode(root->right, temp->mssv);
    }

    return root;
}

// Hàm t?o m?t nút m?i cho cây
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

// Hàm chèn m?t sinh viên vào cây
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

// Hàm t?m ki?m m?t sinh viên trong cây
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

// Hàm xu?t thông tin c?a m?t sinh viên
void printStudent(struct Student *student) {
    if (student != NULL) {
        printf("MSSV: %d\t", student->mssv);
        printf("Name: %s\t", student->name);
        printf("Age: %d\n", student->age);
    }
}

// Duy?t cây theo th? t? NLR (Trý?c tr?t t?)
void traverseNLR(struct Student *root) {
    if (root != NULL) {
        printStudent(root);
        traverseNLR(root->left);
        traverseNLR(root->right);
    }
}

// Duy?t cây theo th? t? LRN (Sau tr?t t?)
void traverseLRN(struct Student *root) {
    if (root != NULL) {
        traverseLRN(root->left);
        traverseLRN(root->right);
        printStudent(root);
    }
}

// Duy?t cây theo th? t? LNR (Trung tr?t t?)
void traverseLNR(struct Student *root) {
    if (root != NULL) {
        traverseLNR(root->left);
        printStudent(root);
        traverseLNR(root->right);
    }
}

// Hàm nh?p thông tin c?a m?t sinh viên
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

// Hàm chính
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

                   
