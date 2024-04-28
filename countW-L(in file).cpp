#include<stdio.h>
#include<string.h>

#define MAX_LINE_LENGTH 1000

void read(char *Filename)
{
    FILE *f;
    printf("Nhap dia chi file: ");
    scanf("%s", Filename);
    f = fopen(Filename, "r");
    if (f == NULL)
    {
        printf("Khong the mo file.\n");
        return;
    }
    fclose(f);
}

void count(char *Filename, int *wordCount, int *lineCount)
{
    FILE *f;
    char line[MAX_LINE_LENGTH];
    *wordCount = 0;
    *lineCount = 0;
    f = fopen(Filename, "r");
    if (f == NULL)
    {
        printf("Khong the mo file.\n");
        return;
    }
    while (fgets(line, MAX_LINE_LENGTH, f) != NULL)
    {
        char *token = strtok(line, " \t\n"); // Tach tu trong dong
        while (token != NULL)
        {
            (*wordCount)++;
            token = strtok(NULL, " \t\n");
        }
        (*lineCount)++;
    }
    fclose(f);
}

int main()
{
    char Filename[100];
    int wordCount = 0;
    int lineCount = 0;
    read(Filename);
    count(Filename, &wordCount, &lineCount);
    printf("So tu: %d\n", wordCount);
    printf("So dong: %d\n", lineCount);
    return 0;
}

