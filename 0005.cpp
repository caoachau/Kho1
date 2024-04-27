#include<stdio.h>
#include<conio.h>

int p,n;

void taofile(void)
{
	int i,x;
	FILE *fp;
	fp=fopen("D:\\Bang.txt","wb");
	printf("so luong:");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf(" Nhap so thu %d: ", i+1);
		scanf("%d",&x);
		fprintf(fp,"%3d",x);
	}
	fclose(fp);
	
}
//.................................................
void xuatfile(void)
{
	int x;
	FILE *fp;
	fp=fopen("D:\\Bang.txt","rb");
	int i=0;
	while(i<n)
	{
		fscanf(fp,"%d",&x);
		printf("%3d",x);
		i++;
	}
	fclose(fp);
	
}
//...............................
void chia(FILE *a,FILE *b,FILE *c,int p)
{
	int dem,x;
	a=fopen("D:\\Bang.txt","rb");
	b=fopen("D:\\Bang1.txt","wb");
	c=fopen("D:\\Bang2.txt","wb");
	while(!feof(a))
	{    
	     // chia phan tu cho b
		dem=0;
		while((dem<p) && (!feof(a)))
		{
			fscanf(a,"%3d",&x);
			fprintf(b,"%3d",x);
			dem++;
			
		}
		// chia phan tu cho c
		dem =0;
		while ((dem <p) && (!feof(a)))
		{
			fscanf(a,"%3d",&x);
			fprintf(c,"%3d",x);
			dem++;
			
		}
	}
	fclose(a);
	fclose(b);
	fclose(c);
}

void tron(FILE *b,FILE *c, FILE *a, int p)
{
	int stop,x,y,l,r;
	a=fopen("D:\\Bang.txt","wb");
	b=fopen("D:\\Bang1.txt","rb");
	c=fopen("D:\\Bang2.txt","rb");
	while((!feof(b)) && (!feof(c)))
	{
		l=0;
		r=0;
		fscanf(b,"%3d",&x);
		fscanf(c,"%3d",&y);
		stop=0;
		while((l!=p) && (r!=p) && (!stop))
		{
			if (x<y)
			{ 
			 fprintf(a,"%3d",x); 
			 l++;
			 if((l<p) && (!feof(b)))
			 fscanf(b,"%3d",&x);
			 else
			 {
			 	fprintf(a,"%3d",y);
				 r++;
			 	if((feof(b))) stop =1;
			 }
			}
			else
			{
				fprintf(a,"%3d",y);r++;
				if((r<p) && (!feof(c)))
				fscanf(c,"%3d",&y);
				else
				{
					fprintf(a,"%3d",x);l++;
					if((feof(c)))
					stop=1;
				}
			
			}
		}
		while ((!feof(b)) && (l<p))
		{
			fscanf(b,"%3d",&x);
			fprintf(a,"%3d",x);
			l++;
			
		} 
		while ((!feof(c)) && (r<p))
		{
			fscanf(c,"%3d",&y);
			fscanf(a,"%3d",y);
			r++;
			
		}
		
	}
	if (!feof(b))
	{
		while (!feof(b))
		{
			fscanf(b,"%3d",&x);
			fprintf(a,"%3d",x);
			
		}
	}
	if(!feof(c))
    {

        while(!feof(c))
       {
       fscanf(c,"%3d",&x);
       fprintf(a,"%3d",x);
       }
    }
    fclose(a);
    fclose(b);
	fclose(c);

}

int main(void)
{
	FILE *a,*b,*c;
	taofile();
	printf("phan tu vua nhap:");
	xuatfile();
	p=1;
	while(p<n)
	{
		chia(a,b,c,p);
		tron(b,c,a,p);
		p=2*p;
		
	}
	printf("\n");
	printf("file sau khi run: ");
	xuatfile();
	getch; 	
}
