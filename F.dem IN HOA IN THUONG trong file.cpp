#include<stdio.h>
#include<conio.h>
#include <ctype.h>
#include <string.h> 

void taofile(void)
 {	
    FILE *fp;
    fp = fopen("D:\\count.txt", "w"); // Open file for writing
    if (fp == NULL) {
        printf("Error!!!\n");
        return;
    }
    printf("Nhap noi dung file : ");
    char n[100];
    gets(n); // Read string from user
    fputs(n, fp); // Write string to file
    fclose(fp); // Close file
}
void xuat(void) 
{
    FILE *fp = fopen("D:\\count", "r"); 
    if (fp == NULL) {
        printf("Không th? m? file ð? ð?c.\n");
        return;
    }
    char ch;
    printf("Noi dung file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch); // In t?ng k? t? trong file ra màn h?nh
    }
    fclose(fp); // Ðóng file
}    
void count(void) {
    FILE *fp = fopen("D:\\count.txt", "r"); // Open file for reading
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    int uppercase[26] = {0};
    int lowercase[26] = {0};
    int ch;
    while ((ch = fgetc(fp)) != EOF) 
	{
        if (isalpha(ch)) 
		{ // Ki?m tra xem ký t? có ph?i là ch? cái không
            if (isupper(ch)) 
			{
                uppercase[ch - 'A']++; // Tang s? l?n xu?t hi?n c?a ký t? in hoa tuong ?ng
            } else 
			{
                lowercase[ch - 'a']++; // Tang s? l?n xu?t hi?n c?a ch? thu?ng tuong ?ng
             }
         }
     }
     fclose(fp);

    for (int i = 0; i < 26; ++i)
	 {
        char ch = 'a' + i;
        char chh ='A' +i;
        printf("\n '%c' xuat hien %d lan || '%c' xuat hien %d lan ", ch, lowercase[i],chh,uppercase[i]);    
    }             
}
    
int main(void)
{
    
	taofile();
	xuat(); 
    count();  
    return 0;
}

