/* -----------------------------------------------
Program 		:	Judul.c
Deskripsi		: 	Modul Tampilan judul permainan (CCC) + fullscreen
Author 			: 	Irsyad Muhammad (191524014)
Versi/tanggal	: 	23/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void MenuUtama(){
//author	: Irsyad Muhammad

//Modul untuk menampilkan mneu utama dalam permainan
//I.S	: Ditampilkan tampilan layar sebelum modul MenuUtama
//F.S	: Ditampilkan tampilan menu utama yang menampilkan pilihan untuk bermain, petunjuk permainan, highscore, dan exit
	
	//PilihMenu adalah variabel lokal bertipe int yang berfungsi sebagai pilihan dari case menu	yang tersedia
	int PilihMenu;
	judul();
	
	gotoxy(58,18);printf("[1] MULAI BERMAIN\n");
	gotoxy(58,19);printf("[2] CARA BERMAIN\n");
	gotoxy(58,20);printf("[3] PAPAN PERINGKAT\n");
	gotoxy(58,21);printf("[0] KELUAR\n");
	gotoxy(58,22);pritnf("Pilih : \n");
	gotoxy(65,22);scanf("%d\n",PilihMenu);
	switch(PilihMenu){
		case 1: system("CLS");
		
		break;
		
		case 2: system("CLS");
		
		break;
		
		case 3: system("CLS");
		
		break;
		
		case 0: exit(1);
		break;
		
		default: MenuUtama();
		break;
	}
}
