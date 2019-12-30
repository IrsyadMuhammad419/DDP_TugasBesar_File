/* -----------------------------------------------
Program 		:	LangkahKomputerMudah5.c
Deskripsi		: 	Modul untuk menentukan langkah yang akan diambil oleh komputer
Author 			:	Hanifah Ghina Nabila
Versi/tanggal	: 	30/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/


void LangkahKomputerMudah5(int board[26]){
//	author	: Hanifah Ghina Nabila
	
// board[26] adalah parameter input bertipe integer dengan passing parameter passing by value
//
    
	/*Deklarasi*/
	int move;

	/*Proses*/
	reset:
	move = 1 + rand()% 25; // 1 adalah range angka terkecil yg akan di random, dan 25 adalah angka terbesar yang akan dirandom
		
	if(board[move] != 0){
		goto reset;
	}
	else{
		board[move] = 1;
	}
}
