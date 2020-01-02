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
int game; //variabel global untuk menentukan permainan sedang berada di ronde ke berapa / untuk membuat permainan berulang selama 10 kali
int menang = 0 , seri = 0, kalah = 0; //variabel global untuk menentukan status kemenangan pemain tiap putaran permainan

struct SaveScore{
		char NamaPemain[50];
		int skor;
	}data; 


/*INISIALISASI MODUL*/

void board3(int board[10]);
void board5(int board[26]);
void DisplayPemain3(int board[10]);
void DisplayPemain5(int board[26]);
void GetLevel();
void gotoxy(int x, int y);
void HitungSkor();
void MenuUtama();
void PilihPapan();
void PilihLevel();
void SimpanSkor(int skor);
void show();
/*===========================================================================================================================================
===========================================================================================================================================*/

void fullscreen(){
//author	: internet

//Modul untuk membuat console windows menjadi layar penuh
//I.S	: Console windows ditampilkan tidak dalam ukuran layar penuh
//F.S	: Console windows ditampilkan dalam ukuran layar penuh

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
	gotoxy(58,5); printf("������������\n");
	gotoxy(76,5); printf("������������\n");
	gotoxy(94,5); printf("������������\n");
	
	/*baris 2*/
	gotoxy(58,6); printf("������������\n");
	gotoxy(76,6); printf("������������\n");
	gotoxy(94,6); printf("������������\n");
	
	/*baris 3*/
	gotoxy(58,7); printf("�����\n");
	gotoxy(76,7); printf("�����\n");
	gotoxy(94,7); printf("�����\n");
	
	/*baris 4*/
	gotoxy(58,8); printf("�����\n");
	gotoxy(76,8); printf("�����\n");
	gotoxy(94,8); printf("�����\n");
	
	/*baris 5*/
	gotoxy(58,9); printf("�����\n");
	gotoxy(76,9); printf("�����\n");
	gotoxy(94,9); printf("�����\n");
	
	/*baris 6*/
	gotoxy(58,10); printf("�����\n");
	gotoxy(76,10); printf("�����\n");
	gotoxy(94,10); printf("�����\n");
		
	/*baris 7*/
	gotoxy(58,11); printf("������������\n");
	gotoxy(76,11); printf("������������\n");
	gotoxy(94,11); printf("������������\n");
	
	/*baris 8*/
	gotoxy(58,12); printf("������������\n");
	gotoxy(76,12); printf("������������\n");
	gotoxy(94,12); printf("������������\n");
	/*END TAMPILAN CCC*/
	
	/*TAMPILAN CIRCLE CROSS CHALLANGE*/
	gotoxy(70,15);printf("CIRCLE CROSS CHALLENGES\n\n");
	/*END TAMPILAN CIRCLE CROSS CHALLANGE*/
	
/*END PROCEDURE_JUDUL*/
}


void PilihLevel(){
//author	: Irsyad Muhammad

//Modul untuk menampilkan pilihan level yang tersedia
//I.S	: Ditampilkan tampilan layar modul MenuUtama
//F.S	: Ditampilkan tampilan menu yang menampilkan level yang tersedia

	int pilihlevel; //variabel lokal bertipe int yang berfungsi sebagai pilihan dari case menu yang tersedia
		
	system("CLS");
	
	gotoxy(70,18);printf("PILIH LEVEL");
	gotoxy(70,20);printf("[1] MUDAH\n");
	gotoxy(70,21);printf("[2] MENENGAH\n");
	gotoxy(70,22);printf("[3] SULIT\n");
	gotoxy(70,23);printf("[0] Menu Utama\n");
	gotoxy(70,25);printf("Masukkan Pilihan :\n");
	gotoxy(90,25);scanf("%d",&pilihlevel);
	menang = 0;
	seri = 0;
	kalah = 0;
	Generate = 1;
	
	
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
		
		default: 
			PilihLevel();
		break;
	}
}


void PilihPapan(){
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan pilihan papan yang tersedia
//I.S	: Ditampilkan tampilan modul PilihLevel
//F.S	: Ditampilkan tampilan pilihan papan yang tersedia yaitu papan 3x3 dan papan 5x5, serta pilihan kembali ke menu sebelumnya dan menu utama

	int pilihpapan; //pilihpapan adalah variabel lokal bertipe int yang berfungsi sebagai pilihan dari case menu yang tersedia

	system("CLS");
		
	gotoxy(70,18);printf("PILIH PAPAN");
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
		
		default: 
			PilihPapan();
		break;
	}
}


