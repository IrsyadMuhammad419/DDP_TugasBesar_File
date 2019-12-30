/* -----------------------------------------------
Program 		:	Mudah5.c
Deskripsi		: 	Modul untuk memulai permainan level mudah papan 5x5
Author 			: 	Hanifah Ghina Nabila
Versi/tanggal	: 	30/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/

int Mudah5(int GiliranMain){
// author	:Hanifah Ghina Nabila

//
//
	/*Deklarasi*/
	int board[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	unsigned turn;
	
	int pilihan;
	
	/*Proses*/		
	for(turn = 0; turn < 25 && CekMenang5(board) == 0; ++turn){

				
		if((turn + GiliranMain) % 2 == 0) {
			LangkahKomputerMudah5(board);
		}
		else {
			LangkahPemain5(board);
		}
	}
	
	switch(CekMenang5(board)) {
		case 0:
			DisplayPemain5(board);
			gotoxy(45,27);printf("Permainan Imbang!\n");
			if (game == 11){
				system("CLS");
				/*Panggil modul score*/
			}
			break;
		
		case 1:
			DisplayPemain5(board);
			gotoxy(45,27);printf("Kamu Kalah :(\n");
			if (game == 11){
				system("CLS");
				/*Panggil modul score*/
			}
			break;
			
		case -1:
			DisplayPemain5(board);
			gotoxy(45,27);printf("Kamu Menang!!\n");
			if (game == 11){
				system("CLS");
				/*Panggil modul score*/
			}
			break;
	}
}
