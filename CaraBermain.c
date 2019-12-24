/* -----------------------------------------------
Program 		:	AboutUs.c
Deskripsi		: 	Modul Tampilan Cara bermain dan aturan (CCC) + fullscreen
Author 			: 	Irsyad Muhammad (191524014)
Versi/tanggal	: 	24/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/
#include<stdio.h>

void CaraBermain(){
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan cara bermain dan aturan
//I.S	:Ditampilkan tampilan sebelum tampilan CaraBermain
//F.S	:Ditampilkan tampilan CaraBermain di layar

/*BEGIN PROCEDURE CARA_BERMAIN*/

	FILE*file;
	char length[6000];//variabel length adalah variabel lokal bertipe array of char untuk memberi batas char dari file yang dibuka
	
	file=fopen("CaraBermain.txt","r");
	
	while(fgets(length,6000,file)!=NULL){
		printf("%s", length);
	}
	
	fclose(file);
	getch();
	//KEMBALI KE MENU UTAMA
	system("CLS");
	
/*END PROCEDURE CARA_BERMAIN*/
}
