/* -----------------------------------------------
Program 		:	Judul.c
Deskripsi		: 	Modul Tampilan judul permainan (CCC) + fullscreen
Author 			: 	Irsyad Muhammad (191524014)
Versi/tanggal	: 	21/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>


/*VARIABEL GLOBAL*/
char square[10]={'0','1','2','3','4','5','6','7','8','9'};
int Generate=1; //variabel global untuk menentukan kecerdasan komputer dan papan yang akan dipanggil


/*INISIALISASI MODUL*/
void gotoxy(int x, int y);
void MenuUtama();
void PilihPapan();
void board3();


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
//author	: 

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
        printf("Pilihlah Tanganmu : \n");
        printf("1. Gunting\n");
        printf("2. Batu\n");
        printf("3. Kertas\n");
        printf("Masukkan Pilihan : ");
        scanf("%d",&pemain); //menginput pilihan tangan user/player
        
		if(pemain>0 && pemain<4){
			if(musuh==0) //jika hasil acak = 0 berinisialiasi bahwa pilihan musuh adalah gunting
	        {
	            if(pemain==1) //jika pemain menginput 1 maka inisialiasinya pemain gunting
	            {
	                printf("\nGunting Lawan Gunting = Kau Seri \n\n");
	                seri++; //jika hasilnya seri maka variabel seri akan bertambah sebanyak 1
	                system("pause");
	                GuntingKertasBatu();
	            }
	            else if(pemain==2) //jika pemain menginput 1 maka inisialiasinya pemain batu
	            {
	                printf("\nGunting Lawan Batu = Kau Menang \n\n");
	                menang++; //jika hasilnya seri maka variabel menang akan bertambah sebanyak 1
	                system("pause");
	                
					switch(Generate){
						case 3: 
							Mudah3(1);
						
						case 5:
							Mudah5(1);
						
						case 6:
							Menengah3(1);
							
						case 10:
							Menengah5(1);
							
						case 9:
							Sulit3(1);
							
						case 15:
							Sulit5(1);
					}
	            }
	            else if(pemain==3) //jika pemain menginput 1 maka inisialiasinya pemain kertas
	            {
	                printf("\nGunting Lawan Kertas = Kau Kalah \n\n");
	                kalah++; //jika hasilnya seri maka variabel kalah akan bertambah sebanyak 1
	                system("pause");
					
					switch(Generate){
						case 3: 
							Mudah3(2);
						
						case 5:
							Mudah5(2);
						
						case 6:
							Menengah3(2);
							
						case 10:
							Menengah5(2);
							
						case 9:
							Sulit3(2);
							
						case 15:
							Sulit5(2);
					}
	            }
	        }
	        else if(musuh==1)
	        {
	            if(pemain==1) //jika pemain menginput 1 maka inisialiasinya pemain gunting
	            {
	                printf("\nBatu Lawan Gunting = Kau Kalah \n\n");
	                kalah++; //jika hasilnya seri maka variabel kalah akan bertambah sebanyak 1
	                system("pause");
	               
				   	switch(Generate){
						case 3: 
							Mudah3(2);
						
						case 5:
							Mudah5(2);
						
						case 6:
							Menengah3(2);
							
						case 10:
							Menengah5(2);
							
						case 9:
							Sulit3(2);
							
						case 15:
							Sulit5(2);
					}	                
	            }
	            else if(pemain==2) //jika pemain menginput 1 maka inisialiasinya pemain batu
	            {
	                printf("\nBatu Lawan Batu = Kau Seri \n\n");
	                seri++; //jika hasilnya seri maka variabel seri akan bertambah sebanyak 1
	                system("pause");
	                GuntingKertasBatu();
	            }
	            else if(pemain==3) //jika pemain menginput 1 maka inisialiasinya pemain kertas
	            {
	                printf("\nBatu Lawan Kertas = Kau Menang \n\n");
	                menang++; //jika hasilnya seri maka variabel menang akan bertambah sebanyak 1
	                system("pause");
					switch(Generate){
						case 3: 
							Mudah3(1);
						
						case 5:
							Mudah5(1);
						
						case 6:
							Menengah3(1);
							
						case 10:
							Menengah5(1);
							
						case 9:
							Sulit3(1);
							
						case 15:
							Sulit5(1);
					}
	            }
	        }
	        if(musuh==2)
	        {
	            if(pemain==1) //jika pemain menginput 1 maka inisialiasinya pemain gunting
	            {
	                printf("\nKertas Lawan Gunting = Kau Menang \n\n");
	                menang++; //jika hasilnya seri maka variabel menang akan bertambah sebanyak 1
	                system("pause");
	                
	                switch(Generate){
						case 3: 
							Mudah3(1);
						
						case 5:
							Mudah5(1);
						
						case 6:
							Menengah3(1);
							
						case 10:
							Menengah5(1);
							
						case 9:
							Sulit3(1);
							
						case 15:
							Sulit5(1);
					}
	            }
	            else if(pemain==2) //jika pemain menginput 1 maka inisialiasinya pemain batu
	            {
	                printf("\nKertas Lawan Batu = Kau Kalah \n\n");
	                kalah++; //jika hasilnya seri maka variabel kalah akan bertambah sebanyak 1
	                system("pause");
	                
            		switch(Generate){
						case 3: 
							Mudah3(2);
						
						case 5:
							Mudah5(2);
						
						case 6:
							Menengah3(2);
							
						case 10:
							Menengah5(2);
							
						case 9:
							Sulit3(2);
							
						case 15:
							Sulit5(2);
					}
	            }
	            else if(pemain==3) //jika pemain menginput 1 maka inisialiasinya pemain kertas
	            {
	                printf("\nKertas Lawan Kertas = Kau Seri \n\n");
	                seri++; //jika hasilnya seri maka variabel seri akan bertambah sebanyak 1
	                system("pause");
	                GuntingKertasBatu();
	            }
	        }
		}else{
			printf("Angka Anda Masukkan Tidak Valid\n");
			system("pause");
			GuntingKertasBatu();
		}
}


