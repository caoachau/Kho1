#include<stdio.h>
#include<conio.h>

//nhap mang
void nhap(int a[], int &n){
    do{
        printf("Nhap n: ");
        scanf("%d",&n);
        if (n<=0) printf("\nNhap lai n!");
    }
    while(n<2||n>99);
     
    for(int i=0; i<n; i++){
        printf("a[%d]: ",i);
        scanf("%d",&a[i]);
    }
}
 
void xuat(int a[], int n)
{
    for(int i=0;i<n;i++)
	{
        printf("%5d",a[i]);
    }
}
    //tim gia tri max
    
  void Max(int a[], int n)
  {
    int Max, Location;
    Max=0;
    Location =0;
    for(int i=1;i<n;i++)
        if(a[i]>Max)
		{
            Max=a[i];
            Location=i;
        }
        printf("\nGia tri Max: %4d", Max);
       
  }  
  
  //tich cac phan tu
   
  void Tich( int a[], int &n)
  {
  int Tich=1;
  for(int i=0; i<n;i++)
    Tich=Tich*a[i];
  printf("\nGia tri tich: %4d",Tich);

  }
  
  //kiem tra va in so nguyen to
int ktrant(int n){
    if(n<2)
        return 0;
    else
	{
        for(int i=2;i<=n/2;i++)
            if(n%i==0)
                return 0;
        return 1;
    }
}
   //dem SNT
    void DemSNT(int a[], int &n)
   {
   	int x=0;
   	for (int i=0; i<=n;i++)
   	if (ktrant (a[i])) x++;
   	printf("\nMang co bao nhieu so nguyen to: %4d " ,x);
   }
   
  
   //in so nguyen to
void insonguyento(int a[], int n)
{
    printf("\nCac so nguyen to co trong mang la:");
    for(int i=0;i<n;i++)
        if(ktrant(a[i]))
            printf("%4d",a[i]);
        
}
   // tinh tong so nguyen to
   void Sum(int a[], int &n)
   {
   	int Sum=0;
   	for (int i=0; i<=n;i++)
   	if(ktrant(a[i])==1) 
      Sum +=a[i];
   	printf("\nGia tri tong cac so nguyen to: %4d",Sum);
   }
   
   //Nhap vào mot giá tri x, in vi trí các phan tu có giá tri bang x (neu có), nguoc lai xuat thông báo.
      int  TimX(int a[], int n)
    	
   {    
	   int x;
	   int c=0;
        printf("\nNhap x: ");
        scanf("%2d",&x);
        for (int i=0;i<=n;i++)
		{
        
         if(x==a[i]) 
		   {
           printf("\nVi tri la : %4d", i);
           c++;
		   }
         else if(i== n-1 && c==0) 
		 {
		 	printf ("\nKhong co vi tri nao bang x");
		 }         
        }
	}
        
   
   //sap xep mang tang dan
    void Sapxep(int a[], int &n)
    {    
    int w;
    for(int i = 0; i < n - 1; i++)
	{
        for(int j = i + 1; j < n; j++)
		{
            if(a[i] > a[j])
			{
               
                w = a[i];
                a[i] = a[j];
                a[j] = w;    
            }
        }
	}
    printf ("\nMang tang dan tu:");
    xuat(a,n);   
    }
    
    //Chen x
    void ChenX(int a[], int &n )
    {   
         int x,k;
    	printf("\nNhap phan tu can chen X="); scanf("%d",&x);
    		                                         
    	printf("\nNhap vi tri can chen X:");  scanf("%d",&k);
    	if (k>n)
            printf("Phan tu can nhap qua gia tri cua mang");
			else if (k<=n)
			{			
    	 for(int i=n;i>k;i--)
          a[i]=a[i-1];    
          a[k]=x;
          k+1;
        printf("Mang sau khi chen:\n");
        for ( int i = 0; i <=n; i++)
        printf("%4d",a[i]);
            }
    }
   
   // Nhap vào mat giá tri z, xóa các phan tu có giá tri bang z có trong mang
 
          int nhapxoa(int a[], int &n)
        {    
            int z;
        	printf("\nNhap Z="); scanf("%d",z);
        	for(int i=0; i<n; i++)
          {
             if (a[i]==z)
              {
              a[i]=a[i+1];
                n-1;
                printf("Da xoa");
                printf("%d",a[i]);
              }
             else if (a[i] !=z)
             {
			 printf("k co gia tri bang z");
             printf("%d", a[i]);
             }
             
          }
         
		}

      
//ham MAIN
int main()
{
    int a[100];
    int n;
    nhap(a,n);
   
    Max(a,n);
    Tich(a,n);
    TimX(a,n);
    insonguyento(a,n);
    DemSNT(a,n);
    Sum(a,n);   
    Sapxep(a,n);
    ChenX(a,n);
    nhapxoa(a,n);
    
    return 0;
}
