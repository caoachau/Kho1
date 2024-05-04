#include <stdio.h>
#include <stdlib.h>
#include <ctime>


void CreateFile(FILE *Ft, int);
void ListFile(FILE *);
void Distribute();
void Copy(FILE *, FILE *);
void CoyRun(FILE *, FILE *);
void MergeRun();
void Merge();

typedef int DataType;
FILE *F0, *F1, *F2;
int M, N, Eor;
DataType X1, X2, X, Y;

void CreateFile(FILE *Ft, int Num) {
    // T?o file có ng?u nhiên n ph?n t?
    Ft = fopen("D:\\Bang.txt", "wb");
    if (Ft == NULL) {
        printf("Khong the mo file.");
        return;
    }

    for (int i = 0; i < Num; i++) {
        X = rand() % 30;
        fprintf(Ft, "%3d", X);
    }
    fclose(Ft);
}

void ListFile(FILE *Ft) {
    // Hi?n th? n?i dung c?a file lên màn hình
    DataType X, I = 0;
    Ft = fopen("D:\\Bang.txt", "rb");
    if (Ft == NULL) {
        printf("Khong the mo file.");
        return;
    }

    while (I < N) {
        fscanf(Ft, "%3d", &X);
        printf("%d ", X);
        I++;
    }
    printf("\n\n");
    fclose(Ft);
}

void Copy(FILE *Fi, FILE *Fj) {
    // Ð?c ph?n t? X t? t?p tin Fi, ghi X vào Fj
    // Eor == 1, N?u h?t Run (trên Fi) ho?c h?t File Fj
    fscanf(Fi, "%3d", &X);
    fprintf(Fj, "%3d", X);
    if (!feof(Fi)) {
        fscanf(Fi, "%3d", &Y);
        long curpos = ftell(Fi) - 2;
        fseek(Fi, curpos, SEEK_SET);
    }
    if (feof(Fi))
        Eor = 1;
    else
        Eor = (X > Y) ? 1 : 0;
}

void CopyRun(FILE *Fi, FILE *Fj) {
    // Sao chép 1 Run t? File Fi vào File Fj
    do {
        Copy(Fi, Fj);
    } while (!Eor);
}

void Distribute() {
    // Phân b? l?n lu?t các Run ng?u nhiên t? F0 vào F1 và F2
    do {
        CopyRun(F0, F1);
        if (!feof(F0))
            CopyRun(F0, F2);
    } while (!feof(F0));
    fclose(F0);
    fclose(F1);
    fclose(F2);
}

void MergeRun() {
    // Tr?n các Run t? F1 và F2 vào F0
    do {
        fscanf(F1, "%3d", &X1);
        long curpos = ftell(F1) - 2;
        fseek(F1, curpos, SEEK_SET);
        fscanf(F2, "%3d", &X2);
        curpos = ftell(F2) - 2;
        fseek(F2, curpos, SEEK_SET);
        if (X1 <= X2) {
            Copy(F1, F0);
            if (Eor)
                CopyRun(F2, F0);
        } else {
            Copy(F2, F0);
            if (Eor)
                CopyRun(F1, F0);
        }
    } while (!Eor);
}

void Merge() {
    // Tr?n các Run t? F1 và F2 vào F0
    while ((!feof(F1)) && (!feof(F2))) {
        MergeRun();
        M++;
    }
    while (!feof(F1)) {
        CopyRun(F1, F0);
        M++;
    }
    while (!feof(F2)) {
        CopyRun(F2, F0);
        M++;
    }
    fclose(F0);
    fclose(F1);
    fclose(F2);
}

int main() {
    printf("Nhap so phan tu : ");
    scanf("%d", &N);
    srand(time(NULL));
    CreateFile(F0, N);
    ListFile(F0);
    do {
        F0 = fopen("D:\\Bang.txt", "rb");
        F1 = fopen("D:\\Bang1.txt", "wb");
        F2 = fopen("D:\\Bang2.txt", "wb");
        Distribute();
        F0 = fopen("D:\\Bang.txt", "wb");
        F1 = fopen("D:\\Bang1.txt", "rb");
        F2 = fopen("D:\\Bang2.txt", "rb");
        M = 0;
        Merge();
    } while (M != 1);
    ListFile(F0);
    return 0;
}

