#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int bac;
    double *heso;
} dathuc;

void nhapDaThuc(dathuc *x) {
    do {
        printf("\nNhap so bac cua da thuc: ");
        scanf("%d", &x->bac);
        if (x->bac < 1)
            printf("\nSo bac cua da thuc khong hop le.\n");
    } while (x->bac < 1);
    
    x->heso = (double *)malloc((x->bac + 1) * sizeof(double));
    
    printf("\nNhap cac he so (a0 -> an):\n");
    for (int i = 0; i <= x->bac; ++i) {
        printf("\nHe so a%d: ", i);
        scanf("%lf", &x->heso[i]);
    }
}

void hienThiDaThuc(dathuc *x) {
    printf("%.2lf", x->heso[0]);
    for (int i = 1; i <= x->bac; ++i) {
        if (x->heso[i] < 0)
            printf(" - %.2lf * x^%d", -x->heso[i], i);
        else
            printf(" + %.2lf * x^%d", x->heso[i], i);
    }
    printf("\n");
}

dathuc* tong2DaThuc(dathuc *x, dathuc *y) {
    int Max = x->bac > y->bac ? x->bac : y->bac;
    int Min = x->bac < y->bac ? x->bac : y->bac;
    dathuc *kq = (dathuc *)malloc(sizeof(dathuc));
    kq->bac = Max;
    kq->heso = (double *)malloc((kq->bac + 1) * sizeof(double));
    
    for (int i = 0; i <= Min; ++i)
        kq->heso[i] = x->heso[i] + y->heso[i];
    
    if (Max == x->bac) {
        for (int i = Min + 1; i <= Max; ++i)
            kq->heso[i] = x->heso[i];
    } else {
        for (int i = Min + 1; i <= Max; ++i)
            kq->heso[i] = y->heso[i];
    }
    
    return kq;
}

dathuc* hieu2DaThuc(dathuc *x, dathuc *y) {
    int Max = x->bac > y->bac ? x->bac : y->bac;
    int Min = x->bac < y->bac ? x->bac : y->bac;
    dathuc *kq = (dathuc *)malloc(sizeof(dathuc));
    kq->bac = Max;
    kq->heso = (double *)malloc((kq->bac + 1) * sizeof(double));
    
    for (int i = 0; i <= Min; ++i)
        kq->heso[i] = x->heso[i] - y->heso[i];
    
    if (Max == x->bac) {
        for (int i = Min + 1; i <= Max; ++i)
            kq->heso[i] = x->heso[i];
    } else {
        for (int i = Min + 1; i <= Max; ++i)
            kq->heso[i] = -y->heso[i];
    }
    
    return kq;
}

void giaiPhongDaThuc(dathuc *x) {
    free(x->heso);
    free(x);
}

int main() {
    dathuc *x = (dathuc *)malloc(sizeof(dathuc));
    printf("\n\t------------ NHAP DA THUC 1 ------------\t\n");
    nhapDaThuc(x);
    hienThiDaThuc(x);
    
    dathuc *y = (dathuc *)malloc(sizeof(dathuc));
    printf("\n\t------------ NHAP DA THUC 2 ------------\t\n");
    nhapDaThuc(y);
    hienThiDaThuc(y);
    
    printf("\n\t----------------------------------------\t\n");
    dathuc *tong = tong2DaThuc(x, y);
    printf("\nTong 2 da thuc tren: ");
    hienThiDaThuc(tong);
    
    dathuc *hieu = hieu2DaThuc(x, y);
    printf("\nHieu 2 da thuc tren: ");
    hienThiDaThuc(hieu);
    
    giaiPhongDaThuc(x);
    giaiPhongDaThuc(y);
    giaiPhongDaThuc(tong);
    giaiPhongDaThuc(hieu);
    
    return 0;
}

