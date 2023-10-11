#include <stdio.h>
#include <conio.h>
#include <cassert>
int main()
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
        printf("%d",a[i]);
    }
  int maxx = a[0];
    for(int i = 0; i<n;i++)
    {
        if(a[i] > maxx) maxx = a[i];
         printf("\n max la: %d", maxx);
    }
 int tich=1;
 for(int i=0; i<n; i++)
      { 
        tich=tich*a[i];
        printf("\nTich:%d", tich);
}
}


    
 
 
