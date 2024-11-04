#include <stdio.h>

void nhap(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap pt thu a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuat(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void max(int a[], int n) {
    if (n <= 0) {
        printf("Mang rong, khong co gia tri max.\n");
        return;
    }
    
    int M = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > M) {
            M = a[i];
        }
    }
    printf("MAX: %d\n", M);
    
    printf("vi tri so co gia tri MAX: ");
    for (int i = 0; i < n; i++) {
        if (a[i] == M) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void min(int a[], int n) {
    if (n <= 0) {
        printf("Mang rong, khong co gia tri max.\n");
        return;
    }
    
    int m = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < m) {
            m = a[i];
        }
    }
    printf("min: %d\n", m);
    
    printf("vi tri so co gia tri MAX: ");
    for (int i = 0; i < n; i++) {
        if (a[i] == m) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int main() {
    int n;
    int a[100];
    printf("nhap n: ");
    scanf("%d", &n);
    
    
    if (n > 0 && n <= 100) {
        nhap(a, n);
        printf("Cac pt: ");
        xuat(a, n);
        max(a, n);
        min(a,n);
    } else {
        printf("Nhap n tu 1 den 100.\n");
    }

    return 0;
}

