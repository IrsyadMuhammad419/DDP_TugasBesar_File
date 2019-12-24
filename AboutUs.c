/* -----------------------------------------------
Program 		:	AboutUs.c
Deskripsi		: 	Modul Tampilan Credits (CCC) + fullscreen
Author 			: 	Irsyad Muhammad (191524014)
Versi/tanggal	: 	24/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/
#include<stdio.h>

void AboutUs(){
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan about us (credits permainan)
//I.S	:Ditampilkan tampilan sebelum tampilan about us
//F.S	:Ditampilkan tampilan about us di layar

	FILE *file;
	char length[6000]; //variabel length adalah variabel lokal bertipe array of char untuk memberi batas char dari file yang dibuka
	
	file=fopen("AboutUs.txt","r");
	
	while (fgets(length,6000,file)!=NULL){
		printf("%s", length);
	}
	
	fclose(file);
	
	getch();
	//KEMBALI KE MENU UTAMA
	system("CLS");
	
}

int main(){
	AboutUs();
}
