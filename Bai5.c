#include<stdio.h>
struct sinhvien{
    char hoten[50];
    int tuoi;
    float cao;
    char gioitinh[20];
};
//typedef sinhvien SV;
int main(){
    struct sinhvien van ={"tongdinhvan",22 ,1.72 ,"nam"};
    struct sinhvien toan={"dinhthanhtoan",23,1.62,"nam"};
    struct sinhvien anh = {"kieuanh", 18, 1.58, "nu"};
    struct sinhvien Bachkhoa[3]={van, toan,anh };
    for (int i =0; i<3;i++){
        printf("tuoi %s: %d \n",Bachkhoa[i].hoten,Bachkhoa[i].tuoi);
    }
    struct sinhvien *nguoi;
    for(nguoi = Bachkhoa; nguoi < Bachkhoa+3;nguoi++){
        printf("tuoi %s :%d \n",nguoi->hoten,nguoi->tuoi );
    }
    return 0;
}