int GuntingKertasBatu(){
//author	: http://deriyuliansyah.blogspot.com/2014/04/game-gunting-batu-dan-kertas-bahasa-c.html

//Modul untuk menampilkan permainan gunting kertas batumemain
//		: 
//		: 

    srand(time(NULL)); //berguna untuk mengacak angka
    int pemain; //merupakan inisialisasi dari pilihan tangan player
    int musuh; //merupakan inisialisasi dari pilihan tangan musuh
    int menang=0; //merupakan inisialisasi dari banyak kemenangan, jumlahnya dimulai dari 0
    int seri=0; //merupakan inisialisasi dari banyak imbang, jumlahnya dimulai dari 0
    int kalah=0; //merupakan inisialisasi dari banyak kekalahan, jumlahnya dimulai dari 0
    int GiliranMain;
    char jawaban;
    system("CLS"); //berfungsi untuk clear screen atau membersihkan layar(mengosongkan layar)

        musuh = rand()%3; //inisialisasi dari pilihan musuh yang acak dari 0 hingga 2
        gotoxy(70,18);printf("PILIHLAH TANGANMU : \n");
        gotoxy(70,20);printf("[1] Gunting\n");
        gotoxy(70,21);printf("[2] Batu\n");
        gotoxy(70,22);printf("[3] Kertas\n");
        gotoxy(70,23);printf("Masukkan Pilihan : ");
        gotoxy(90,23);scanf("%d",&pemain); //menginput pilihan tangan user/player
        
		if(pemain>0 && pemain<4){
			if(musuh==0) //jika hasil acak = 0 berinisialiasi bahwa pilihan musuh adalah gunting
	        {
	            if(pemain==1) //jika pemain menginput 1 maka inisialiasinya pemain gunting
	            {
	                gotoxy(70,25);printf("Gunting Lawan Gunting (Seri)\n\n");
	                gotoxy(70,29);system("pause");
	                GuntingKertasBatu();
	            }
	            else if(pemain==2) //jika pemain menginput 1 maka inisialiasinya pemain batu
	            {
	                gotoxy(70,25);printf("Gunting Lawan Batu (Menang)\n\n");
	                gotoxy(70,27);printf("Kamu Main Pertama\n");
	                gotoxy(70,29);system("pause");
	                
	                GetLevel(1);
					
	            }
	            else if(pemain==3) //jika pemain menginput 1 maka inisialiasinya pemain kertas
	            {
	                gotoxy(70,25);printf("Gunting Lawan Kertas (Kalah)\n\n");
	                gotoxy(70,27);printf("Kamu Main Kedua\n");	                
	                gotoxy(70,29);system("pause");
					
					GetLevel(2);
	            }
	        }
	        else if(musuh==1)
	        {
	            if(pemain==1) //jika pemain menginput 1 maka inisialiasinya pemain gunting
	            {
	               	gotoxy(70,25);printf("Batu Lawan Gunting (Kalah)\n\n");
	                gotoxy(70,27);printf("Kamu Main Kedua\n");
	                gotoxy(70,29);system("pause");
	               
					GetLevel(2);	                
	            }
	            else if(pemain==2) //jika pemain menginput 1 maka inisialiasinya pemain batu
	            {
	                gotoxy(70,25);printf("Batu Lawan Batu (Seri)\n\n");
	                gotoxy(70,29);system("pause");
	                GuntingKertasBatu();
	            }
	            else if(pemain==3) //jika pemain menginput 1 maka inisialiasinya pemain kertas
	            {
	                gotoxy(70,25);printf("Batu Lawan Kertas (Menang)\n\n");
					gotoxy(70,27);printf("Kamu Main Pertama\n");
	                gotoxy(70,29);system("pause");
					
					GetLevel(1);
	            }
	        }
	        if(musuh==2)
	        {
	            if(pemain==1) //jika pemain menginput 1 maka inisialiasinya pemain gunting
	            {
	                gotoxy(70,25);printf("Kertas Lawan Gunting (Menang)\n\n");
	                gotoxy(70,27);printf("Kamu Main Pertama\n");
	                gotoxy(70,29);system("pause");
	                
	                GetLevel(1);
	            }
	            else if(pemain==2) //jika pemain menginput 1 maka inisialiasinya pemain batu
	            {
	                gotoxy(70,25);printf("Kertas Lawan Batu (Kalah)\n\n");
	                gotoxy(70,27);printf("Kamu Main Kedua\n");
	                gotoxy(70,29);system("pause");
	                
            		GetLevel(2);
		
	            }
	            else if(pemain==3) //jika pemain menginput 1 maka inisialiasinya pemain kertas
	            {
	                gotoxy(70,25);printf("Kertas Lawan Kertas (Seri)\n\n");
	                gotoxy(70,29);system("pause");
	                GuntingKertasBatu();
	            }
	        }
		}else{
			gotoxy(65,22);printf("Angka Anda Masukkan Tidak Valid\n");
			getch();
			GuntingKertasBatu();
		}
}

