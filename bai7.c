#include<stdio.h>
#include<stdlib.h>
struct linhkien
{
    char ten[40];
    int giatri;
    char donvi[10];
    char mausac[10];
};

int main(){
    struct linhkien  dientro = {"tro", 120,"om","vang"};
    struct linhkien     tudien= {"tu dien",47,"um","den"};
    struct linhkien *ban = (struct linhkien *)malloc(4*sizeof(struct linhkien));
    ban[0]= dientro;
    ban[1] = tudien;
// In giá trị của các linh kiện
printf("\n%d",dientro);
printf("\n%d",ban[0]);
    printf("Gia tri linh kien 1: %s, %d, %s, %s\n", ban[0].ten, ban[0].giatri, ban[0].donvi, ban[0].mausac);
    printf("Gia tri linh kien 2: %s, %d, %s, %s\n", ban[1].ten, ban[1].giatri, ban[1].donvi, ban[1].mausac);
    free(ban);
}