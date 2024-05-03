#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct
{
	char ma[10];
	char hoten[40];
}SinhVien;
void WriteFile(char *Filename)
{
	FILE *f;
	int n,i;
	SinhVien sv;
	f=fopen(Filename,"ab");
	printf("Nhap so luong");scanf("%d",&n);
	fflush(stdin);
	for( i=1;i<=n;i++);
	{
		printf("sv thu %i\n",i);
		printf("mssv:");gets(sv.ma);
		printf("hoten:");gets(sv.hoten);
		fwrite(&sv,sizeof(sv),1,f);
		fflush(stdin);
		
	}
	fclose(f);
	printf("bam phim bat ki de tiep tuc");
	getch();
}

void read( char *Filename)
{
	FILE *f;
	SinhVien sv;
	f=fopen(Filename,"rb");
	printf("mssv|Hovaten\n");
	fread(&sv,sizeof(sv),1,f);
	while(!feof(f))
	{
		printf("&s|%s\n",sv.ma,sv.hoten);
		fread(&sv,sizeof(sv),1,f);
	}
	fclose(f);
	printf("Ba, phim bat ki de tiep tuc");
	getch();
	}

void search(char *Filename)
{
	char mssv[10];
	FILE *f;
	int Found=0;
	SinhVien sv;
	fflush(stdin);
	printf("mssv can tim:");gets(mssv);
	f=fopen(Filename,"rb");
	while(!feof(f) && Found ==0)
	{
		fread(&sv,sizeof(sv),1,f);
		if(strcmp(sv.ma,mssv)==0)
		Found =1;
	}
	fclose(f);
	if(Found==1)
	printf("tim thay sv co ma %s. Ho ten la: %s",sv.ma,sv.hoten);
	else
	printf("k tim thay sv co ma %s",mssv);
	printf("\n Bam phim bat ki de tiep tuc");
	getch();
	
	
}
int main()
{
	int c;
	for(;;)
	{
		printf("1.Nhap dssv\n");
		printf("2.in dssv\n");
		printf("3.Tim sv\n");
		printf("4.thoat");
		printf("Bam chon 1.2.3.4 de tiep tuc");scanf("%d", &c);
		if(c==1) WriteFile("D:\\SinhVien.Dat");
	
		else if(c==2) read("D:\\SinhVien.Dat");
		
		else if(c==3) search("D:\\SinhVien.Dat");
		else break;
		
	}
	return 0;
}