void GetLevel(int GiliranMain){
//author	: Hanifah Ghina Nabila

//GiliranMain	: parameter input bertipe integer dengan passing parameter passing by value
//GiliranMain	: berfungsi untuk menjadi parameter untuk modul setiap level di bawah ini.

	switch(Generate){
		case 3: 
			game = 1;
			do{
				Mudah3(GiliranMain);
				gotoxy(45,29);system("pause");
				game++;
			}while (game < 11);
		
		case 5:
			game = 1;
			do{
				Mudah5(GiliranMain);
				gotoxy(45,29);system("pause");
				game++;
			}while (game < 11);
			
		case 6:
			game = 1;
			do{
				Menengah3(GiliranMain);
				gotoxy(45,29);system("pause");
				game++;
			}while (game < 11);	
			
		case 10:
			game = 1;
			do{
				Menengah5(GiliranMain);
				gotoxy(45,29);system("pause");
				game++;
			}while (game < 11);
			
		case 9:
			game = 1;
			do{
				Sulit3(GiliranMain);
				gotoxy(45,29);system("pause");
				game++;
			}while (game < 11);	
			
		case 15:
			game = 1;
			do{
				Sulit5(GiliranMain);
				gotoxy(45,29);system("pause");
				game++;
			}while (game < 11);
	}
}


