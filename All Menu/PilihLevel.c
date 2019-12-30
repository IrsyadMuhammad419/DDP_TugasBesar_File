/* -----------------------------------------------
Program 		:	PilihLevel.c
Deskripsi		: 	Modul untuk menampilkan tampilan pilihan level yang tersedia
Author 			: 	Irsyad Muhammad (191524014)
Versi/tanggal	: 	24/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/
#include<stdio.h>

void PilihLevel(){
//author	: Irsyad Muhammad

//Modul untuk menampilkan pilihan level yang tersedia
//I.S	: Ditampilkan tampilan layar modul MenuUtama
//F.S	: Ditampilkan tampilan menu yang menampilkan level yang tersedia

	int pilihlevel; //variabel lokal bertipe int yang berfungsi sebagai pilihan dari case menu yang tersedia
	gotoxy(70,20);printf("[1] MUDAH\n");
	gotoxy(70,21);printf("[2] MENENGAH\n");
	gotoxy(70,22);printf("[3] SULIT\n");
	gotoxy(70,23);printf("[0] KEMBALI KE MENU UTAMA\n");
	gotoxy(70,26);printf("Masukkan Pilihan :\n");
	gotoxy(83,26);scanf("%d",&pilihlevel);
	
	switch(pilihlevel){
		case 1:
			system("CLS");
			break;
			
		case 2:
			system("CLS");
			break;
			
		case 3:
			system("CLS");
			break;
			
		case 0:
			system("CLS");
			MenuUtama();
			break;
	}
}
