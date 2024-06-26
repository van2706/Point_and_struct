#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct date{
    int ngay;
    int thang;
    int nam;
};
struct sinhvien{
    char id[20];
    char hoten[50];
    char gioitinh[20];
    struct date ngaysinh;
    int tuoi;
    float monhoc1;
    float monhoc2;
    float monhoc3;
    float tb_diem;
    char hocluc[20];

};

typedef struct sinhvien  SV;

void xoa_xuong_dong(char a[]);
void nhap1sinhvien(SV *n1);
void tuoi(SV *sv);
void diemtrungbinh(SV *sv);
void in1sinhvien(SV sv);
void hocluc(SV *sv);

void xoa_xuong_dong(char a[]){
	int len = strlen(a);
	if(a[len-1]=='\n'){
		a[len-1]='\0';
	}
}

void nhap1sinhvien(SV *n1){
    printf("Nhap id: "); fflush(stdin); fgets(n1->id,sizeof(n1->id),stdin);xoa_xuong_dong(n1->id);
    printf("Nhap ho ten: "); fflush(stdin);fgets(n1->hoten,sizeof(n1->hoten),stdin);xoa_xuong_dong(n1->hoten);
    printf("Nhap gio tinh: "); fflush(stdin);fgets(n1->gioitinh,sizeof(n1->gioitinh),stdin);xoa_xuong_dong(n1->gioitinh);
    printf("Nhap ngay sinh: ") ;scanf("%d%d%d",&n1->ngaysinh.ngay,&n1->ngaysinh.thang,&n1->ngaysinh.nam);
    printf("Nhap diem mon 1: "); scanf("%f", &n1->monhoc1);
    printf("Nhap diem mon 2: "); scanf("%f", &n1->monhoc2);
    printf("Nhap diem mon 3: "); scanf("%f", &n1->monhoc3);
}

void in1sinhvien(SV sv){
    printf("\n%5s \t %20s \t%10s \t %2d/%d/%d \t %10d \t %6.2f \t %6.2f \t %6.2f \t %6.2f \t %6s",sv.id,sv.hoten, sv.gioitinh,sv.ngaysinh.ngay,sv.ngaysinh.thang,sv.ngaysinh.nam,sv.tuoi,sv.monhoc1,sv.monhoc2,sv.monhoc3,sv.tb_diem,sv.hocluc);
}
void tuoi(SV *sv){
	sv->tuoi = 2024 - sv->ngaysinh.nam;
}
void diemtrungbinh(SV *sv){
    sv->tb_diem = (sv->monhoc1+sv->monhoc2+sv->monhoc3)/3;
}
void hocluc(SV *sv){
    if(sv->tb_diem <5.0){
        strcpy(sv->hocluc, "trung binh");
    }
    else if(sv->tb_diem <8.0){
        strcpy(sv->hocluc, "kha");
    }
    else{ strcpy(sv->hocluc, "gioi");}
}
void capnhapsv(SV *sv){
    nhap1sinhvien(sv);
    tuoi(sv);
    diemtrungbinh(sv); // truyen con tro;
    hocluc(sv);
}
void nhapdanhsachSV(SV ds[],int *n){
    do {
        printf("\n nhap so luong sinh vien: ");
        scanf("%d",n);
    }
    while(*n <=0);
    for(int i =0;i<*n;i++){
        capnhapsv(&ds[i]);
    }
}
void xuatdanhsachSV(SV ds[], int n){
    printf("%5s \t %20s \t %10s \t %10s \t %10s \t %6s \t %6s \t %6s \t %6s \t %5s", "ID", "Ten", "Gioi Tinh", "Ngay Sinh", "Tuoi", "Diem 1", "Diem 2", "Diem 3", "Diem TB", "XepLoai");
	printf("\n");
    for (int i = 0;i<n;i++){
        in1sinhvien(ds[i]);
    }
}

void xuatdulieuvaofile(SV sv[], int n){
    printf("\n nhap ten file:");
    char tenfile[20];
    fflush(stdin);fgets(tenfile,sizeof(tenfile), stdin); xoa_xuong_dong(tenfile);
    FILE *f;
    f = fopen(tenfile, "wb");
    if(f == NULL){
        printf("error !");
        exit(1);
    }
    fwrite(&n, sizeof(n),1,f);
    for (int i =0 ; i<n;i++){
        fwrite(&sv[i], sizeof(SV),1,f);
    }
    fclose(f);
}
void mofile(SV sv[],int *n){
    printf("\n nhap duong dan: ");
    char tenfile[20];
    fflush(stdin);fgets(tenfile,sizeof(tenfile), stdin); xoa_xuong_dong(tenfile);
    FILE *f;
    f = fopen(tenfile, "rb");
    if(f ==NULL){
        printf("error mo file !");
        exit(1);
    }
    fread(n, sizeof(*n),1,f);
    for(int i =0;i<(*n);i++){
            fread(&sv[i],sizeof(SV),1,f);
    }
    fclose(f);

}
void nhapphimbatki(){
    printf("\nnhap phim bat ki !");
}
int main(){
    SV sv[100];
    int n;
    int chon;
    SV temp[100];
    int ncp;
    do{
        printf("\nnhap lua chon :\n");
        printf("1 - phan danh sach sinh vien\n");
        printf("2 - xuat danh sach sinh vien \n");
        printf("3 - xuat danh sach sinh vien vao file \n");
        printf("4 - mo danh sach sinh vien vao file \n");
        printf("0 - Thoat \n");
        printf("phim :");
        scanf("%d",&chon);
        switch (chon){
            case 1:
                nhapdanhsachSV(sv, &n);
                //nhapphimbatki();
                break;
            case 2:
                xuatdanhsachSV(sv, n);
               // nhapphimbatki();
                break;
            case 3:
                xuatdulieuvaofile(sv , n);
                break;
            case 4:
                
                mofile(sv,&n);
                printf("%d",n);
                break;
        }

    }
    while(chon!=0);

}