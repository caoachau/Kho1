//Yêu cauu 1/  Tìm 10 so Fibonacci dauu tiên su dung phuong pháp de quy#
#include <stdio.h>
#include <conio.h>
#include <string.h>

int Fibo( int n)
{    int f0 = 0;
     int f1 = 1;
     int fn = 1;
     int i;
	if (n<0)      { return -1;}
	 else if (n==0 || n==1 )
	              { return n;}
	 else         { for (i = 2; i < n; i++) {
                      f0 = f1;
                      f1 = fn;
                      fn = f0 + f1;}}
 return fn;	  
	 
}
 int main()
 { 
 printf("10 so dau tien cua day so Fibonacci: \n");
    for (int i = 0; i < 10; i++) 
	{
        printf("%d ", Fibo(i));
    }
}
 
