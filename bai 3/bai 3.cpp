#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char hoten[50];
    char ma[20];
    float diem1, diem2, diem3;
} SV;
int main(){
    int n;
    printf("Nhap so luong sinh vien: \n");
    scanf("%d", &n);
    if(n <= 0){
        printf("So luong sinh vien khong hop le!");
        return 1;
    }
    SV *ds = (SV *)malloc(n * sizeof(SV));
    if(ds == NULL){
        printf("Khong du bo nho!\n");
        return 1;
    }
    getchar();
    
    //nhap dl
    for(int i = 0; i < n; i++){
        printf("Nhap sinh vien thu %d: \n", i + 1);
        printf("Ho ten: ");
        fgets(ds[i].hoten, sizeof(ds[i].hoten), stdin);
        printf("Ma sinh vien: ");
        scanf("%19s", ds[i].ma);
        printf("Diem 1: ");
        scanf("%f", &ds[i].diem1);
        printf("Diem 2: ");
        scanf("%f", &ds[i].diem2);
        printf("Diem 3: ");
        scanf("%f", &ds[i].diem3);
        getchar();
    }
    
    //in ra
    printf("DANH SACH SINH VIEN:\n");
    for(int i = 0; i < n; i++){
        printf("Sinh vien thu %d:\n", i + 1);
        printf("Ho ten: %s", ds[i].hoten);
        printf("Ma sinh vien: %s\n", ds[i].ma);
        printf("Diem 1: %.2f\n", ds[i].diem1);
        printf("Diem 2: %.2f\n", ds[i].diem2);
        printf("Diem 3: %.2f\n", ds[i].diem3);
    }
    
    //giai phong danh sach
    free(ds);
    return 0;
}

