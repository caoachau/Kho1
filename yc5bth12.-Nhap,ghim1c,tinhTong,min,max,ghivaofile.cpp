#include <stdio.h>
#include <stdlib.h>

void writeToFile(int arr[], int n, char *filePath) {
    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        printf("Ko the mo file.\n");
        exit(1);
    }


    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

void readFromFile(char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        exit(1);
    }

    int num;
    printf("\n Noi dung file:\n");
    while (fscanf(file, "%d", &num) == 1) {
        printf("%d ", num);
    }

    fclose(file);
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int calculateSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;

  
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

   
    printf("Nhap %d so nguyen duong:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

  
    char filePath[100];
    printf("Nhap duong dan file: ");
    scanf("%s", filePath);

   
    writeToFile(arr, n, filePath);

  
    int sum = calculateSum(arr, n);
    int max = findMax(arr, n);
    int min = findMin(arr, n);

    
    FILE *resultFile = fopen(filePath, "a");
    if (resultFile == NULL) {
        printf("Khong the mo file.\n");
        exit(1);
    }
    fprintf(resultFile, "\nTong: %d\n", sum);
    fprintf(resultFile, "Max: %d\n", max);
    fprintf(resultFile, "Min: %d\n", min);
    fclose(resultFile);
  
    readFromFile(filePath);

    return 0;
}

