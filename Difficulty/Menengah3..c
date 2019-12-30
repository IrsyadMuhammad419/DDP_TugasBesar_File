/* -----------------------------------------------
Program 		:	Menengah3.c
Deskripsi		: 	Modul untuk memulai permainan level menengah papan 3x3
Author 			: 	Irsyad Muhammad
Versi/tanggal	: 	29/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/

int Menengah3(int GiliranMain){
// author	: Irsyad Muhammad

//
//
	/*Deklarasi*/
	int board[10] = {0,0,0,0,0,0,0,0,0,0};
	
	unsigned turn;
	
	int pilihan;
	
	
	/*Proses*/
	
	
	for(turn = 0; turn < 9 && CekMenang(board) == 0; ++turn){

		
		if((turn + GiliranMain) % 2 == 0) {
			if(turn < 6) {
				LangkahKomputerSulit3(board);
			}
			else{
				LangkahKomputerMudah3(board);
			}
		}
		else {
			LangkahPemain3(board);
		}
	}
	
	switch(CekMenang(board)) {
		case 0:
			DisplayPemain3(board);
			gotoxy(45,27);printf("Permainan Imbang!\n");
			if (game == 11){
				system("CLS");
				/*Panggil modul score*/
			}
			break;
		
		case 1:
			DisplayPemain3(board);
			gotoxy(45,27);printf("Kamu Kalah :(\n");
			if (game == 11){
				system("CLS");
				/*Panggil modul score*/
			}
			break;
			
		case -1:
			DisplayPemain3(board);
			gotoxy(45,27);printf("Kamu Menang!!\n");
			if (game == 11){
				system("CLS");
				/*Panggil modul score*/
			}
			break;
	}
}
