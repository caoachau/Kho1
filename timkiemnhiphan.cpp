#include <stdio.h>
void nhap(int a[], int &n) {
    do {
        printf("Nhap n: ");
        scanf("%d", &n);
        if (n <= 0) printf("\nNhap lai n!");
    } while (n < 2 || n > 99);

    for (int i = 0; i < n; i++) {
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void xuat(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d", a[i]);
    }
}

void sx(int a[], int &n)
    {    
    int w;
    for(int i = 0; i < n - 1; i++)
	{
        for(int j = i + 1; j < n; j++)
		{
            if(a[i] > a[j])
			{
               
                w = a[i];
                a[i] = a[j];
                a[j] = w;    
            }
        }
	}
    printf ("\nMang tang dan tu:");
    xuat(a,n);   
    }

int tim(int a[], int n, int x) {
    int l = 0;
    int r = n - 1;
    int mid;
    do {
        mid = (l + r) / 2;
        if (x == a[mid]) return mid;
        if (x < a[mid]) r = mid - 1;
        else if (x > a[mid]) l = mid + 1;
    } while (l <= r);
    return -1;
}

int main() {
    int a[100];
    int n;
    nhap(a, n);

    xuat(a, n);

    sx(a, n);

    int x;
    printf("\nNhap x: ");
    scanf("%d", &x);
    int result = tim(a, n, x);
    if (result != -1)
        printf("Vi tri cua %d trong mang la: %d\n", x, result);
    else
        printf("%d khong co trong mang.\n", x);
    return 0;
}
