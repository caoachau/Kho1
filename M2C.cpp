#include <stdio.h>
#include <conio.h>
#include <math.h>
//Nhap mang 2C
void Nhap( int a[][100], int &n, int &m)
{
	printf ("Nhap so cot:"); scanf("%d",&n);
	printf ("Nhap so hang:"); scanf("%d",&m);
	  if( n<0 && m<0 ) printf ("Nhap lai");
	  
	for( int i=0; i<n;i++)
	  {
	  	for (int j=0; j<m; j++)
	  	{ 
	  	  printf("A[%d][%d]=", i,j);	  	  
	  	  scanf("%d", &a[i][j]);
	  	  
	  	}
	  }
}
//Xuat mang 2C
void Xuat( int a[][100], int &n, int &m)
{

	  for( int i=0; i<n;i++)
	  {
	  	for (int j=0; j<m; j++)
	  	{ 
	  	printf("%4d", a[i][j]);
	  
	  }
	  printf("\n");
	  }
}

//TIm max
void Max( int a[][100], int &n, int &m)
{      
      int Max;
      Max =a[0][0];
    for( int i=0; i<n;i++)
	  {
	  	for (int j=0; j<m; j++)
	  	{ 
	  	  if (a[i][j] > Max)
	  	    Max= a[i][j];
	  	}
	  }
printf("\nGia tri max tren cot 1 cua mang la %5d",Max);
}
// Tim min
void Min( int a[][100], int &n, int &m)
{      
      int Min;
      Min=a[0][0];
    for( int i=0; i<n;i++)
	  {
	  	for (int j=0; j<m; j++)
	  	{ 
	  	  if (a[i][j] < Min)
	  	    Min= a[i][j];
	  	}
	  }
printf("\nGia tri min tren cot 1 cua mang la %5d",Min);
}
//Dem SNT , tinh tong cac ptu tren ma tran
     
        // kiem tra SNT
                bool KT( int a)
                {
                	if (a<2) return false;
                	 for(int i = 2; i <= a/2;i++)
					 {
                      if(a % i == 0) return false;
                	return true;
                }}
        //Dem SNT
		 void Dem( int a[][100], int &n, int &m)
              {      
               int x=0;
             for( int i=0; i<n;i++)
	           {
	  	         for (int j=0; j<m; j++)
	  	          { 
	  	            if(KT(a[i][j])) x++;
	  	            
	  	        }
				  }
				  printf("\nSo luong SNT trong mang: %4d",x);
			   }
	  	//In SNT
	  	void insonguyento(int a[][100], int &n,int &m)
               {
                   printf("\nCac so nguyen to co trong mang la:");
                    for(int i=0;i<n;i++)
                     for (int j=0;j<m;j++)                      
                      if(KT(a[i][j]))
                      printf("%4d",a[i][j]);
                  }
       //Tinh Tong
	   	      void Sum( int a[][100], int &n, int &m)
	   	      {
	   	      	int Sum=0;
	   	      	 for( int i=0; i<n;i++)
	               {
	  	             for (int j=0; j<m; j++)
	  	               { 
	  	                 if(KT(a[i][j])==1) Sum=Sum +a[i][j];
	  	                
	  	             }}
	  	             printf("\nGia tri tong cac so nguyen to: %4d",Sum);
	   	  }
//Sap xep Tang Giam 
      //SX mang 1 chieu
      int Sapxep(int a[], int &n)
    {    
    int i,j; int w;
    for(int i = 0; i < n - 1; i++)
	{
        for(int j = i + 1; j < n; j++)
		{
            if(a[i] > a[j])
			{
                // Hoan vi 2 so a[i] va a[j]
                w = a[i];
                a[i] = a[j];
                a[j] = w;    
            }
        }
	}
   }
      //SX mang 2 chieu
          int Sx( int a[][100], int &n, int &m)
          {
          
          int i; int b[n*m];
          
           for(i=0;i<n*m;i++)
		   {
           b[i] = a[i/m][i%m];
           }
           
            Sapxep(b,n*m);
            
            for(i=0;i<n*m;i++)
			{
             a[i/m][i%m] = b[i];
            }
            
            Xuat(a,n,m);
         }
 
//Nhap gia tri x , tim va in ra vi tri cua x trong mang


// Ham 9
int main()
{
	int a[100][100];
	int m; int n;
	Nhap(a,n,m);
	Xuat(a,n,m);
	Max(a,n,m);
	Min(a,n,m);
	Dem(a,n,m);
	insonguyento(a,n,m);
	Sum(a,n,m);
	Sx(a,n,m);
	return 0;
}
	

