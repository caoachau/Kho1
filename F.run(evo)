#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
int n; // Global variable to store the total number of elements

void taofile(void) {
    FILE *fp;
    fp = fopen("D:\\Bang.txt", "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int x;
    char buffer[256]; // Buffer for user input

    printf("Nhap cac phan tu (bam Enter de ket thuc):\n");
    while (1) {
        printf("Nhap so (Enter de ket thuc): ");
        fgets(buffer, sizeof(buffer), stdin); // Read user input as string
        if (strcmp(buffer, "\n") == 0) // Check if user pressed only Enter
            break;

        x = atoi(buffer); // Convert string to integer
        fprintf(fp, "%6d", x);
        n++; // Increment the count of elements
    }
    fclose(fp);
}

void xuatfile(void) {
    int x;
    FILE *fp;
    fp = fopen("D:\\Bang.txt", "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fscanf(fp, "%d", &x) != EOF) {
        printf("%6d", x);
    }

    fclose(fp);
}

void chia(FILE *a, FILE *b, FILE *c, int p) 
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
			fscanf(a,"%6d",&x);
			fprintf(b,"%6d",x);
			dem++;
			
		}
		// chia phan tu cho c
		dem =0;
		while ((dem <p) && (!feof(a)))
		{
			fscanf(a,"%6d",&x);
			fprintf(c,"%6d",x);
			dem++;
			
		}
	}
	fclose(a);
	fclose(b);
	fclose(c);
}

void tron(FILE *b, FILE *c, FILE *a, int p) 
{
	int stop,x,y,l,r;
	a=fopen("D:\\Bang.txt","wb");
	b=fopen("D:\\Bang1.txt","rb");
	c=fopen("D:\\Bang2.txt","rb");
	while((!feof(b)) && (!feof(c)))
	{
		l=0;
		r=0;
		fscanf(b,"%6d",&x);
		fscanf(c,"%6d",&y);
		stop=0;
		while((l!=p) && (r!=p) && (!stop))
		{
			if (x<y)
			{ 
			 fprintf(a,"%6d",x); 
			 l++;
			 if((l<p) && (!feof(b)))
			 fscanf(b,"%6d",&x);
			 else
			 {
			 	fprintf(a,"%6d",y);
				 r++;
			 	if((feof(b))) stop =1;
			 }
			}
			else
			{
				fprintf(a,"%6d",y);r++;
				if((r<p) && (!feof(c)))
				fscanf(c,"%6d",&y);
				else
				{
					fprintf(a,"%6d",x);l++;
					if((feof(c)))
					stop=1;
				}
			
			}
		}
		while ((!feof(b)) && (l<p))
		{
			fscanf(b,"%6d",&x);
			fprintf(a,"%6d",x);
			l++;
			
		} 
		while ((!feof(c)) && (r<p))
		{
			fscanf(c,"%6d",&y);
			fscanf(a,"%6d",y);
			r++;
			
		}
		
	}
	if (!feof(b))
	{
		while (!feof(b))
		{
			fscanf(b,"%6d",&x);
			fprintf(a,"%6d",x);
			
		}
	}
	if(!feof(c))
    {

        while(!feof(c))
       {
       fscanf(c,"%6d",&x);
       fprintf(a,"%6d",x);
       }
    }
    fclose(a);
    fclose(b);
	fclose(c);

}

int main(void) {
    FILE *a, *b, *c;
    taofile();
    printf("Cac phan tu vua nhap:\n");
    xuatfile();

    int p = 1;
    while (p < n) {
        chia(a, b, c, p);
        tron(b, c, a, p);
        p *= 2;
    }

    printf("\nFile sau khi sap xep:\n");
    xuatfile();

    return 0;
}

