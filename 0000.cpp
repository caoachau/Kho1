#include<stdio.h>
#include<conio.h>
 int main()
 {
 	FILE *f;
 	f=fopen("D:\\Baihat.txt", "r+");
 	if (f!=NULL)
 	{
 	fputs("Em oi Ha Noi pho\n",f);
 	fputs("Ta con em, mui hoa lan, ta con em, mui hoa sua",f);
 	fclose(f);
 }
 
 return 0;
 
 }
