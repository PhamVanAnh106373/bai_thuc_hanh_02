#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    
    float *ma = (float *)malloc(n * sizeof(float));
    if (ma == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }

    //nhap dl
    printf("Nhap mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &ma[i]);
    }

    //in ra
    printf("Mang vua tao:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%.2f ", ma[i]);
    }

    //giai phong ma tran
    for (int i = 0; i < n; i++) {
        free(ma);
    }
    free(ma);

    return 0;
}
