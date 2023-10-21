#include <stdio.h>
#include <conio.h>

//ham nhap va xuat mang 2 chieu
void Nhapmang2chieu(int a[][], int &m,int &n)
 do{
     
 printf("Nhap so cot:"); scanf("%d",&m);
 printf("\nNhap so hang:"); scanf("%d",&m);
   }
 while (n<2||n>99 && m<2||m>99);
 for (int i=0; i<m;i++);
 for (int j=0;j<n;j++);
      {
         printf("a[%d][%d}= ", i,j);
         scanf("%d",&a[i][j]);
       }

void Xuatmang2chieu(int a[][], int &m,int&n)
{
     for (int i=0; i<m;i++);
      for (int j=0;j<n;j++);
      {
          printf("%4d", a[i][j]);
      }
     
}          

}
int main()
{
    int a[100][100];
    int m,n;
    Nhapmang2chieu(a[][],m.n);
}
