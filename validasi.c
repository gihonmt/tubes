#include <stdio.h>
#include <string.h>

int main(){
    char kodeprak[10];
    

    printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
    scanf("%s", kodeprak);
    while(strcmp(kodeprak,"EL2205")!= 0 && strcmp(kodeprak,"EL2208")!= 0 && strcmp(kodeprak,"EB2200")!= 0){
        printf("Input tidak valid.\n");
        printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
        scanf("%s", kodeprak);
    }
    return 0;
}
