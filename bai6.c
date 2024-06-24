#include<stdio.h>
#include<stdlib.h>
int main(){
    // cap phat bo nho dong
    int n;
    printf("nhap so luong doi tuong: ");
    scanf("%d",&n);
    //int *pt = (int *)malloc(n*sizeof(int));
    int *pt =(int*)calloc(n,sizeof(int));
    for(int i =0;i<n;i++){
           printf("\na[%d] = ",i);
           scanf("%d",pt+i);

    }
    printf("\nphan tu cua mang:");
    for(int i =0; i<n;i++){
        printf(" %d",*(pt+i));
    }
    int x;
    printf("\nnhap kich thuoc thay doi:");
    scanf("%d",&x);
    realloc(pt, x);
        printf("\nphan tu cua mang:");
    for(int i =0; i<x;i++){
        printf(" %d",*(pt+i));
    }
    free(pt);
}