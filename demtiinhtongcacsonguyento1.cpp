#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
//nhap va xuat mang
{
	int n,i;
	int a[100];
	printf("Nhap so pt:"); 
	scanf("%d", &n);
for (int i =0;i <n; i++)
  {
    scanf("%d", &a[i]);
   }
    printf("Mang vua nhap la:");
    for(i=0;i<n;i++)
    {
        printf("%4d",a[i]);
    }
    //tim gia tri max
  int maxx = a[0];
    for(int i = 0; i<n;i++)
    {
        if(a[i] > maxx) maxx = a[i];
         printf("\n max la: %d", maxx);
    }
    //tinh tich cac phan tu
 int tich=1;
 for(int i=0; i<n; i++)
      { 
        tich=tich*a[i];
        printf("\nTich:%d", tich);
      }
      // kiem tra so nguyen to
      if (n<=0) 
      printf("SAI! Hay nhap lai mang");
      bool Kiemtrasonguyento(a[i]);
      if (a[i]< 2) return false;
                  else return true;
       if (n%2==0) return false;
       // dem va tinh tong cac so nguyen to
       int tong=0;
       int dem=0;
       int x;
        bool KTSNT(int x);
     	if(x<2)
		return false;
    	for(int i=2; i<=x/2; i++)
		if(x%i==0)
  			    return false; 
    	else    return true;
    	
    	printf("So luong so nguyen to trong mang",x);
    
 
     
}


    
 
 
