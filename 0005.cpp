#include<stdio.h>
#include<conio.h>

int p,n;

void taofile(void)
{
	int i,x;
	FILE *fp;
	fp=fopen("D:\\Bang.txt","wb");
	printf("so luong:"
	scanf("%d",&n);
	for (i=0;i<=n;i++)
	{
		printf(" Nhap so thu %d", i+1);
		scanf("%d",&x);
		fprintf(fp,"%d",x);
	}
	fclose(f);
	
}

void xuatfile(void)
{
	int x;
	FILE *fp;
	fp=fopen("D:\\Bang.txt","rb");
	int i=0;
	while(i<n)
	{
		fscanf(fp,"%d",&x);
		printf("%d",x);
		i++;
	}
	fclose(f);
	
}
void chia(FILE *a,FILE *b,FILE *c,int p)
{
	int dem,x;
	a=fopen("D:\\Bang.txt","rb");
	b=fopen("D:\\Bang1.txt","wb");
	c=fopen("D:\\Bang2.txt","wb");
	while(!feof(a))
	{
		dem=0;
		while((dem<p) && (!feof(a)))
		{
			fscanf(a,"%d",&x)
			fprintf(b,"%d",x)
			dem++;
			
		}
		dem =0;
		while ((dem <p) && (!feof(a)))
		{
			fscanf(a,"%d",&x);
			fprintf(c,"%d",x)
			dem++;
			
		}
	}
	fclose(a);
		fclose(b);
			fclose(c);
}

void tron(FILE *b,FILE *c, FIlE *a, int p)
{
	int stop,x,y,l,r;
	a=fopen("D:\\Bang.txt","wb");
	b=fopen("D:\\Bang1.txt","rb");
	c=fopen("D:\\Bang2.txt","rb");
	while((!feof(b)) && (!feof(c)))
	{
		l=0;
		r=0;
		fscanf(b,"%d",&x);
		fscanf(c,"%d",&y);
		stop=0;
		while((l!=p) && (r!=p) && (!stop))
		{
			if (x<y)
			{ 
			 fprintf(a,"%d",x); l++;
			 if((l<p) && (!feof(b)))
			 fscanf(b,"%d",&x)
			 else
			 {
			 	fprintf(a,"%d",y);r++;
			 	if((feof(b))) stop =1;
			 }
			}
			else
			{
				printf(a,"%d",y);r++;
				if((r<p) && (!feof(c)))
				fscanf(c,"%d",&y);
				else
				{
					fprintf(a,"%d",x);l++;
					if((feof(c)))
					stop=1;
				}
			
			}
		}
		............................
	}
}
