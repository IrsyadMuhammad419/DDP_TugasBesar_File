/* -----------------------------------------------
Program 		:	CCC.c
Deskripsi		: 	Game Tic Tac Toe
Author 			: 	Hanifah Ghina Nabila (191524010)
					Irsyad Muhammad (191524014)
Versi/tanggal	: 	1.1 / 21/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>


/*VARIABEL GLOBAL*/
int Generate=1; //variabel global untuk menentukan kecerdasan komputer dan papan yang akan dipanggil
int game = 1; //variabel global untuk menentukan permainan sedang berada di ronde ke berapa / untuk membuat permainan berulang selama 10 kali


/*INISIALISASI MODUL*/
void gotoxy(int x, int y);
void MenuUtama();
void PilihPapan();
void DisplayPemain(int board[10]);
void board3(int board[10]);
void board5();


void fullscreen(){
//author	: internet

//Modul untuk membuat console windows menjadi layar penuh
//I.S	: 
//F.S	:

	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}


void gotoxy(int x, int y){
//author	: 

//modul untuk memfungsikan fungsi gotoxy
//I.S	:
//F.S	:
	
	HANDLE hConsoleOutput;  
	COORD dwCursorPosition;  
	dwCursorPosition.X = x;  
	dwCursorPosition.Y = y;  
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);   
}


void Judul(){
// Author	: Irsyad Muhammad

// Procedur untuk menampilkan judul permainan
// I.S	: Layar menampilkan blankpage
// F.S	: Layar menampilkan judul permainan "CCC :Circle Cross Challange"

/*BEGIN PROCEDURE_JUDUL*/	
	/*TAMPILAN CCC*/
	
	/*baris 1*/
	gotoxy(58,5); printf("лллллллллллл\n");
	gotoxy(76,5); printf("лллллллллллл\n");
	gotoxy(94,5); printf("лллллллллллл\n");
	
	/*baris 2*/
	gotoxy(58,6); printf("лллллллллллл\n");
	gotoxy(76,6); printf("лллллллллллл\n");
	gotoxy(94,6); printf("лллллллллллл\n");
	
	/*baris 3*/
	gotoxy(58,7); printf("ллллл\n");
	gotoxy(76,7); printf("ллллл\n");
	gotoxy(94,7); printf("ллллл\n");
	
	/*baris 4*/
	gotoxy(58,8); printf("ллллл\n");
	gotoxy(76,8); printf("ллллл\n");
	gotoxy(94,8); printf("ллллл\n");
	
	/*baris 5*/
	gotoxy(58,9); printf("ллллл\n");
	gotoxy(76,9); printf("ллллл\n");
	gotoxy(94,9); printf("ллллл\n");
	
	/*baris 6*/
	gotoxy(58,10); printf("ллллл\n");
	gotoxy(76,10); printf("ллллл\n");
	gotoxy(94,10); printf("ллллл\n");
		
	/*baris 7*/
	gotoxy(58,11); printf("лллллллллллл\n");
	gotoxy(76,11); printf("лллллллллллл\n");
	gotoxy(94,11); printf("лллллллллллл\n");
	
	/*baris 8*/
	gotoxy(58,12); printf("лллллллллллл\n");
	gotoxy(76,12); printf("лллллллллллл\n");
	gotoxy(94,12); printf("лллллллллллл\n");
	/*END TAMPILAN CCC*/
	
	/*TAMPILAN CIRCLE CROSS CHALLANGE*/
	gotoxy(70,15);printf("CIRCLE CROSS CHALLENGES\n\n");
	/*END TAMPILAN CIRCLE CROSS CHALLANGE*/
	
	/*GARIS PEMBATAS*/
	gotoxy(55,17);printf("______________________________________________________");
	/*END GARIS PEMBATAS*/
	
/*END PROCEDURE_JUDUL*/
}


