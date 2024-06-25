#include<stdio.h>
#include<stdlib.h>
struct thoigian{
 int ngay;
 int thang;
 int nam;
};
int main(){
    FILE *f;
    f = fopen("D:/TU_HOC_LAP_TRINH/HOC_C/point/file_bin.bin", "wb");
    if(f ==NULL){
        printf("error !");
        exit(1);
    }
    struct thoigian n1;
    n1.ngay =12;
    n1.thang =05;
    n1.nam = 2023;
    fwrite(&n1,sizeof(struct thoigian),1,f);
    fclose(f);
}