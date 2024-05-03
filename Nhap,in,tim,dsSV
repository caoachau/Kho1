#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
typedef struct
{
	char MaSV[10]; char HovaTen[40];
} 
Sinhvien;
//.............................................
void Nhap(char *Filename);
void Xuat(char *Filename);
void tim(char *Filename);
//...............................................

int main()
{ int key;
while(true)
	{
        system("cls");
        printf("*************************************************\n");
        printf("**           THAO TAC TREN CHUOI               **\n");
        printf("**         1. Nhap sinh vien                   **\n");
        printf("**         2.In danh sach sinh vien            **\n");
        printf("**         3.Tim kiem                          **\n");
        printf("**         0. Thoat                            **\n");
        printf("*************************************************\n");
       fflush(stdin);
	    printf("\n   \t\t    AN PHIM CHON: ");
        scanf("%d",&key);
        switch(key)  
        	{
case 1:{
		fflush(stdin);
		Nhap("Sinhvien.txt");
		printf("\nBam phim bat ky de tiep tuc!");
        getch();
		break;
}
//.....................
case 2:
	{
		fflush(stdin);
		Xuat("Sinhvien.txt");
 		printf("\nBam phim bat ky de tiep tuc!");
        getch();
	break;
		
	}

//........................
case 3:
fflush(stdin);
tim("Sinhvien.txt");
 printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
                
case 0:
                exit(1);
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;

}}}

 void Nhap(char *Filename)
 {
 
 FILE *f;
 int n,i;
 Sinhvien sv;
 f=fopen(Filename,"ab");
 printf("So luong SV:"); scanf("%d",&n);
 for (int i=0;i<n;i++)
 {
 	printf("SV thu %i\n",i);
 	fflush(stdin);
 	printf("MasoSV:");gets(sv.MaSV);
 	printf("HovaTen:");gets(sv.HovaTen);
 	fwrite(&sv,sizeof(sv),1,f);
 }
 fclose(f);
 printf("an phim bat ki de tiep tuc!\n");
	getch();
 }
//....................................
void Xuat(char *Filename)
 {
 FILE *f;
 Sinhvien sv;
 f=fopen(Filename,"rb");
 printf("MSSV SV | Ho va Ten\n"); fread(&sv,sizeof(sv),1,f);
 while(!feof(f))
 {printf("%s | %s\n",sv.MaSV,sv.HovaTen);
  fread(&sv,sizeof(sv),1,f);
 }  
 fclose(f);
 printf("an phim bat ki de tiep tuc!\n");
	getch();
 }
//..........................................
void tim(char *Filename)
{
	char MSSV[10];
	FILE *f;
	int Found=0;
	Sinhvien sv;
	fflush(stdin);
	printf("Ma so sinh vien can tim:"); gets(MSSV);
	f=fopen(Filename,"rb");
	while (!feof(f) && Found ==0)
	{
	fread(&sv,sizeof(sv),1,f);
	if(strcmp(sv.MaSV,MSSV)==0) Found=1;
	}
	fclose(f);
	if (Found=1)
	{
		printf("Tim thay sv co ma %s. Ho Ten la:%s", sv.MaSV,sv.HovaTen);
		
	}
	else
	{
		printf("Khong tim ra sv co ma %s", MSSV);
	}
	printf("an phim bat ki de tiep tuc!\n");
	getch();
}


