#include<stdio.h>
#include<stdlib.h>

int main(){
    // mo file
    FILE *f;
    f = fopen("D:/TU_HOC_LAP_TRINH/HOC_C/point/mofile.txt","w");
    if(f ==NULL){
        printf("file khong mo duoc can thong tin");
        exit(1);
    }
    int n;
    printf("/n dien thong tin can ghi vao file :");
    scanf("%d",&n);
    fprintf(f,"%d",n);
    fclose(f);
}