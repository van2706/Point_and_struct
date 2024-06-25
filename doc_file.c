#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *f;
    f = fopen("D:/TU_HOC_LAP_TRINH/HOC_C/point/mofile.txt","r");
    if(f ==NULL){
        printf("error!");
        exit(1);
    }
    int n;
    fscanf(f,"%d",&n);
    printf("gia tri vua doc:%d",n);
}