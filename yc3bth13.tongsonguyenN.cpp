#include<stdio.h>
#include<conio.h>
#include<string.h>

int tong(int n)
{
	int T;
	
	if (n==1) {return 1;}
	else {T= n+tong(n-1);}
	return (T);
}
int main()
{
int i,n,T;
printf("Nhap so nguyen duong:"); scanf("%d",&n);	
T=tong(n);
printf("Tong cac so tu 1 toi %d la:%d",n,T);
return 0;
}
