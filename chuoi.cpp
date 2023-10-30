#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
 void NhapChuanhoa(char s[])
{  
    printf("\n Nhap chuoi:");
    gets(s);
    
}
int xoa(char s[],int vitrixoa)
{
	int n=strlen(s);
    for(int i=vitrixoa;i<n;i++)
     s[i]=s[i+1];
	s[n-1]='\0'; 
}
int  xoakt(char s[50])
{
    for(int i=0;i<strlen(s);i++)
		if(s[i]==' '&& s[i+1]==' ')
		{
			xoa(s,i);
			i--;
		}
    if(s[0]==' ')
		xoa(s,0);
    if(s[strlen(s)-1]==' ')
		xoa(s,strlen(s)-1);
}
int chuanhoa(char s[]) //in hoa ki tu dau
{ int i=0;
	strlwr(s);
	xoakt(s);
	s[0]=s[0]-32;
	for(int i=0;i<strlen(s);i++)
		{ 
		if(s[i]==' '&& s[i+1]!=' ')
		    s[i+1]=s[i+1]-32;
		}
		 printf("\n Chuoi chuan hoa:");	puts(s);
}
 
// dem tu
int demtu(char s[])
{ int demtu=1;
	strlwr(s);
	for(int i=0;i<strlen(s);i++)
		{ 
		if(s[i]==' ')
		     demtu++;
		}
		printf("\n so tu %d",demtu);
}
//dem ki tu
int demkt(char s[])
{ int demkytu=0;
  char c,c1;
	printf("\n Nhap mot ky tu:= ");
	scanf("%c",&c);
	//fflush(stdin);// xoa bo nho tam ban phim
  	strupr(s);
    for(int i=0;i<strlen(s);i++)
		{ 
		if(s[i]==toupper(c))
		     demkytu++;
		}
		printf("\n So ky tu %d",demkytu);
}

//ghep chuoi
int Ghepchuoi(char s[],char  s2[])
{  
fflush(stdin);
   printf("\n Nhap chuoi S2:");
    gets(s2); 
    chuanhoa(s2);
    int i,j,n1,n2;
    
     n1 = strlen(s);
   n2 = strlen(s2);
     
   j=0;
   for(i = n1; i<n1+n2; i++ ) {
      s[i] = s2[j];
      j++;
   }
     
   s[i] = '\0';
    
   printf("\nKet qua sau khi noi chuoi la:\n");
   chuanhoa(s);
   printf("%s", s);
 
}


 //Ham main
 int main()
 {    
    char s[100];
    char s2[100];
    char s3[100];
 	NhapChuanhoa(s);
 	chuanhoa(s);
 	demtu(s);
 	demkt(s);
 	Ghepchuoi(s,s2);
 	
 	return 0;
 }
