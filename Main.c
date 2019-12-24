/* -----------------------------------------------
Program 		:	Judul.c
Deskripsi		: 	Modul Tampilan judul permainan (CCC) + fullscreen
Author 			: 	Irsyad Muhammad (191524014)
Versi/tanggal	: 	21/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
/*INISIALISASI MODUL*/
void gotoxy(int x, int y);

void fullscreen(){
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void gotoxy(int x, int y){
//modul untuk memfungsikan fungsi gotoxy	
	HANDLE hConsoleOutput;  
	COORD dwCursorPosition;  
	dwCursorPosition.X = x;  
	dwCursorPosition.Y = y;  
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);   
}

void judul(){
// Author	: Irsyad Muhammad

// Procedur untuk menampilkan judul permainan
// I.S		: Layar menampilkan blankpage
// F.S		: Layar menampilkan judul permainan "CCC :Circle Cross Challange"

/*BEGIN PROCEDURE_JUDUL*/	
	/*TAMPILAN CCC*/
	
	/*baris 1*/
	gotoxy(58,5); printf("лллллллллллл\n");
	gotoxy(76,5); printf("лллллллллллл\n");
	gotoxy(94,5); printf("лллллллллллл\n");
	
	/*baris 2*/
	gotoxy(58,6); printf("лллллллллллл\n");
	gotoxy(76,6); printf("лллллллллллл\n");
	gotoxy(94,6); printf("лллллллллллл\n");
	
	/*baris 3*/
	gotoxy(58,7); printf("ллллл\n");
	gotoxy(76,7); printf("ллллл\n");
	gotoxy(94,7); printf("ллллл\n");
	
	/*baris 4*/
	gotoxy(58,8); printf("ллллл\n");
	gotoxy(76,8); printf("ллллл\n");
	gotoxy(94,8); printf("ллллл\n");
	
	/*baris 5*/
	gotoxy(58,9); printf("ллллл\n");
	gotoxy(76,9); printf("ллллл\n");
	gotoxy(94,9); printf("ллллл\n");
	
	/*baris 6*/
	gotoxy(58,10); printf("ллллл\n");
	gotoxy(76,10); printf("ллллл\n");
	gotoxy(94,10); printf("ллллл\n");
		
	/*baris 7*/
	gotoxy(58,11); printf("лллллллллллл\n");
	gotoxy(76,11); printf("лллллллллллл\n");
	gotoxy(94,11); printf("лллллллллллл\n");
	
	/*baris 8*/
	gotoxy(58,12); printf("лллллллллллл\n");
	gotoxy(76,12); printf("лллллллллллл\n");
	gotoxy(94,12); printf("лллллллллллл\n");
	/*END TAMPILAN CCC*/
	
	/*TAMPILAN CIRCLE CROSS CHALLANGE*/
	gotoxy(70,14);printf("CIRCLE CROSS CHALLENGES\n\n");
	/*END TAMPILAN CIRCLE CROSS CHALLANGE*/
	
/*END PROCEDURE_JUDUL*/
}

void AboutUs(){
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan about us (credits permainan)
//I.S	:Ditampilkan tampilan sebelum tampilan about us
//F.S	:Ditampilkan tampilan about us di layar

/*BEGIN PROCEDUR ABOUTUS*/
	FILE *file;
	char length[6000];//variabel length adalah variabel lokal bertipe array of char untuk memberi batas char dari file yang dibuka
	
	file=fopen("AboutUs.txt","r");
	
	while (fgets(length,6000,file)!=NULL){
		printf("%s", length);
	}
	
	fclose(file);
	
	gotoxy(70,30);printf("Tekan Tombol Untuk Melanjutkan...\n");getch();
	//KEMBALI KE MENU UTAMA
	system("CLS");
	MenuUtama();
/*END PROCEDURE ABOUTUS*/

}

void MenuUtama(){
//author	: Irsyad Muhammad

//Modul untuk menampilkan mneu utama dalam permainan
//I.S	: Ditampilkan tampilan layar sebelum modul MenuUtama
//F.S	: Ditampilkan tampilan menu utama yang menampilkan pilihan untuk bermain, petunjuk permainan, highscore, dan exit
	
	//PilihMenu adalah variabel lokal bertipe int yang berfungsi sebagai pilihan dari case menu	yang tersedia
	int PilihMenu;
	judul();
	
	gotoxy(70,20);printf("[1] PERMAINAN BARU\n");
	gotoxy(70,21);printf("[2] CARA BERMAIN\n");
	gotoxy(70,22);printf("[3] PAPAN PERINGKAT\n");
	gotoxy(70,23);printf("[4] CREDITS");
	gotoxy(70,24);printf("[0] KELUAR\n");
	gotoxy(70,26);printf("Pilih : \n");
	gotoxy(78,26);scanf("%d",&PilihMenu);
	switch(PilihMenu){
		case 1: system("CLS");
		
		break;
		
		case 2: system("CLS");
		
		break;
		
		case 3: system("CLS");
		
		break;
		
		case 4: 
				system("CLS");
				AboutUs();
		break;
		
		case 0: exit(1);
		break;
		
		default: MenuUtama();
		break;
	}
}

int main(){
	fullscreen();
	MenuUtama();
}
