#include <stdio.h>
#include <stdbool.h>

void nhap(int a[], int *n) {
    do {
        printf("Nhap n: ");
        scanf("%d", n);
        if (*n <= 0) printf("\nNhap lai n!");
    } while (*n < 2 || *n > 99);

    for (int i = 0; i < *n; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void hv(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int phandoan(int a[], int low, int high) {
    int p = a[high];
    int left = low;
    int right = high - 1;
    
    while (true) {
        while (left <= right && a[left] < p) left++;
        while (right >= left && a[right] > p) right--;
        
        if (left >= right) break;
        hv(&a[left], &a[right]);
        left++;
        right--;		
    }
    
    hv(&a[left], &a[high]);
    return left;	
}

void qs(int a[], int low, int high) {
    if (low < high) {
        int i = phandoan(a, low, high);
        qs(a, low, i - 1);
        qs(a, i + 1, high);
    }
}

void xuat(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d\t", a[i]);
    }
}

int main() {
    int a[100];
    int n, low = 0, high;
    nhap(a, &n);
    high = n - 1;
    qs(a, low, high);
    xuat(a, n);
    
    return 0;
}
