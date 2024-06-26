#include<stdio.h>
#include<stdlib.h>
void nhap_mang(int *n, int a[]){
    do{
    printf(" nhap so luong phan tu: ");
    *n =3;
    }
    while(*n <0);
    printf("nhap cac phan tu");
    for(int i=0 ;i<3;i++){
        printf("x[%d] =",i);
        scanf("%d",&a[i]);
    }
}
void xuat_mang(int n, int a[]){
    printf("\ncac gia tri cua mang: ");
    for(int i=0 ;i<n;i++){
        printf("x[%d] =%d",i,a[i]);
    }
}
int main(){
    int n;
    int a[100];
nhap_mang(&n,a);
xuat_mang(n,a);

}