#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char hoten[30];
    int masv;
    float d1, d2, d3;
}Data;

typedef struct tagNode{
    Data infor;
    struct tagNode *link;
}Node;

typedef struct{
    Node *pHead;
    Node *pTail;
    int spt;
}LList;

/////////////////////////////////////
void initList(LList *L){
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}

/////////////////////////////////////
int emptyList(LList L){
    return (L.spt == 0);
}

/////////////////////////////////////
void insert_Head(LList *L, Data x){
    Node *pp;
    pp = (Node*)malloc(sizeof(Node));
    if(pp == NULL){
        printf("Khong du bo nho!\n");
        return;
    }
    pp->infor = x;
    pp->link = NULL;
    if(emptyList(*L)){
        L->pHead = pp;
        L->pTail = pp;
    }
    else{
        pp->link = L->pHead;
        L->pHead = pp;
    }
    L->spt++;
}

/////////////////////////////////////
void insert_Tail(LList *L, Data x){
    Node *pp;
    pp = (Node*)malloc(sizeof(Node));
    if(pp == NULL){
        printf("Khong du bo nho!\n");
        return;
    }
    pp->infor = x;
    pp->link = NULL;
    if(emptyList(*L)){
        L->pHead = pp;
        L->pTail = pp;
    }
    else{
        L->pTail->link = pp;
        L->pTail = pp;
    }
    L->spt++;
}

/////////////////////////////////////
void insert_After(LList *L, int ma, Data x){
    Node *p = L->pHead;
    while(p != NULL && p->infor.masv != ma){
        p = p->link;
    }
    if(p == NULL){
        printf("Khong tim thay sinh vien co ma %d!\n", ma);
        return;
    }
    Node *pp = (Node*)malloc(sizeof(Node));
    if(pp == NULL){
        printf("Khong du bo nho!\n");
        return;
    }
    pp->infor = x;
    pp->link = p->link;
    p->link = pp;
    if(p == L->pTail){
        L->pTail = pp;
    }
    L->spt++;
}

/////////////////////////////////////
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &x->masv);
    if(x->masv > 0){
        getchar();
        printf("Nhap ho ten: ");
        fgets(x->hoten, sizeof(x->hoten), stdin);
        printf("Nhap diem mon 1: ");
        scanf("%f", &x->d1);
        printf("Nhap diem mon 2: ");
        scanf("%f", &x->d2);
        printf("Nhap diem mon 3: ");
        scanf("%f", &x->d3);
    }
}

/////////////////////////////////////
void in(Data x){
    printf("Ten: %s", x.hoten);
    printf("Ma: %d\n", x.masv);
    printf("Diem 1: %.2f\n", x.d1);
    printf("Diem 2: %.2f\n", x.d2);
    printf("Diem 3: %.2f\n", x.d3);
}

/////////////////////////////////////
void processList(LList L){
    Node *pp = L.pHead;
    if(emptyList(L)){
        printf("Danh sach rong!\n");
        return;
    }
    while(pp != NULL){
        in(pp->infor);
        pp = pp->link;
    }
}

/////////////////////////////////////
void freeList(LList *L){
    Node *p = L->pHead;
    while(p != NULL){
        Node *q = p;
        p = p->link;
        free(q);
    }
    initList(L);
}

/////////////////////////////////////
int main(){
    LList L;
    int kt = 0;
    Data x;
    initList(&L);
    do{
        printf("\nChuong trinh lam viec voi DSLK don SV\n");
        printf("\n1: Them nut vao dau danh sach");
        printf("\n2: Them nut vao cuoi danh sach");
        printf("\n3: Them nut vao sau mot nut khac trong danh sach");
        printf("\n9: Duyet ds");
        printf("\n0: Thoat");
        printf("\nMoi ban chon: ");
        int chon;
        scanf("%d", &chon);
        switch(chon){
            case 1:
                printf("Nhap thong tin sinh vien can them:\n");
                nhap(&x);
                if(x.masv > 0){
                    insert_Head(&L, x);
                }
                break;
            case 2:
                printf("Nhap thong tin sinh vien can them:\n");
                nhap(&x);
                if(x.masv > 0){
                    insert_Tail(&L, x);
                }
                break;
            case 3:
                printf("Nhap ma sinh vien can chen sau: ");
                int ma;
                scanf("%d", &ma);
                printf("Nhap thong tin sinh vien can them:\n");
                nhap(&x);
                if(x.masv > 0){
                    insert_After(&L, ma, x);
                }
                break;
            case 9:
                processList(L);
                break;
            case 0:
                printf("Bye bye\n");
                kt = 1;
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    }while(kt == 0);
    freeList(&L);
    return 0;
}

