#include<stdio.h>
#include<conio.h>
#include<string.h>



void nhapMang(int A[], int &n, int i = 0)
{
    // �i?u ki?n d?ng
    if(i == n) // D?ng d? quy khi ch? s? i = n (n: s? lu?ng ph?n t? c?a m?ng)
        return;

    // Nh?p m?ng
    printf("Nhap phan tu thu A[%d] = ", i);
    scanf("%d", &A[i]);

    // G?i l?i h�m d? quy
    // d?ng th?i tang gi� tr? c?a ch? s? i l�n
    // di?u n�y cung tuong t? nhu s? d?ng v�ng l?p for d? duy?t m?ng.
    nhapMang(A, n, i + 1);
}

void xuatMang(int A[], int n, int i = 0){

    // �i?u ki?n d?ng
    if(i == n)
        return;

    // Xu?t m?ng
    printf("%5d", A[i]);

    // G?i l?i h�m d? quy
    xuatMang(A, n, i + 1);
}
int main()
{
    int n;
    int A[100];

    printf("Nhap so luong phan tu cua mang = ");
    scanf("%d", &n);
    nhapMang(A,n);

    printf("Mang da nhap la:\n");
    xuatMang(A, n);
    printf("\n");

    return 1;
}
