/* -----------------------------------------------
Program 		:	LangkahPemain3.c
Deskripsi		: 	Modul untuk menerima input langkah yang akan diambil oleh pemain
Author 			:	Github Matthew Steel
Versi/tanggal	: 	29/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/

void LangkahPemain3(int board[10]) {
// author	: Github Matthew Steel

// board[10] adalah parameter input bertipe integer dengan passing parameter passing by value
//

	/*Deklarsi*/
	int move = 0;
	
	
	/*Proses*/
	do{
		begin:
		
			DisplayPemain3(board);
		
			gotoxy(45,28);printf("Masukkan Pilihan :");
			gotoxy(65,28);scanf("%d", &move);
			
			if (board[move] != 0){
				gotoxy(45, 32);printf("Langkah Tidak Valid!\n");
				gotoxy(65, 32);getch();
				goto begin;
				printf("\n");
			}
	}while( move >= 10 || move < 1 && board[move] == 0);
	
	board[move] = -1;
}
