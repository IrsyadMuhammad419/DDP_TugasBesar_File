/* -----------------------------------------------
Program 		:	DisplayPemain3.c
Deskripsi		: 	Modul untuk menampilkan tampilan permainan board 3x3
Author 			: 	Irsyad Muhammad (191524014)
Versi/tanggal	: 	30/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/


void DisplayPemain3(int board[10]){
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan permainan board 3x3
//Board adalah parameter input bertipe integer dengan passing paramaeter passing by value

//I.S	:Tampilan akan 
//F.S	: Pada layar ditampilkan tampilan berupa papan 3x3, ronde, map permainan, dan timer
	
	/*Deklarasi*/
	int y; //variabel untuk menentukan koordinat y
	
	/*TAMPILAN SAAT PERMAINANA MULAI*/
	
	board3(board);
	gotoxy(15,2);printf("ษอออออออออออออออออออออออป");
	gotoxy(39,3);printf("บ");
	gotoxy(15,3);printf("บ Ronde Ke :\t %d",game);
	gotoxy(15,4);printf("ศอออออออออออออออออออออออผ");
	gotoxy(43,10);printf("Pemain ( O )        Komputer ( X )\n");
	gotoxy(145,10);printf("Map");
	
	
	for(y = 0; y < 48; y++){
		gotoxy(125,y);printf("บ");
	}
}