int CekMenang(const int board[10]){
//author	: Matthew Steel

//const int board[10] 	: parameter input bertipe const int dengan passing parameter passing by value
//parameter input memiliki fungsi memberi informasi isi array board[10] dalam modul setiap level (mudah, menengah, sulit)
	
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


int CekMenang5(const int board[26]){
//author	: Hanifah Ghina Nabila

//const int board[26] 	: parameter input bertipe const int dengan passing parameter passing by value
//parameter input memiliki fungsi memberi informasi isi array board[26] dalam modul setiap level (mudah, menengah, sulit)
	
	/*Deklarasi*/
//	unsigned wins[28][4]={{1,2,3,4},{2,3,4,5},{6,7,8,9},{7,8,9,10},{11,12,13,14},{12,13,14,15},{16,17,18,19},{17,18,19,20},{21,22,23,24},
//	{22,23,24,25},{1,6,11,16},{6,11,16,21},{2,7,12,17},{7,12,17,22},{3,8,13,18},{8,13,18,23},{4,9,14,19},{9,14,19,24},
//	{5,10,15,20},{10,15,20,25},{6,12,18,24},{1,7,13,19},{7,13,19,25},{2,8,14,20},{4,8,12,16},{5,9,13,17},{9,13,17,21},{10,14,18,22}};
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


int minimax(int board[10], int player) {
//author	: Github: Matthew Steel, 2009

// Modul untuk mencari kemungkinan pergerakan komputer yang memungkinkan dan baik untuk komputer menentukan pergerakan komputer dengan menelurusipergerakan komputer
//board[10]	: parameter input bertipe integer dengan passing parameter passing by value
//board[10]	: berfungsi untuk memberi informasi isi dari array board
//player	: parameter input bertipe integer dengan passing parameter passing by value
//player	: berfungsi untuk menerima angka -1 (angka player dalam board[10])


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


int minimax5(int board[26], int player) {
//author	: Github: Matthew Steel, 2009

// Modul untuk mencari kemungkinan pergerakan komputer yang memungkinkan dan baik untuk komputermenentukan pergerakan komputer dengan menelurusipergerakan komputer
//board[10]	: parameter input bertipe integer dengan passing parameter passing by value
//board[10]	: berfungsi untuk memberi informasi isi dari array board
//player	: parameter input bertipe integer dengan passing parameter passing by value
//player	: berfungsi untuk menerima angka -1 (angka player dalam board[10])

    //How is the position like for player (their turn) on board?
    int winner = CekMenang5(board);
    if(winner != 0) return winner*player;

    int move = -1;
    int score = -2;//Losing moves are preferred to no move
    int i;
    for(i = 1; i < 26; ++i) {//For all moves,
        if(board[i] == 0) {//If legal,
            board[i] = player;//Try the move
            int thisScore = -minimax5(board, player*-1);
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

//Modul untuk menentukan langkah yang akan diambil oleh komputer dalam permaianan level mudah papan 3x3
//int board[10]	: parameter input bertipe integer dengan passing parameter passing by value
//int board[10]	: berfungsi untuk memberikan informasi isi array board yang ada pada modul Mudah3
    
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


void LangkahKomputerMudah5(int board[26]){
//	author	: Hanifah Ghina Nabila
	
//Modul untuk menentukan langkah yang akan diambil oleh komputer dalam permaianan level mudah papan 5x5
//int board[26]	: parameter input bertipe integer dengan passing parameter passing by value
//int board[26]	: berfungsi untuk memberikan informasi isi array board yang ada pada modul Mudah5
    
    
	/*Deklarasi*/
	int i;
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


void LangkahKomputerSulit3(int board[10]){
//	author	: Github Matthew Steel
	
//Modul untuk menentukan langkah yang akan diambil oleh komputer dalam permaianan level sulit papan 3x3
//int board[10]	: parameter input bertipe integer dengan passing parameter passing by value
//int board[10]	: berfungsi untuk memberikan informasi isi array board yang ada pada modul Sulit3
    
    
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


void LangkahKomputerSulit5(int board[26]) {
//	author	: Irsyad Muhammad
	
//Modul untuk menentukan langkah yang akan diambil oleh komputer dalam permaianan level sulit papan 3x3
//int board[26]	: parameter input bertipe integer dengan passing parameter passing by value
//int board[26]	: berfungsi untuk memberikan informasi isi array board yang ada pada modul Sulit5
    
    
	/*Deklarasi*/
	int move = -1;
	int score = -2;
	int i;

	/*Proses*/
	for(i=1; i < 26; ++i) {
		
		if(board[i] == 0){
			board[i] = 1;
			int tempScore = -minimax5(board, -1);
			board[i] = 0;
			if (tempScore > score) {
				score = tempScore;
				move = i;	
			}
		}
	}
	
	board[move] = 1;
}


void DisplayPemain3(int board[10]){
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan permainan board 3x3
//Board adalah parameter input bertipe integer dengan passing paramaeter passing by value

//I.S	:Tampilan akan 
//F.S	: Pada layar ditampilkan tampilan berupa papan 3x3, ronde, map permainan, dan timer
	
	/*Deklarasi*/
	int y; //variabel untuk menentukan koordinat y
	
	/*Process*/
	switch(CekMenang(board)){
		case -1:
			++menang;
			break;

		case 1:
			++kalah;
			break;
	}
	
	/*TAMPILAN SAAT PERMAINAN MULAI*/
	board3(board);
	gotoxy(15,2);printf("�����������������������ͻ");
	gotoxy(39,3);printf("�");
	gotoxy(15,3);printf("� Ronde Ke :\t %d",game);
	gotoxy(15,4);printf("�����������������������ͼ");
	gotoxy(43,10);printf("Pemain ( O )        Komputer ( X )\n");
	gotoxy(145,10);printf("Map");
	gotoxy(143,25);printf("Status");
	gotoxy(135,27);printf("Menang	: %d", menang);
	gotoxy(135,29);printf("Seri	: %d", seri);
	gotoxy(135,31);printf("Kalah	: %d", kalah);
	
	
	for(y = 0; y < 48; y++){
		gotoxy(125,y);printf("�");
	}
}


void DisplayPemain5(int board[26]){
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan permainan board 3x3
//Board adalah parameter input bertipe integer dengan passing paramaeter passing by value

//I.S	:Tampilan akan 
//F.S	: Pada layar ditampilkan tampilan berupa papan 3x3, ronde, map permainan, dan timer
	
	/*Deklarasi*/
	int y; //variabel untuk menentukan koordinat y
	
	/*Process*/
	switch(CekMenang5(board)){
		case -1:
			menang++;
			break;
		case 0:
			seri++;
			break;
		case 1:
			kalah++;
			break;
	}
	
	/*TAMPILAN SAAT PERMAINANA MULAI*/
	board5(board);
	gotoxy(15,2);printf("�����������������������ͻ");
	gotoxy(39,3);printf("�");
	gotoxy(15,3);printf("� Ronde Ke :\t %d",game);
	gotoxy(15,4);printf("�����������������������ͼ");
	gotoxy(43,10);printf("Pemain ( O )        Komputer ( X )\n");
	gotoxy(145,10);printf("Map");
	
	
	for(y = 0; y < 48; y++){
		gotoxy(125,y);printf("�");
	}
}


void LangkahPemain3(int board[10]) {
// author	: Matthew Steel

//Modul untuk menerima input langkah pemain pada permainan papa 3x3
//int board[10]	: parameter input bertipe integer dengan passing parameter passing by value
//int board[10]	: berfungsi untuk memberikan informasi isi array board yang ada pada modul Mudah3
    

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


void LangkahPemain5(int board[26]) {
// author	: Hanifah Ghina Nabila

//Modul untuk menerima input dari pemain pada permainan papa 5x5
//int board[26]	: parameter input bertipe integer dengan passing parameter passing by value
//int board[26]	: berfungsi untuk memberikan informasi isi array board yang ada pada modul Mudah3
    

	/*Deklarsi*/
	int move = 0;
	
	
	/*Proses*/
	do{
		begin:
		
			DisplayPemain5(board);
		
			gotoxy(45,28);printf("Masukkan Pilihan :");
			gotoxy(65,28);scanf("%d", &move);
			
			if (board[move] != 0){
				gotoxy(45, 32);printf("Langkah Tidak Valid!\n");
				gotoxy(65, 32);getch();
				goto begin;
				printf("\n");
			}
	}while( move >= 26 || move < 1 && board[move] == 0);
	
	board[move] = -1;
}


int Mudah3(int GiliranMain){
// author	: Irsyad Muhammad

//Modul untuk memulai permaianan dengan level mudah papan 3x3
//GiliranMain : parameter input bertipe integer dengan passing parameter passing by value
//GiliranMain berfungsi untuk menentukan urutan main dalam permainan


	/*Deklarasi*/
	int board[10] = {0,0,0,0,0,0,0,0,0,0};
	
	unsigned turn;
	
	int pilihan;
	
	/*Proses*/		
	for(turn = 0; turn < 9 && CekMenang(board) == 0; ++turn){

				
		if((turn + GiliranMain) % 2 == 0) {
			LangkahKomputerMudah3(board);
		}
		else {
			LangkahPemain3(board);
		}
	}
	
	switch(CekMenang(board)) {
		case 0:
			++seri;
			DisplayPemain3(board);
			gotoxy(55,27);printf("Permainan Imbang!\n");
			if (game == 10){
				gotoxy(45,29);system("pause");
				system("CLS");
				HitungSkor();
				MenuUtama();
			}
			break;
		
		case 1:
			DisplayPemain3(board);
			gotoxy(55,27);printf("Kamu Kalah :(\n");
			if (game == 10){
				gotoxy(45,29);system("pause");
				system("CLS");
				HitungSkor();
				MenuUtama();
			}
			break;
			
		case -1:
			DisplayPemain3(board);
			gotoxy(55,27);printf("Kamu Menang!!\n");
			if (game == 10){
				gotoxy(45,29);system("pause");
				system("CLS");
				/*Panggil modul score*/
				HitungSkor();
				MenuUtama();
			}
			break;
	}
}


int Mudah5(int GiliranMain){
// author	: Hanifah Ghina Nabila

//Modul untuk memulai permaianan dengan level mudah papan 5x5
//GiliranMain : parameter input bertipe integer dengan passing parameter passing by value
//GiliranMain berfungsi untuk menentukan urutan main dalam permainan
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
			if (game == 10){
				system("CLS");
				/*Panggil modul score*/
				HitungSkor();
			}
			break;
		
		case 1:
			DisplayPemain5(board);
			gotoxy(45,27);printf("Kamu Kalah :(\n");
			if (game == 10){
				system("CLS");
				/*Panggil modul score*/
				HitungSkor();
			}
			break;
			
		case -1:
			DisplayPemain5(board);
			gotoxy(45,27);printf("Kamu Menang!!\n");
			if (game == 10){
				system("CLS");
				/*Panggil modul score*/
				HitungSkor();
			}
			break;
	}
}


int Menengah3(int GiliranMain){
// author	: Irsyad Muhammad

//Modul untuk memulai permaianan dengan level menengah papan 3x3
//GiliranMain : parameter input bertipe integer dengan passing parameter passing by value
//GiliranMain berfungsi untuk menentukan urutan main dalam permainan


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
			++seri;
			DisplayPemain3(board);
			gotoxy(55,27);printf("Permainan Imbang!\n");
			if (game == 10){
				gotoxy(45,29);system("pause");
				system("CLS");
				HitungSkor();
				MenuUtama();
			}
			break;
		
		case 1:
			DisplayPemain3(board);
			gotoxy(55,27);printf("Kamu Kalah :(\n");
			if (game == 10){
				gotoxy(45,29);system("pause");
				system("CLS");
				HitungSkor();
				MenuUtama();
			}
			break;
			
		case -1:
			DisplayPemain3(board);
			gotoxy(55,27);printf("Kamu Menang!!\n");
			if (game == 10){
				gotoxy(45,29);system("pause");
				system("CLS");
				HitungSkor();
				MenuUtama();
			}
			break;
	}
}


int Menengah5(int GiliranMain){
//author	:

//Modul untuk memulai permaianan dengan level menengah papan 5x5
//GiliranMain : parameter input bertipe integer dengan passing parameter passing by value
//GiliranMain berfungsi untuk menentukan urutan main dalam permainan


	exit(1);
}


int Sulit3(int GiliranMain){
// author	: Matthew Steel 

//Modul untuk memulai permaianan dengan level sulit papan 3x3
//GiliranMain : parameter input bertipe integer dengan passing parameter passing by value
//GiliranMain berfungsi untuk menentukan urutan main dalam permainan

	/*Deklarasi*/
	int board[10] = {0,0,0,0,0,0,0,0,0,0};
	
	unsigned turn;
	
	int pilihan;
	
	
	/*Proses*/
	
	
	for(turn = 0; turn < 9 && CekMenang(board) == 0; ++turn){

		
		if((turn + GiliranMain) % 2 == 0) {
			LangkahKomputerSulit3(board);
		}
		else {
			LangkahPemain3(board);
		}
	}
	
	switch(CekMenang(board)) {
		case 0:
			++seri;
			DisplayPemain3(board);
			gotoxy(45,27);printf("Permainan Imbang!\n");
			if (game == 10){
				gotoxy(45,29);system("pause");
				system("CLS");
				HitungSkor();
				MenuUtama();
				
			}
			break;
		
		case 1:
			DisplayPemain3(board);
			gotoxy(55,27);printf("Kamu Kalah :(\n");
			if (game == 10){
				gotoxy(45,29);system("pause");
				system("CLS");
				HitungSkor();
				MenuUtama();
			}
			break;
			
		case -1:
			DisplayPemain3(board);
			gotoxy(45,27);printf("Kamu Menang!!\n");
			if (game == 10){
				gotoxy(45,29);system("pause");
				system("CLS");
				HitungSkor();
				MenuUtama();
			}
			break;
	}
}


int Sulit5(int GiliranMain){
// author	: Irsyad Muhammad

//
//
	/*Deklarasi*/
	int board[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	
	unsigned turn;
	
	int pilihan;
	
	/*Proses*/		
	for(turn = 0; turn < 25 && CekMenang5(board) == 0; ++turn){

				
		if((turn + GiliranMain) % 2 == 0) {
			LangkahKomputerSulit5(board);
		}
		else {
			LangkahPemain5(board);
		}
	}
	
	switch(CekMenang5(board)) {
		case 0:
			DisplayPemain5(board);
			gotoxy(45,27);printf("Permainan Imbang!\n");
			if (game == 10){
				system("CLS");
				/*Panggil modul score*/
				HitungSkor();
				MenuUtama();
			}
			break;
		
		case 1:
			DisplayPemain5(board);
			gotoxy(45,27);printf("Kamu Kalah :(\n");
			if (game == 10){
				system("CLS");
				/*Panggil modul score*/
				HitungSkor();
				MenuUtama();
			}
			break;
			
		case -1:
			DisplayPemain5(board);
			gotoxy(45,27);printf("Kamu Menang!!\n");
			if (game == 10){
				system("CLS");
				/*Panggil modul score*/
				HitungSkor();
				MenuUtama();
			}
			break;
	}
}

void HitungSkor(){
//author	: Hanifah Ghina Nabila

//Modul untuk menghitung skor selama permainan
//I.S	:
//F.S	:

	int SkorTotal, SkorMenang, SkorSeri;
	
	switch(Generate){
		case 3:
			SkorMenang = menang*1000;
			SkorSeri = seri*500;
			SkorTotal = SkorMenang + SkorSeri;
			break;
		case 5:
		case 6:
			SkorMenang = menang*3000;
			SkorSeri = seri*1500;
			SkorTotal = SkorMenang + SkorSeri;
			break;
		case 10:
		case 9:
			SkorMenang = menang*7000;
			SkorSeri = seri*3500;
			SkorTotal = SkorMenang + SkorSeri;
			break;
	}
	
	gotoxy(70,22);printf("Skor kamu : %d", SkorTotal);

	SimpanSkor(SkorTotal);

}

void SimpanSkor(int skor){
//author	: Hanifah Ghina Nabila

//Modul untuk menginput nama pemain dan menyimpan nama pemain beserta skor ke dalam file DataSkorCCC.dat
//int skor	: parameter input bertipe integer dengan passing parameter passing by value
//int skor 	: berfungsi menginput skorTotal dari modul hitungskor ke dalam struct data 
	
	struct data; 
	FILE *DataSkor;
	
	DataSkor = fopen("DataSkorCCC.dat", "rb");
	data.skor = skor;
	gotoxy(60,24);printf("Masukkan nama kamu : ");
	scanf("%s\n", &data.NamaPemain);

	fclose(DataSkor);
	
}


void show(){
//author	: Hanifah Ghina Nabila

//Modul untuk menampilkan score yang sudah disimpan di dalam file.
//I.S	: Ditampilkan tampilan MenuUtama
//F.S	: Ditampilkan tampilan berupa nama dan skor yang dimiliki
   
    FILE *tampil;
    struct data;
    
    tampil = fopen("DataSkorCCC.dat", "rb");
    
    while (!feof(tampil)) {
        fscanf(tampil, "%s %d\n", &data.NamaPemain, &data.skor);
        gotoxy(70,2);printf("Papan Peringkat\n");
        gotoxy(70,5);printf("%s - %d\n\n", data.NamaPemain, data.skor);
    }
    
	gotoxy(65,25);system("pause");
    MenuUtama();
}


char gridChar(int i){
//author	: Github : Matthew Steel

//Modul untuk menampilkan simbol di dalam papan
//int i 	: parameter input bertipe integer dengan passing parameter passing by value.
//int i		: berfungsi untuk mengisi switch 
	
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
	gotoxy(x,15);printf("     |     |\n");
	gotoxy(x,16);printf("  %c  |  %c  |  %c\n", gridChar(b[1]), gridChar(b[2]), gridChar(b[3]));
	gotoxy(x,17);printf("_____|_____|_____\n");
	gotoxy(x,18);printf("     |     |\n");
	gotoxy(x,19);printf("  %c  |  %c  |  %c\n",gridChar(b[4]), gridChar(b[5]), gridChar(b[6]));	
	gotoxy(x,20);printf("_____|_____|_____\n");
	gotoxy(x,21);printf("     |     |\n");
	gotoxy(x,22);printf("  %c  |  %c  |  %c\n",gridChar(b[7]), gridChar(b[8]), gridChar(b[9]));
	gotoxy(x,23);printf("     |     |\n");
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


void board5(int b[26]) {
//Author	: Irsyad Muhammad

//Procedure untuk menampilkan papan ukuran 5x5
//I.S	: Layar menampilkan pilihan sebelum modul board5
//F.S	: Ditampilkan papan dengan grid 5x5
	
	system("CLS");
	/*TAMPILAN PAPAN*/
	gotoxy(60,10);printf("|     |     |     |\n");
	gotoxy(55,11);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n", gridChar(b[1]), gridChar(b[2]), gridChar(b[3]), gridChar(b[4]), gridChar(b[5])); //tempat penyimpanan bidak 1-5
	gotoxy(55,12);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,13);printf("|     |     |     |\n");
	gotoxy(55,14);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n", gridChar(b[6]), gridChar(b[7]), gridChar(b[8]), gridChar(b[9]), gridChar(b[10]));//tempat penyimpanan bidak 6-10
	gotoxy(55,15);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,16);printf("|     |     |     |\n");
	gotoxy(55,17);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n", gridChar(b[11]), gridChar(b[12]), gridChar(b[13]), gridChar(b[14]), gridChar(b[15])); //tempat penyimpanan bidak 11-15
	gotoxy(55,18);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,19);printf("|     |     |     |\n");
	gotoxy(55,20);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n", gridChar(b[16]), gridChar(b[17]), gridChar(b[18]), gridChar(b[19]), gridChar(b[20])); //tempat penyimpanan bidak 16-20
	gotoxy(55,21);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,22);printf("|     |     |     |\n");
	gotoxy(55,23);printf("  %c  |  %c  |  %c  |  %c  |  %c  \n", gridChar(b[21]), gridChar(b[22]), gridChar(b[23]), gridChar(b[24]), gridChar(b[25])); //tempat penyimpanan bidak 21-25
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

//Modul untuk mengatur kecepatan printf() pada modul loading()

	clock_t endwait;
	endwait=clock()+persentase*CLOCKS_PER_SEC;
	while(clock()<endwait){};
	
}


void loading() {
//author	: Irsyad Muhammad

//Modul untuk menampilkan tampilan loading
//I.S	: Ditampilkan tampilan modul PilihPapan/GuntingKertasBatu
//F.s	: Ditampilkan tampilan modul GuntingKertasBatu/level yang tersedia(Mudah3,Mudah5,Menengah3,Menengah5,Sulit3, dan Sulit5)
 
 /*BEGIN PROCEDURE LOADING*/
	int x;
	gotoxy(75,20); printf("Harap Tunggu..");

	for(x=65;x<=67;x++){
		gotoxy(x,22);printf("�\n");
		timer(0.5);
	}
	
	for(x=68;x<=75;x++){
		gotoxy(x,22);printf("�\n");
		timer(0.1);
	}
	
	for(x=76;x<=86;x++){
		gotoxy(x,22);printf("�\n");
		timer(0.02);
	}
	
	for(x=87;x<=97;x++){
		gotoxy(x,22);printf("�\n");
		timer(0.1);
	}
	
/*END PROCEDURE LOADING*/
}


void MenuUtama() {
//author	: Irsyad Muhammad

//Modul untuk menampilkan mneu utama dalam permainan
//I.S	: Ditampilkan tampilan layar sebelum modul MenuUtama
//F.S	: Ditampilkan tampilan menu utama yang menampilkan pilihan untuk bermain, petunjuk permainan, highscore, dan exit
	
	int pilihmenu;	//PilihMenu adalah variabel lokal bertipe int yang berfungsi sebagai pilihan dari case menu	yang tersedia
	
	
	system("CLS");
	Judul();
	
	gotoxy(70,20);printf("[1] PERMAINAN BARU\n");
	gotoxy(70,21);printf("[2] CARA & ATURAN BERMAIN\n");
	gotoxy(70,22);printf("[3] PAPAN PERINGKAT\n");
	gotoxy(70,23);printf("[4] CREDITS\n");
	gotoxy(70,24);printf("[0] KELUAR\n");
	gotoxy(70,26);printf("Masukkan Pilihan : \n");
	gotoxy(90,26);scanf("%d",&pilihmenu);

	switch(pilihmenu){
		case 1: 
			PilihLevel();
		break;
		
		case 2: 
			system("CLS");
			CaraBermain();
		break;
		
		case 3: 
			system("CLS");
			show();
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
