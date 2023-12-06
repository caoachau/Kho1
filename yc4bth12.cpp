#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	char MaSV[10]; char HovaTen[40];
} 
Sinhvien;
//.............................................
void Nhap(char *filename);
void xuat(char *filename);
void tim(char *filename);
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
case 1:
fflush(stdin);
Nhap("Sinhvien.txt");
printf("\nBam phim bat ky de tiep tuc!");
                getch();
	break;


           

//.....................
case 2:
fflush(stdin);
xuat("Sinhvien.txt");
 printf("\nBam phim bat ky de tiep tuc!");
                getch();
	break;
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

 void Nhap(char *filename)
 {
 
 FILE *f;
 int n,i;
 Sinhvien sv;
 f=fopen(filename,"ab");
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
 }
//....................................
void Xuat(char *filename)
 {
 FILE *f;
 Sinhvien sv;
 f=fopen(filename,"rb");
 printf("MSSV SV | Ho va Ten\n"); fread(&sv,sizeof(sv),1,f);
 while(!feof(f))
 {printf("%s | %s\n",sv.MaSV,sv.HovaTen);
  fread(&sv,sizeof(sv),1,f);
 }  
 fclose(f);
 }
//..........................................
void tim(char *filename)
{
	char MSSV[10];
	FILE *f;
	int Found=0;
	Sinhvien sv;
	fflush(stdin);
	printf("Ma so sinh vien can tim:"); gets(MSSV);
	f=fopen(filename,"rb");
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
}


