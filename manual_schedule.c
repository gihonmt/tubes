//***********************************************************//
//                      [ Source Code ]
//
// Institution: Institut Teknologi Bandung
// Name: A2/4
// File Name: manual_schedule.c
// Dependency : stdio.h, stdlib.h, string.h
//
// Description:
// Fungsi untuk membuat schedule secara manual
//
// Status:
// 1. Cynthia Evani - 13217045 : Create the file
// 2. <Nama Praktikan> - <NIM> : Fix the bug where number 2 printed twice
//***********************************************************//

//BELOM LENGKAP:
//Deklarasi fungsi
//Link ke fungsinya
//ANJING GUE BARU SADAR MISAL INPUTNYA A TAPI ROMBONGAN ADA A1, A2, A3 GITU ITU
//  INPUTNYA JADI 3 RUANGAN --> solved pake struct, kalo jelek debug aja

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ASUMSI
//Perintah keluar hanya bisa dimasukkan di kode praktikum
//Kalau hari sabtu atau minggu, pesan error --> di validasi


void manual_schedule()
{
    typedef struct ruangan_s{
        char *i, *j, *k;
    }ruangan_t;
    
    char *kodeprak, *rombongan, *minggu, *hari;
    int cekquit;
    ruangan_t *ruangan;
    
    kodeprak = (char*)malloc(6*sizeof(char));
    rombongan = (char*)malloc(2*sizeof(char));
    minggu = (char*)malloc(2*sizeof(char));
    hari = (char*)malloc(8*sizeof(char));
    ruangan = (ruangan_t*)malloc(4*sizeof(ruangan_t));
    
    cekquit = (strcmp(kodeprak,"q")||strcmp(kodeprak,"Q"));

    printf("[Mode Schedule]\n");
    printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
    
    while(cekquit == 0){
        printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200): ");
        scanf("%s",kodeprak);
        Validasi_KodePrak(kodeprak); //Gihon
        if(strcmp(kodeprak,"EL2205") == 1){
            printf("\nRombongan (A1, A2, B1, B2, C1, atau C2): ");
            scanf("%s",rombongan);
            Validasi_RombonganEL2205(rombongan);//Justin
        }
        else if(strcmp(kodeprak,"EL2208") == 1){
            printf("\nRombongan (A1, A2, A3, B1, B2, B3, atau C): ");
            scanf("%s",rombongan);
            Validasi_RombonganEL2208(rombongan);//taudah
        }
        else{
            printf("\nRombongan (A atau B): ");
            scanf("%s",rombongan);
            Validasi_RombonganEB2200(rombongan);//taudah
        }
        
        printf("\nMinggu ke: ");
        scanf("%s",minggu);
        Validasi_Minggu(minggu);
        
        printf("\nRuangan: ");
        if(strlen(rombongan)>1){ //Kebanyakan yang cuma 1 karakter ada subnya
            if((strcmp(kodeprak,"EL2205") == 1)){ //Kalo EL2205 pasti 2 ruangan
                printf("Ruangan 1:"); scanf("%s",ruangan->i);
                printf("Ruangan 2:"); scanf("%s",ruangan->j);
            }
            else if((strcmp(kodeprak,"EL2208") == 1)&&((strcmp(rombongan,"A")==1)||(strcmp(rombongan,"B")==1))){
                printf("Ruangan 1:"); scanf("%s",ruangan->i);
                printf("Ruangan 2:"); scanf("%s",ruangan->j);
                printf("Ruangan 3:"); scanf("%s",ruangan->k);
            }
        }
        else{
            printf("Ruangan:"); scanf("%s",ruangan->i);
        }
    }
    if(cekquit == 1){
        exit(0);
    }
}
