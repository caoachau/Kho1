#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	FILE * fp;
	char filename[67], ch;
	printf("Duong dan:");
	gets(filename);
	if ((fp=fopen (filename, "r")) ==NULL)
	{printf("Sai\n");
	exit(1);
	}
	while ((ch= getc(fp) ) != EOF)
          printf("%c",ch);
	fclose(fp);
	return 0;
	
}

