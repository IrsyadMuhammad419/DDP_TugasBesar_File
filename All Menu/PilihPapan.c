/* -----------------------------------------------
Program 		:	PilihLevel.c
Deskripsi		: 	Modul untuk menampilkan tampilan pilihan papan yang tersedia
Author 			: 	Irsyad Muhammad (191524014)
Versi/tanggal	: 	24/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/
#include<stdio.h>

void PilihPapan(){
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan pilihan papan yang tersedia
//I.S	: Ditampilkan tampilan modul PilihLevel
//F.S	: Ditampilkan tampilan pilihan papan yang tersedia yaitu papan 3x3 dan papan 5x5, serta pilihan kembali ke menu sebelumnya dan menu utama

	int pilihpapan; //pilihpapan adalah variabel lokal bertipe int yang berfungsi sebagai pilihan dari case menu yang tersedia
	
	gotoxy();printf("[1] PAPAN 3x3\n");
	gotoxy();printf("[2] PAPAN 5x5\\n");
	gotoxy();printf("[9] Kembali\n");
	gotoxy();printf("[0] Menu Utama\n");
	gotoxy();pritnf("Masukkan Pilihan :\n");
	gotoxy();scanf("%d",&pilihpapan);
	
		switch(pilihpapan){
			case 1:
				system("CLS");
				board3();
				break;
			
			case 2:
				system("CLS");
				board5();
				break;
			
			case 9:
				system("CLS");
				PilihLevel();
				break;
				
			case 0:
				system("CLS");
				MenuUtama();
				break;
		}
}
