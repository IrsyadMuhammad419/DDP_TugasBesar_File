/* -----------------------------------------------
Program 		:	Papan permainan.c
Deskripsi		: 	Modul Tampilan Papan 5x5 + fullscreen
Author 			: 	Irsyad Muhammad (191524014)
Versi/tanggal	: 	22/12/2019 updated(30/12/2019)
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/
#include<stdio.h>
#include<conio.h>
#include<windows.h>

/*Inisialisasi*/
//void board5();
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

void board5(int b[26]) {
//Author	: Irsyad Muhammad

//Procedure untuk menampilkan papan ukuran 5x5
//I.S	: Layar menampilkan pilihan sebelum modul board5
//F.S	: Ditampilkan papan dengan grid 5x5
	
	system("CLS");
	/*TAMPILAN PAPAN*/
	gotoxy(60,10);printf("|     |     |     |\n");
	gotoxy(55,11);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n", gridChar(b[1]), gridChar(b[2]), gridChar(b[3]), gridChar(b[4]), gridChar(b[5])); //tempat penyimpanan bidak 1-5
	gotoxy(55,12);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,13);printf("|     |     |     |\n");
	gotoxy(55,14);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n", gridChar(b[6]), gridChar(b[7]), gridChar(b[8]), gridChar(b[9]), gridChar(b[10]));//tempat penyimpanan bidak 6-10
	gotoxy(55,15);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,16);printf("|     |     |     |\n");
	gotoxy(55,17);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n", gridChar(b[11]), gridChar(b[12]), gridChar(b[13]), gridChar(b[14]), gridChar(b[15])); //tempat penyimpanan bidak 11-15
	gotoxy(55,18);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,19);printf("|     |     |     |\n");
	gotoxy(55,20);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n", gridChar(b[16]), gridChar(b[17]), gridChar(b[18]), gridChar(b[19]), gridChar(b[20])); //tempat penyimpanan bidak 16-20
	gotoxy(55,21);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,22);printf("|     |     |     |\n");
	gotoxy(55,23);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n", gridChar(b[21]), gridChar(b[22]), gridChar(b[23]), gridChar(b[24]), gridChar(b[25])); //tempat penyimpanan bidak 21-25
	gotoxy(60,24);printf("|     |     |     |\n");
	/*END TAMPILAN PAPAN*/
}

int main(){
	fullscreen();
	board5();

}