void PilihLevel(){
//author	: Irsyad Muhammad

//Modul untuk menampilkan pilihan level yang tersedia
//I.S	: Ditampilkan tampilan layar modul MenuUtama
//F.S	: Ditampilkan tampilan menu yang menampilkan level yang tersedia

	int pilihlevel; //variabel lokal bertipe int yang berfungsi sebagai pilihan dari case menu yang tersedia
	gotoxy(70,20);printf("[1] MUDAH\n");
	gotoxy(70,21);printf("[2] MENENGAH\n");
	gotoxy(70,22);printf("[3] SULIT\n");
	gotoxy(70,23);printf("[0] Kembali Ke Menu Utama\n");
	gotoxy(70,25);printf("Masukkan Pilihan :\n");
	gotoxy(90,25);scanf("%d",&pilihlevel);
	
	switch(pilihlevel){
		case 1:
			system("CLS");
			Generate=Generate*1;
			PilihPapan();
			break;
			
		case 2:
			system("CLS");
			Generate=Generate*2;
			PilihPapan();
			break;
			
		case 3:
			system("CLS");
			Generate=Generate*3;
			PilihPapan();
			break;
			
		case 0:
			system("CLS");
			MenuUtama();
			break;
	}
}


void PilihPapan(){
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan pilihan papan yang tersedia
//I.S	: Ditampilkan tampilan modul PilihLevel
//F.S	: Ditampilkan tampilan pilihan papan yang tersedia yaitu papan 3x3 dan papan 5x5, serta pilihan kembali ke menu sebelumnya dan menu utama

	int pilihpapan; //pilihpapan adalah variabel lokal bertipe int yang berfungsi sebagai pilihan dari case menu yang tersedia
	
	gotoxy(73,18);printf("PILIH PAPAN");
	gotoxy(70,20);printf("[1] PAPAN 3x3\n");
	gotoxy(70,21);printf("[2] PAPAN 5x5\n");
	gotoxy(70,22);printf("[9] Kembali\n");
	gotoxy(70,23);printf("[0] Menu Utama\n");
	gotoxy(70,25);printf("Masukkan Pilihan :\n");
	gotoxy(90,25);scanf("%d",&pilihpapan);
	
		switch(pilihpapan){
			case 1:
				system("CLS");
				Generate=Generate*3;
				GuntingKertasBatu();
				break;
			
			case 2:
				system("CLS");
				Generate=Generate*5;
				GuntingKertasBatu();
				break;
			
			case 9:
				system("CLS");
				PilihLevel();
				break;
				
			case 0:
				system("CLS");
				MenuUtama();
				break;
		}
}


