/* -----------------------------------------------
Program 		:	GridChar
Deskripsi		: 	Modul untuk menampilkan simbol di dalam papan
Author 			: 	Github Matthew Steel
Versi/tanggal	: 	29/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/

char gridChar(int i){
//author	: Github : Matthew Steel

//int i 	: parameter input bertipe integer dengan passing parameter passing by value.
//
	
	switch(i){
		case -1:
			return 'O';
		case 0:
			return ' ';
		case 1:
			return 'X';
	}	
	
}
