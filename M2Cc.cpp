#include <stdio.h>
#include <conio.h>
#include <math.h>
//1./2.Nhap mang 2C
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
//3.Xuat mang 2C
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

//4.TIm max
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
//4.Tim min
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
//5.Dem SNT , tinh tong cac ptu tren ma tran
     
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
	  	             printf("\nGia tri tong cac so nguyen to: %4d\n",Sum);
	   	  }
	   	  
//6.Nhap gia tri x , tim va in ra vi tri cua x trong mang
  void Timx( int a[][100], int &n, int &m)
{    
	   int x;
	   
        printf("\nNhap x: ");
        scanf("%2d",&x);
        for (int i=0;i<=n;i++)
		{
	     for (int j=0;j<=i;j++)
	     {   
		   if(a[i][j]==x)  printf("\nVi tri co gia tri bang x : a[%d][%d]\n",i,j);
		}
	}
}
	    
        


//7.yeN ngua
void Yenngua(int a[][100],int x, int y){
	int i,j,pos = 0,min = a[0][0];
	int c=x;
	for(i = 0; i < x;i++){
			for(j = 0;j<y; j++){
				if(min > a[i][j]){
						min = a[i][j];
						pos = j;
						}
					int k;
					if( j == y-1){
						for(k = i; k<x; k++){
						if(min < a[k][pos]){
							if(k == x-1){
							if(k == c) continue;
							printf("\ndiem yen ngua %d", a[k][pos]);
							c=k;
									}
						}
					}
		
				}
		
		}}}
			
			
				 	

//8Sap xep Tang Giam
 
      //SX mang 1 chieu
      void Sapxep(int a[], int n)
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
          void Sx( int a[][100], int n, int m)
          {
          
          int i; int b[n*m];
          
           for(i=0;i<n*m;i++)
		   {
           b[i] = a[i/m][i%m];
           }
           
            Sapxep(b, n*m);
            
            for(i=0;i<n*m;i++)
			{
             a[i/m][i%m] = b[i];
            }
            printf("\n%d----Mang sau khi sap xep----\n");
            Xuat(a,n,m);
         }
 //9. tinh tong cac ptu tren duong cheo 9
  void Tongcheochinh(int a[][100], int n, int m)
    {
    	 int Tong=0;
	for(int i = 0; i < n ; i++)
	  {
        for(int j = 0; j < m; j++)
		  { 
		    if (i==j) Tong=Tong +a[i][j];
		  }
	  }
    	printf("Tong duong cheo chinh%4d\n",Tong);
    	
    }
    
//10.Ðem xem có bao nhiêu so chan nam trong tam giác trên cua duong chéo chính
      void Demsochan(int a[][100],int n,int m)
{            int demsochan=0; 
               for( int i=0; i<n;i++)
	               {
	  	             for (int j=0; j<i; j++)
	  	               {  
	  	                  if (a[i][j] %2==0)
	  	                     demsochan++;
	  	                  
	  	                  
	  	                 }}
	  	               
	             printf("so chan%4d\n", demsochan);
	            for( int i=0; i<n;i++)
	               {
	  	             for (int j=0; j<i; j++)
	  	               { 
						 printf("%d\n",a[i][j]);
					   }
				   }
}




//bai tren con sai


//11. Tìm và in ra các so le n?m trong tam giác duoi c?a duong chéo phu
        //(tính luon duong cheo phu)
        

//12.Nhap vào hai ma tran A, B có m dòng, n cot. Tính tong, tích hai ma tran


//ma tran b  

void NhapMTB( int b[][100], int &n, int &m)
{
	printf ("Nhap so cot B:"); scanf("%d",&n);
	printf ("Nhap so hangB:"); scanf("%d",&m);
	  if( n<0 && m<0 ) printf ("Nhap lai");
	  
	for( int i=0; i<n;i++)
	  {
	  	for (int j=0; j<m; j++)
	  	{ 
	  	  printf("b[%d][%d]=", i,j);	  	  
	  	  scanf("%d", &b[i][j]);
	  	  
	  	}
	  }
}
//Xuat mang 2C
void XuatMTB( int b[][100], int &n, int &m)
{

	  for( int i=0; i<n;i++)
	  {
	  	for (int j=0; j<m; j++)
	  	{ 
	  	printf("%4d", b[i][j]);
	  
	  }
	  printf("\n");
	  }
}

//ma tran c

void NhapMTC( int c[][100], int &n, int &m)
{
	printf ("Nhap so cot C:"); scanf("%d",&n);
	printf ("Nhap so hang C:"); scanf("%d",&m);
	  if( n<0 && m<0 ) printf ("Nhap lai");
	  
	for( int i=0; i<n;i++)
	  {
	  	for (int j=0; j<m; j++)
	  	{ 
	  	  printf("c[%d][%d]=", i,j);	  	  
	  	  scanf("%d", &c[i][j]);
	  	  
	  	}
	  }
}
//Xuat mang 2C
void XuatMTC( int c[][100], int &n, int &m)
{

	  for( int i=0; i<n;i++)
	  {
	  	for (int j=0; j<m; j++)
	  	{ 
	  	printf("%4d", c[i][j]);
	  
	  }
	  printf("\n");
	  }
}

//tich 2 mt B*C
void tichMaTran(int b[][100], int c[][100], int t[][100], int n, int m)
{
     for(int i=0;i<n;i++) 
     {     
        for(int j=0;j<m;j++)
		 {
           t[i][j]= b[i][j]*c[i][j];
         }
     }
     printf("\n Tich 2 Ma tran:\n");
    for(int i=0;i<m;i++)
    {    
        for(int j=0;j<n;j++)
        {
            printf("%5d",t[i][j]);
        }
        printf("\n");
    }
}


// Ham 9
int main()
{
	int a[100][100];
	int b[100][100];
	int c[100][100];
	int t[100][100];
	int m; int n;
	Nhap(a,n,m);
	Xuat(a,n,m);
	Max(a,n,m);
	Min(a,n,m);
	Dem(a,n,m);
	insonguyento(a,n,m);
	Sum(a,n,m);
	Sx(a,n,m);
	Yenngua(a,n,m);
	Timx(a,n,m);
	Tongcheochinh(a,n,m);
	Demsochan(a,n,m);
	NhapMTB(b,n,m);
	XuatMTB(b,n,m);
    NhapMTC(c,n,m);
	XuatMTC(c,n,m);
	tichMaTran(b,c,t,n,m);
	
	 
	return 0;
}
	

