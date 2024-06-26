
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> 
typedef struct sv {
    char hoten[40];
    int tuoi;
} sv;

typedef struct node {
    sv data;
    struct node *left;
    struct node *right;
} node;

typedef node* TREE;

TREE insertNode(TREE root, sv x) {
    if (root == NULL) {
        root = (TREE)malloc(sizeof(node));
        root->data = x;
        root->left = NULL;
        root->right = NULL;
    } else if (strcmp(x.hoten, root->data.hoten) < 0) {
        root->left = insertNode(root->left, x);
    } else {
        root->right = insertNode(root->right, x);
    }
    return root;
}

TREE minValueNode(TREE node) {
    TREE current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

TREE deleteNode(TREE root, char *hoten) {
    if (root == NULL) return root;

    if (strcmp(hoten, root->data.hoten) < 0)
        root->left = deleteNode(root->left, hoten);
    else if (strcmp(hoten, root->data.hoten) > 0)
        root->right = deleteNode(root->right, hoten);
    else {
        if (root->left == NULL) {
            TREE temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TREE temp = root->left;
            free(root);
            return temp;
        }

        TREE temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data.hoten);
    }
    return root;
}

void updateNode(TREE root, char *hoten, sv newData) {
    if (root == NULL) return;

    if (strcmp(hoten, root->data.hoten) < 0)
        updateNode(root->left, hoten, newData);
    else if (strcmp(hoten, root->data.hoten) > 0)
        updateNode(root->right, hoten, newData);
    else
        root->data = newData;
}

TREE searchNode(TREE root, char *hoten) {
    if (root == NULL || strcmp(root->data.hoten, hoten) == 0)
        return root;

    if (strcmp(root->data.hoten, hoten) < 0)
        return searchNode(root->right, hoten);

    return searchNode(root->left, hoten);
}

void replaceNode(TREE root, char *oldName, char *newName, sv newData) {
    // First, delete the node with the old name
    root = deleteNode(root, oldName);
    // Then, insert a new node with the new name and data
    root = insertNode(root, newData);
}

void taocay(TREE *root) {
    sv x;
    char key;
    int firstOption = 1;

    do {
        printf("\nNhap thong tin sv:");
        printf("\nNhap ho ten: ");
        fgets(x.hoten, sizeof(x.hoten), stdin);
        x.hoten[strcspn(x.hoten, "\n")] = '\0'; // Remove newline character

        if (strlen(x.hoten) == 0) {
            printf("Ho ten khong duoc de trong!\n");
            continue;
        }

        printf("Nhap tuoi: ");
        if (scanf("%d", &x.tuoi) != 1) {
            printf("Tuoi phai la so nguyen!\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }
        getchar(); // Clear newline character left by scanf

        *root = insertNode(*root, x);

        if (firstOption) {
            printf("\nNhan Enter de tiep tuc them node, nhan Esc de quay ve menu.\n");
            firstOption = 0;
        } else {
            printf("\nNode da duoc them. Nhan Enter de tiep tuc them node, nhan Esc de quay ve menu.\n");
        }

        key = getch();
        if (key == 27) { // ASCII value of 'Esc' key
            break;
        }

    } while (key == 13); // ASCII value of 'Enter' key
}

void NLR(TREE root) {
    if (root != NULL) {
        printf("\nHo ten: %s", root->data.hoten);
        printf("\nTuoi: %d", root->data.tuoi);
        NLR(root->left);
        NLR(root->right);
    }
}

void LRN(TREE root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        printf("\nHo ten: %s", root->data.hoten);
        printf("\nTuoi: %d", root->data.tuoi);
    }
}

void LNR(TREE root) {
    if (root != NULL) {
        LNR(root->left);
        printf("\nHo ten: %s", root->data.hoten);
        printf("\nTuoi: %d", root->data.tuoi);
        LNR(root->right);
    }
}

// H�m t�nh chi?u cao c?a c�y
int treeHeight(TREE root) {
    if (root == NULL)
        return 0;
    else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
    }
}

// H�m t?m node trong c�y
TREE findNode(TREE root, char *hoten) {
    if (root == NULL)
        return NULL;
    if (strcmp(root->data.hoten, hoten) == 0)
        return root;
    TREE leftResult = findNode(root->left, hoten);
    if (leftResult != NULL)
        return leftResult;
    return findNode(root->right, hoten);
}



