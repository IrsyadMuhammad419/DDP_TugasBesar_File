/* -----------------------------------------------
Program 		:	LangkahKomputerMudah3.c
Deskripsi		: 	Modul untuk menentukan langkah yang akan diambil oleh komputer
Author 			: 	Irsyad Muhammad (191524014)
Versi/tanggal	: 	29/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/

void LangkahKomputerMudah3(int board[10]){
//	author	: Irsyad Muhammad
	
// board[10] adalah parameter input bertipe integer dengan passing parameter passing by value
//
    
	/*Deklarasi*/
	int i;
	int move;

	/*Proses*/
	reset:
	move = 1 + rand()% 8; // 1 adalah range angka terkecil yg akan di random, dan 9 adalah angka terbesar yang akan dirandom
		
	if(board[move] != 0){
		goto reset;
	}
	else{
		board[move] = 1;
	}
}