int CekMenang(){
//

//
//

	/*Cek horizontal*/
	
	if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    /*Cek Vertikal*/
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    /*Cek Diagonal*/
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
	else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9'){
    	return 2;
	}
	else{
		return 0;
	}
}

int LangkahKomputer(){
//	
	
//
//
    srand(time(0));
	char random;
	char value;
	random = "123456789" [rand() % 9];
	value = random;
	
	return value ;
}


int Mudah3(int GiliranMain){
// author	:

//
//
	unsigned turn;
	int pilihan, i,win;
	
	for(turn = 0; turn < 9 && win == 0; turn++){

		
		if((turn+GiliranMain) %2 == 0){
			/*computer turn*/
			for(i = 1; i<10; i++){
				if(LangkahKomputer() == square[i] && square[i] != 'O'){
					square[i]='X';
					break;
				}
				else if(LangkahKomputer() == square[i] && square[i] != 'O'){
					square[i]='X';
					break;
				}
			}
		}
		else{
			begin:
			board3();
			
			scanf("%d",&pilihan);
			if (pilihan == 1 && square[1] == '1')
				square[1]='O';
			
			else if(pilihan == 2 && square[2] == '2')
				square[2]='O';
			
			else if(pilihan == 3 && square[3] == '3')
				square[3]='O';
			
			else if(pilihan == 4 && square[4] == '4')
				square[4]='O';
			
			else if(pilihan == 5 && square[5] == '5')
				square[5]='O';
			
			else if(pilihan == 6 && square[6] == '6')
				square[6]='O';
			
			else if(pilihan == 7 && square[7] == '7')
				square[7]='O';
			
			else if(pilihan == 8 && square[8] == '8')
				square[8]='O';
			
			else if(pilihan == 9 && square[9] == '9')
				square[9]='O';
			
			else{
				printf("Langkah Tidak Valid\n");
				getch();
				goto begin;
			}
			win=CekMenang();
			board3();
		}
	}
	if (win == 1){
		printf("Kamu Menang!\n");
	}
	else if(win == 2){
		printf("Kamu Kalah\n");
	}
getch();
}

int Mudah5(int GiliranMain){
	exit(1);
}

int Menengah3(int GiliranMain){
	exit(1);
}

int Menengah5(int GiliranMain){
	exit(1);
}

int Sulit3(int GiliranMain){
	exit(1);
}


int Sulit5(int GiliranMain){
	exit(1);
}


void board3(){
//Author	: Irsyad Muhammad

//Procedure untuk menampilkan papan ukuran 3x3
//I.S	: Layar menampilkan pilihan sebelum modul board3
//F.S	: Ditampilkan papan dengan grid 3x3
	
	system("CLS");
	/*TAMPILAN PAPAN*/
	gotoxy(70,10);printf("|     |\n");
	gotoxy(65,11);printf("  %c  |  %c  |  %c\n", square[1],square[2],square[3]);
	gotoxy(65,12);printf("_____|_____|_____\n");
	gotoxy(70,13);printf("|     |\n");
	gotoxy(65,14);printf("  %c  |  %c  |  %c\n",square[4],square[5],square[6]);	
	gotoxy(65,15);printf("_____|_____|_____\n");
	gotoxy(70,16);printf("|     |\n");
	gotoxy(65,17);printf("  %c  |  %c  |  %c\n",square[7],square[8],square[9]);
	gotoxy(70,18);printf("|     |\n");
	/*END TAMPILAN PAPAN*/
}


void board5(){
//Author	: Irsyad Muhammad

//Procedure untuk menampilkan papan ukuran 5x5
//I.S	: Layar menampilkan pilihan sebelum modul board5
//F.S	: Ditampilkan papan dengan grid 5x5
		
	/*TAMPILAN PAPAN*/
	gotoxy(60,10);printf("|     |     |     |\n");
	gotoxy(60,11);printf("|     |     |     |\n"); //tempat penyimpanan bidak 1-5
	gotoxy(55,12);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,13);printf("|     |     |     |\n");
	gotoxy(60,14);printf("|     |     |     |\n"); //tempat penyimpanan bidak 6-10
	gotoxy(55,15);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,16);printf("|     |     |     |\n");
	gotoxy(60,17);printf("|     |     |     |\n"); //tempat penyimpanan bidak 11-15
	gotoxy(55,18);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,19);printf("|     |     |     |\n");
	gotoxy(60,20);printf("|     |     |     |\n"); //tempat penyimpanan bidak 16-20
	gotoxy(55,21);printf("_____|_____|_____|_____|_____\n");
	gotoxy(60,22);printf("|     |     |     |\n");
	gotoxy(60,23);printf("|     |     |     |\n"); //tempat penyimpanan bidak 21-25
	gotoxy(60,24);printf("|     |     |     |\n");
	/*END TAMPILAN PAPAN*/
}


void CaraBermain(){
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


void AboutUs(){
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


void timer(float persentase){
//author:

//Modul untuk 
//I.S	:
//F.S	:

	clock_t endwait;
	endwait=clock()+persentase*CLOCKS_PER_SEC;
	while(clock()<endwait){};
	
}


void loading(){
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


void MenuUtama(){
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
//			loading();
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

int main(){
	fullscreen();
	MenuUtama();
	
	
}
