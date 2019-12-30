/* -----------------------------------------------
Program 		:	Sulit3.c
Deskripsi		: 	Modul untuk memulai permainan level sulit papan 3x3
Author 			: 	Github MatthewSteel
Versi/tanggal	: 	29/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/

	/*Deklarasi*/
	int board[10] = {0,0,0,0,0,0,0,0,0,0};
	
	unsigned turn;
	
	int pilihan, i;
	
	
	/*Proses*/
	
	
	for(turn = 0; turn < 9 && CekMenang(board) == 0; ++turn){

		
		if((turn + GiliranMain) % 2 == 0) {
			LangkahKomputer(board);
		}
		else {
			board3(board);
			LangkahPemain(board);
		}
	}
	
	switch(CekMenang(board)) {
		case 0:
			board3(board);
			printf("Draw\n");
			break;
		
		case 1:
			board3(board);
			printf("Kamu Kalah\n");
			break;
			
		case -1:
			board3(board);
			printf("Kamu Menang!!\n");
			break;
	}
	getch();