// H�m gi?i ph�ng b? nh? c?a c�y
void freeTree(TREE root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    TREE t = NULL;
    int choice;
    char hoten[40], newHoten[40];
    sv new_sv;

    while (1) {
        printf("\nMenu:");
        printf("\n1. Tao cay");
        printf("\n2. Them node");
        printf("\n3. Xoa node");
        printf("\n4. Sua node");
        printf("\n5. Tim node");
        printf("\n6. Thay the node");
        printf("\n7. Duyet cay (NLR)");
        printf("\n8. Duyet cay (LRN)");
        printf("\n9. Duyet cay (LNR)");
        printf("\n10.Chieu cao cua cay"); 
        printf("\n11.Tim node:"); 
        printf("\n12.Giai phong bo nho cua cay");
        printf("\n0. Thoat");
        printf("\nChon: ");
        if (scanf("%d", &choice) != 1) {
            printf("Lua chon khong hop le. Vui long chon ");         
			while (getchar() != '\n'); // Clear invalid input
            continue;
        }
        getchar(); // Clear newline character left by scanf

        switch (choice) {
            case 1:
                taocay(&t);
                break;
            case 2:
                printf("\nNhap ho ten: ");
                fgets(new_sv.hoten, sizeof(new_sv.hoten), stdin);
                new_sv.hoten[strcspn(new_sv.hoten, "\n")] = '\0'; // Remove newline character
                printf("Nhap tuoi: ");
                if (scanf("%d", &new_sv.tuoi) != 1) {
                    printf("Tuoi phai la so nguyen!\n");
                    while (getchar() != '\n'); // Clear invalid input
                    continue;
                }
                getchar(); // Clear newline character left by scanf
                t = insertNode(t, new_sv);
                break;
            case 3:
                printf("\nNhap ho ten cua node can xoa: ");
                fgets(hoten, sizeof(hoten), stdin);
                hoten[strcspn(hoten, "\n")] = '\0'; // Remove newline character
                t = deleteNode(t, hoten);
                break;
            case 4:
                printf("\nNhap ho ten cua node can sua: ");
                fgets(hoten, sizeof(hoten), stdin);
                hoten[strcspn(hoten, "\n")] = '\0'; //Remove newline character
                printf("Nhap thong tin moi:\n");
                printf("Nhap ho ten moi: ");
                fgets(new_sv.hoten, sizeof(new_sv.hoten), stdin);
                new_sv.hoten[strcspn(new_sv.hoten, "\n")] = '\0'; // Remove newline character
                printf("Nhap tuoi moi: ");
                scanf("%d", &new_sv.tuoi);
                getchar(); // Clear newline character left by scanf
                updateNode(t, hoten, new_sv);
                break;
            case 5:
              { 
			  printf("\nNhap ho ten cua node can tim: ");
                fgets(hoten, sizeof(hoten), stdin);
                hoten[strcspn(hoten, "\n")] = '\0'; // Remove newline character
                TREE searchedNode = searchNode(t, hoten);
                if (searchedNode != NULL) {
                    printf("\nNode da tim thay:");
                    printf("\nHo ten: %s", searchedNode->data.hoten);
                    printf("\nTuoi: %d", searchedNode->data.tuoi);
                } else {
                    printf("\nKhong tim thay node co ho ten \"%s\".", hoten);
                }             
              }
                break;
            case 6:
            	{
                printf("\nNhap ho ten cua node can thay the: ");
                fgets(hoten, sizeof(hoten), stdin);
                hoten[strcspn(hoten, "\n")] = '\0'; // Remove newline character
                printf("\nNhap thong tin moi:\n");
                printf("Nhap ho ten moi: ");
                fgets(newHoten, sizeof(newHoten), stdin);
                newHoten[strcspn(newHoten, "\n")] = '\0'; // Remove newline character
                printf("Nhap tuoi moi: ");
                scanf("%d", &new_sv.tuoi);
                getchar(); // Clear newline character left by scanf
                replaceNode(t, hoten, newHoten, new_sv);
                }
                break;
                
                
            case 7:
                printf("\nDuyet cay theo thu tu truoc (NLR):");
                NLR(t);
                break;
            case 8:
                printf("\nDuyet cay theo thu tu sau (LRN):");
                LRN(t);
                break;
            case 9:
                printf("\nDuyet cay theo thu tu giua (LNR):");
                LNR(t);
                break;

            case 10: 
            {
			printf("\n Chieu cao cua cay: %d " , treeHeight(t));
		    }
            break;
			           
            case 11:
            {	
             printf("\nNhap ho ten cua node can tim: ");
             fgets(hoten, sizeof(hoten), stdin);
             hoten[strcspn(hoten, "\n")] = '\0'; // Remove newline character
             TREE foundNode = findNode(t, hoten);
             if (foundNode != NULL) {
             printf("\nNode da tim thay:");
             printf("\nHo ten: %s", foundNode->data.hoten);
             printf("\nTuoi: %d", foundNode->data.tuoi);
             } else {
             printf("\nKhong tim thay node co ho ten \"%s\".", hoten);
             }
            }
            break;
            case 12:
              {
			  printf("\nGiai phong bo nho cua cay.");
            freeTree(t);
             t = NULL;
              }
             break;

            case 0:
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    }

    return 0;
}