int GuntingKertasBatu(){
//author	: http://deriyuliansyah.blogspot.com/2014/04/game-gunting-batu-dan-kertas-bahasa-c.html

//Modul untuk menampilkan permainan gunting kertas batumemain
//	: 
//	: 

    srand(time(NULL)); //berguna untuk mengacak angka
    int pemain; //merupakan inisialisasi dari pilihan tangan player
    int musuh; //merupakan inisialisasi dari pilihan tangan musuh
    int menang=0; //merupakan inisialisasi dari banyak kemenangan, jumlahnya dimulai dari 0
    int seri=0; //merupakan inisialisasi dari banyak imbang, jumlahnya dimulai dari 0
    int kalah=0; //merupakan inisialisasi dari banyak kekalahan, jumlahnya dimulai dari 0
    char jawaban;
    system("cls"); //berfungsi untuk clear screen atau membersihkan layar(mengosongkan layar)

        musuh = rand()%3; //inisialisasi dari pilihan musuh yang acak dari 0 hingga 2
        gotoxy(70,15);printf("Pilihlah Tanganmu : \n");
        gotoxy(70,16);printf("1. Gunting\n");
        gotoxy(70,17);printf("2. Batu\n");
        gotoxy(70,18);printf("3. Kertas\n");
        gotoxy(70,20);printf("Masukkan Pilihan : ");
        gotoxy(90,20);scanf("%d",&pemain); //menginput pilihan tangan user/player
        
		if(pemain>0 && pemain<4){
			if(musuh==0) //jika hasil acak = 0 berinisialiasi bahwa pilihan musuh adalah gunting
	        {
	            if(pemain==1) //jika pemain menginput 1 maka inisialiasinya pemain gunting
	            {
	                gotoxy(65,22);printf("Gunting Lawan Gunting = Kau Seri \n\n");
	                seri++; //jika hasilnya seri maka variabel seri akan bertambah sebanyak 1
	                gotoxy(65,25);system("pause");
	                GuntingKertasBatu();
	            }
	            else if(pemain==2) //jika pemain menginput 1 maka inisialiasinya pemain batu
	            {
	                gotoxy(65,22);printf("Gunting Lawan Batu = Kau Menang \n\n");
	                gotoxy(70,23);printf("Urutan Main = Pertama");
	                menang++; //jika hasilnya seri maka variabel menang akan bertambah sebanyak 1
	                gotoxy(65,25);system("pause");
	                
					switch(Generate){
						case 3: 
							do{
								Mudah3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
						
						case 5:
							Mudah5(1);
						
						case 6:
							do{
								Menengah3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 10:
							Menengah5(1);
							
						case 9:
							do{
								Sulit3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 15:
							Sulit5(1);
					}
	            }
	            else if(pemain==3) //jika pemain menginput 1 maka inisialiasinya pemain kertas
	            {
	                gotoxy(65,22);printf("Gunting Lawan Kertas = Kau Kalah \n\n");
	                gotoxy(70,23);printf("Urutan Main = Kedua\n");
	                
	                kalah++; //jika hasilnya seri maka variabel kalah akan bertambah sebanyak 1
	                gotoxy(65,25);;system("pause");
					
					switch(Generate){
						case 3: 
							do{
								Mudah3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
							
						case 5:
							Mudah5(2);
						
						case 6:
							do{
								Menengah3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 10:
							Menengah5(2);
							
						case 9:
							do{
								Sulit3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
						
						case 15:
							Sulit5(2);
					}
	            }
	        }
	        else if(musuh==1)
	        {
	            if(pemain==1) //jika pemain menginput 1 maka inisialiasinya pemain gunting
	            {
	                gotoxy(65,22);printf("Batu Lawan Gunting = Kau Kalah \n\n");
	                gotoxy(70,23);printf("Urutan Main = Kedua\n");
	                	                
	                kalah++; //jika hasilnya seri maka variabel kalah akan bertambah sebanyak 1
	                gotoxy(65,25);system("pause");
	               
				   	switch(Generate){
						case 3: 
							do{
								Mudah3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
						
						case 5:
							Mudah5(2);
						
						case 6:
							do{
								Menengah3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 10:
							Menengah5(2);
							
						case 9:
							do{
								Sulit3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 15:
							Sulit5(2);
					}	                
	            }
	            else if(pemain==2) //jika pemain menginput 1 maka inisialiasinya pemain batu
	            {
	                gotoxy(65,22);printf("Batu Lawan Batu = Kau Seri \n\n");
	                seri++; //jika hasilnya seri maka variabel seri akan bertambah sebanyak 1
	                gotoxy(65,25);system("pause");
	                GuntingKertasBatu();
	            }
	            else if(pemain==3) //jika pemain menginput 1 maka inisialiasinya pemain kertas
	            {
	                gotoxy(65,22);printf("Batu Lawan Kertas = Kau Menang \n\n");
					gotoxy(70,23);printf("Urutan Main = Pertama\n");
	                menang++; //jika hasilnya seri maka variabel menang akan bertambah sebanyak 1
	                gotoxy(65,25);system("pause");
					switch(Generate){
						case 3: 
							do{
								Mudah3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
						
						case 5:
							Mudah5(1);
						
						case 6:
							do{
								Menengah3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 10:
							Menengah5(1);
							
						case 9:
							do{
								Sulit3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 15:
							Sulit5(1);
					}
	            }
	        }
	        if(musuh==2)
	        {
	            if(pemain==1) //jika pemain menginput 1 maka inisialiasinya pemain gunting
	            {
	                gotoxy(65,22);printf("Kertas Lawan Gunting = Kau Menang \n\n");
	                gotoxy(70,23);printf("Urutan Main = Pertama\n");
					menang++; //jika hasilnya seri maka variabel menang akan bertambah sebanyak 1
	                gotoxy(65,25);system("pause");
	                
	                switch(Generate){
						case 3: 
							do{
								Mudah3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
							
						case 5:
							Mudah5(1);
						
						case 6:
							do{
								Menengah3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 10:
							Menengah5(1);
							
						case 9:
							do{
								Sulit3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 15:
							Sulit5(1);
					}
	            }
	            else if(pemain==2) //jika pemain menginput 1 maka inisialiasinya pemain batu
	            {
	                gotoxy(65,22);printf("Kertas Lawan Batu = Kau Kalah \n\n");
	                gotoxy(70,23);printf("Urutan Main = Kedua\n");
	                kalah++; //jika hasilnya seri maka variabel kalah akan bertambah sebanyak 1
	                gotoxy(65,25);system("pause");
	                
            		switch(Generate){
						case 3: 
							do{
								Mudah3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
							
						case 5:
							Mudah5(2);
						
						case 6:
							do{
								Menengah3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 10:
							Menengah5(2);
							
						case 9:
							do{
								Sulit3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 15:
							Sulit5(2);
					}
	            }
	            else if(pemain==3) //jika pemain menginput 1 maka inisialiasinya pemain kertas
	            {
	                gotoxy(65,22);printf("Kertas Lawan Kertas = Kau Seri \n\n");
	                seri++; //jika hasilnya seri maka variabel seri akan bertambah sebanyak 1
	                gotoxy(65,25);system("pause");
	                GuntingKertasBatu();
	            }
	        }
		}else{
			gotoxy(65,22);printf("Angka Anda Masukkan Tidak Valid\n");
			getch();
			GuntingKertasBatu();
		}
}


int CekMenang(const int board[10]){
//author	:

//
//
	
	/*Deklarasi*/
	unsigned wins[8][3]={{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
	int i;
	
	/*Proses*/
	for(i = 0; i < 8; ++i){
		if (board[wins[i][0]] != 0 &&
           board[wins[i][0]] == board[wins[i][1]] &&
           board[wins[i][0]] == board[wins[i][2]])
			return board[wins[i][2]];
	}
	return 0;
}


int minimax(int board[10], int player) {
//author	: Github: Matthew Steel, 2009

// Modul untuk mencari kemungkinan pergerakan komputer yang memungkinkan dan baik untuk komputermenentukan pergerakan komputer dengan menelurusipergerakan komputer
//board[10]	: parameter input bertipe integer dengan passing parameter passing by value
//player	: parameter input bertipe integer dengan passing parameter passing by valuepassing 

    //How is the position like for player (their turn) on board?
    int winner = CekMenang(board);
    if(winner != 0) return winner*player;

    int move = -1;
    int score = -2;//Losing moves are preferred to no move
    int i;
    for(i = 1; i < 10; ++i) {//For all moves,
        if(board[i] == 0) {//If legal,
            board[i] = player;//Try the move
            int thisScore = -minimax(board, player*-1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }//Pick the one that's worst for the opponent
            board[i] = 0;//Reset board after try
        }
    }
    if(move == -1) return 0;
    return score;
}


void LangkahKomputerMudah3(int board[10]) {
//	author	: Irsyad Muhammad
	
// board[10] adalah parameter input bertipe integer dengan passing parameter passing by value
//
    
	/*Deklarasi*/
	int i;
	int move;

	/*Proses*/
	reset:
	move = 1 + rand()% 9; // 1 adalah range angka terkecil yg akan di random, dan 9 adalah angka terbesar yang akan dirandom
		
	if(board[move] != 0){
		goto reset;
	}
	else{
		board[move] = 1;
	}
}


void LangkahKomputerSulit3(int board[10]){
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


void DisplayPemain(int board[10]){
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan permainan board 3x3
//Board adalah parameter input bertipe integer dengan passing paramaeter passing by value

//I.S	:Tampilan akan 
//F.S	: Pada layar ditampilkan tampilan berupa papan 3x3, ronde, map permainan, dan timer
	
	/*Deklarasi*/
	int y; //variabel untuk menentukan koordinat y
	
	/*TAMPILAN SAAT PERMAINANA MULAI*/
	
	board3(board);
	gotoxy(15,2);printf("ЩЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЛ");
	gotoxy(39,3);printf("К");
	gotoxy(15,3);printf("К Ronde Ke :\t %d",game);
	gotoxy(15,4);printf("ШЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭЭМ");
	gotoxy(43,7);printf("Pemain ( O )        Komputer ( X )\n");
	gotoxy(145,7);printf("Map");
	
	
	for(y = 0; y < 48; y++){
		gotoxy(125,y);printf("К");
	}
}

void LangkahPemain(int board[10]) {
// author	:

// board[10] adalah parameter input bertipe integer dengan passing parameter passing by value
//

	/*Deklarsi*/
	int move = 0;
	
	
	/*Proses*/
	do{
		begin:
		
			DisplayPemain(board);
		
			gotoxy(45,25);printf("Masukkan Pilihan :");
			gotoxy(65,25);scanf("%d", &move);
			
			if (board[move] != 0){
				gotoxy(45, 27);printf("Langkah Tidak Valid!\n");
				gotoxy(65, 27);getch();
				goto begin;
				printf("\n");
			}
	}while( move >= 10 || move < 1 && board[move] == 0);
	
	board[move] = -1;
}


int Mudah3(int GiliranMain){
// author	:

//
//
	/*Deklarasi*/
	int board[10] = {0,0,0,0,0,0,0,0,0,0};
	
	unsigned turn;
	
	int pilihan, i;
	
	/*Proses*/		
	for(turn = 0; turn < 9 && CekMenang(board) == 0; ++turn){

				
		if((turn + GiliranMain) % 2 == 0) {
			LangkahKomputerMudah3(board);
		}
		else {
			LangkahPemain(board);
		}
	}
	
	switch(CekMenang(board)) {
		case 0:
			DisplayPemain(board);
			gotoxy(45,27);printf("Permainan Imbang!\n");
			if (game == 11){
				system("CLS");
				/*Panggil modul score*/
			}
			break;
		
		case 1:
			DisplayPemain(board);
			gotoxy(45,27);printf("Kamu Kalah :(\n");
			if (game == 11){
				system("CLS");
				/*Panggil modul score*/
			}
			break;
			
		case -1:
			DisplayPemain(board);
			gotoxy(45,27);printf("Kamu Menang!!\n");
			if (game == 11){
				system("CLS");
				/*Panggil modul score*/
			}
			break;
	}
}


int Mudah5(int GiliranMain){
	exit(1);
}


int Menengah3(int GiliranMain){
// author	:

//
//
	/*Deklarasi*/
	int board[10] = {0,0,0,0,0,0,0,0,0,0};
	
	unsigned turn;
	
	int pilihan, i;
	
	
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
			LangkahPemain(board);
		}
	}
	
	switch(CekMenang(board)) {
		case 0:
			DisplayPemain(board);
			gotoxy(45,27);printf("Permainan Imbang!\n");
			if (game == 11){
				system("CLS");
				/*Panggil modul score*/
			}
			break;
		
		case 1:
			DisplayPemain(board);
			gotoxy(45,27);printf("Kamu Kalah :(\n");
			if (game == 11){
				system("CLS");
				/*Panggil modul score*/
			}
			break;
			
		case -1:
			DisplayPemain(board);
			gotoxy(45,27);printf("Kamu Menang!!\n");
			if (game == 11){
				system("CLS");
				/*Panggil modul score*/
			}
			break;
	}
}


int Menengah5(int GiliranMain){
	exit(1);
}


int Sulit3(int GiliranMain){
// author	:

//
//
	/*Deklarasi*/
	int board[10] = {0,0,0,0,0,0,0,0,0,0};
	
	unsigned turn;
	
	int pilihan, i;
	
	
	/*Proses*/
	
	
	for(turn = 0; turn < 9 && CekMenang(board) == 0; ++turn){

		
		if((turn + GiliranMain) % 2 == 0) {
			LangkahKomputerSulit3(board);
		}
		else {
			LangkahPemain(board);
		}
	}
	
	switch(CekMenang(board)) {
		case 0:
			board3(board);
			gotoxy(65,27);printf("Permainan Imbang!\n");
			break;
		
		case 1:
			board3(board);
			gotoxy(65,27);printf("Kamu Kalah :(\n");
			break;
			
		case -1:
			board3(board);
			gotoxy(65,27);printf("Kamu Menang!!\n");
			break;
	}
	getch();
}


int Sulit5(int GiliranMain){
	exit(1);
}


char gridChar(int i){
//author	: Github : Matthew Steel

//Modul untuk menampilkan simbol di dalam papan
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


void board3(int b[10]) {
//Author	: Irsyad Muhammad

//Procedure untuk menampilkan papan ukuran 3x3
//I.S	: Layar menampilkan pilihan sebelum modul board3
//F.S	: Ditampilkan papan dengan grid 3x3
	
	int x = 50;
	system("CLS");
	
	/*TAMPILAN PAPAN YANG AKAN DIISI INPUT PLAYER*/
	gotoxy(x,11);printf("     |     |\n");
	gotoxy(x,12);printf("  %c  |  %c  |  %c\n", gridChar(b[1]), gridChar(b[2]), gridChar(b[3]));
	gotoxy(x,13);printf("_____|_____|_____\n");
	gotoxy(x,14);printf("     |     |\n");
	gotoxy(x,15);printf("  %c  |  %c  |  %c\n",gridChar(b[4]), gridChar(b[5]), gridChar(b[6]));	
	gotoxy(x,16);printf("_____|_____|_____\n");
	gotoxy(x,17);printf("     |     |\n");
	gotoxy(x,18);printf("  %c  |  %c  |  %c\n",gridChar(b[7]), gridChar(b[8]), gridChar(b[9]));
	gotoxy(x,19);printf("     |     |\n");
	/*END TAMPILAN PAPAN YANG AKAN DIISI INPUT PLAYER*/
	
	
	/*TAMPILAN PAPAN MAP*/
	gotoxy(143,11);printf("|     |\n");
	gotoxy(138,12);printf("  1  |  2  |  3\n");
	gotoxy(138,13);printf("_____|_____|_____\n");
	gotoxy(143,14);printf("|     |\n");
	gotoxy(138,15);printf("  4  |  5  |  6\n");	
	gotoxy(138,16);printf("_____|_____|_____\n");
	gotoxy(143,17);printf("|     |\n");
	gotoxy(138,18);printf("  7  |  8  |  9\n");
	gotoxy(138,19);printf("     |     |\n");
	/*END TAMPILAN PAPAN MAP*/
}


void board5() {
//Author	: Irsyad Muhammad

//Procedure untuk menampilkan papan ukuran 5x5
//I.S	: Layar menampilkan pilihan sebelum modul board5
//F.S	: Ditampilkan papan dengan grid 5x5
	
	system("CLS");
	/*TAMPILAN PAPAN*/
	gotoxy(60,10);printf("|     |     |     |\n");
	gotoxy(55,11);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n"); //tempat penyimpanan bidak 1-5
	gotoxy(55,12);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,13);printf("|     |     |     |\n");
	gotoxy(55,14);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n");//tempat penyimpanan bidak 6-10
	gotoxy(55,15);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,16);printf("|     |     |     |\n");
	gotoxy(55,17);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n"); //tempat penyimpanan bidak 11-15
	gotoxy(55,18);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,19);printf("|     |     |     |\n");
	gotoxy(55,20);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n"); //tempat penyimpanan bidak 16-20
	gotoxy(55,21);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,22);printf("|     |     |     |\n");
	gotoxy(55,23);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n"); //tempat penyimpanan bidak 21-25
	gotoxy(60,24);printf("|     |     |     |\n");
	/*END TAMPILAN PAPAN*/
}


void CaraBermain() {
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan cara bermain dan aturan
//I.S	:Ditampilkan tampilan sebelum tampilan CaraBermain
//F.S	:Ditampilkan tampilan CaraBermain di layar

/*BEGIN PROCEDURE CARA_BERMAIN*/

	FILE*file;
	char length[6000];//variabel length adalah variabel lokal bertipe array of char untuk memberi batas char dari file yang dibuka
	
	file=fopen("CaraBermain.txt","r");
	
	while(fgets(length,6000,file)!=NULL){
		printf("%s", length);
	}
	
	fclose(file);
	gotoxy(65,47);printf("Tekan Tombol Untuk Kembali...\n");getch();
	//KEMBALI KE MENU UTAMA
	system("CLS");
	MenuUtama();
	
/*END PROCEDURE CARA_BERMAIN*/
}


void AboutUs() {
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan about us (credits permainan)
//I.S	:Ditampilkan tampilan sebelum tampilan about us
//F.S	:Ditampilkan tampilan about us di layar

/*BEGIN PROCEDUR ABOUTUS*/
	FILE *file;
	char length[6000];//variabel length adalah variabel lokal bertipe array of char untuk memberi batas char dari file yang dibuka
	
	file=fopen("AboutUs.txt","r");
	
	while (fgets(length,6000,file)!=NULL){
		printf("%s", length);
	}
	
	fclose(file);
	
	gotoxy(65,30);printf("Tekan Tombol Untuk Melanjutkan...\n");getch();
	//KEMBALI KE MENU UTAMA
	system("CLS");
	MenuUtama();
/*END PROCEDURE ABOUTUS*/

}


void timer(float persentase) {
//author:

//Modul untuk 
//I.S	:
//F.S	:

	clock_t endwait;
	endwait=clock()+persentase*CLOCKS_PER_SEC;
	while(clock()<endwait){};
	
}


void loading() {
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan loading
//I.S	: Ditampilkan tampilan modul ModulUtama
//F.s	: Ditampilkan tampilan loading
 
 /*BEGIN PROCEDURE LOADING*/
	int x;
	gotoxy(75,20); printf("Harap Tunggu..");

	for(x=65;x<=67;x++){
		gotoxy(x,22);printf("л\n");
		timer(0.5);
	}
	
	for(x=68;x<=75;x++){
		gotoxy(x,22);printf("л\n");
		timer(0.2);
	}
	
	for(x=76;x<=86;x++){
		gotoxy(x,22);printf("л\n");
		timer(0.02);
	}
	
	for(x=87;x<=97;x++){
		gotoxy(x,22);printf("л\n");
		timer(0.1);
	}
	
/*END PROCEDURE LOADING*/
}


void MenuUtama() {
//author	: Irsyad Muhammad

//Modul untuk menampilkan mneu utama dalam permainan
//I.S	: Ditampilkan tampilan layar sebelum modul MenuUtama
//F.S	: Ditampilkan tampilan menu utama yang menampilkan pilihan untuk bermain, petunjuk permainan, highscore, dan exit
	
	int PilihMenu;	//PilihMenu adalah variabel lokal bertipe int yang berfungsi sebagai pilihan dari case menu	yang tersedia
	Judul();
	
	gotoxy(70,20);printf("[1] PERMAINAN BARU\n");
	gotoxy(70,21);printf("[2] CARA & ATURAN BERMAIN\n");
	gotoxy(70,22);printf("[3] PAPAN PERINGKAT\n");
	gotoxy(70,23);printf("[4] CREDITS\n");
	gotoxy(70,24);printf("[0] KELUAR\n");
	gotoxy(70,26);printf("Masukkan Pilihan : \n");
	gotoxy(90,26);scanf("%d",&PilihMenu);

	switch(PilihMenu){
		case 1: 
			system("CLS");
			PilihLevel();
		break;
		
		case 2: 
			system("CLS");
			CaraBermain();
		break;
		
		case 3: 
			system("CLS");
		
		break;
		
		case 4: 
			system("CLS");
			AboutUs();
		break;
		
		case 0: 
			exit(1);
		break;
		
		default: 
			MenuUtama();
		break;
	}
}

int main() {
	fullscreen();
	MenuUtama();
}
