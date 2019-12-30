/* -----------------------------------------------
Program 		:	LangkahKomputer.c
Deskripsi		: 	Modul untuk menentukan board yang akan diisi oleh komputer
Author 			: 	Github MatthewSteel
Versi/tanggal	: 	29/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/

void LangkahKomputer(int board[10]){
//	author	: Github Matthew Steel
	
// board[10] adalah parameter input bertipe integer dengan passing parameter passing by value
//
    
	/*Deklarasi*/
	int move = -1;
	int score = -2;
	int i;

	/*Proses*/
	for(i=1; i < 10; ++i) {
		
		if(board[i] == 0){
			board[i] = 1;
			int tempScore = -minimax(board, -1);
			board[i] = 0;
			if (tempScore > score) {
				score = tempScore;
				move = i;	
			}
		}
	}
	
	board[move] = 1;
}
