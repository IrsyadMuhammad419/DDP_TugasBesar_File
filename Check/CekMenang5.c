/* -----------------------------------------------
Program 		:	CekMenang.c
Deskripsi		: 	Modul untuk memeriksa apakah sudah ada pemenang?
Author 			:	Hanifah Ghina Nabila
Versi/tanggal	: 	30/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/

int CekMenang5(const int board[26]){
//author	: Hanifah Ghina Nabila

//
//
	
	/*Deklarasi*/
	unsigned wins[12][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{1,6,11,16,21},{2,7,12,17,22},
	{3,8,13,18,23},{4,9,14,19,24},{5,10,15,20,25},{1,7,13,19,25},{5,9,13,17,21}};
	int i;
	
	/*Proses*/
	for(i = 0; i < 12; ++i){
		if (board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]] &&
           board[wins[i][0]] == board[wins[i][3]] &&
           board[wins[i][0]] == board[wins[i][4]])
			return board[wins[i][4]];
	}
	return 0;
}
