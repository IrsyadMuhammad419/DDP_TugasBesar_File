/* -----------------------------------------------
Program 		:	Mudah3.c
Deskripsi		: 	Modul untuk memulai permainan level easy papan 3x3
Author 			: 	http://deriyuliansyah.blogspot.com/2014/04/game-gunting-batu-dan-kertas-bahasa-c.html
Versi/tanggal	: 	2.0 / 29/12/2019 Updated (30/12/2019)
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/

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
							do{
								Mudah5(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
							
						case 6:
							do{
								Menengah3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 10:
							do{
								Menengah5(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
							
						case 9:
							do{
								Sulit3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 15:
							do{
								Sulit5(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
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
							do{
								Mudah5(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
							
						case 6:
							do{
								Menengah3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 10:
							do{
								Menengah5(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
							
						case 9:
							do{
								Sulit3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
						
						case 15:
							do{
							Sulit5(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
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
							do{
								Mudah5(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
						
						case 6:
							do{
								Menengah3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 10:
							do{
								Menengah5(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
								
						case 9:
							do{
								Sulit3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 15:
							do{
								Sulit5(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
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
							do{
								Mudah5(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
							
						case 6:
							do{
								Menengah3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 10:
							do{
								Menengah5(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
							
						case 9:
							do{
								Sulit3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 15:
							do{
								Sulit5(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
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
							do{
								Mudah5(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
							
						case 6:
							do{
								Menengah3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 10:
							do{
								Menengah5(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
							
						case 9:
							do{
								Sulit3(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 15:
							do{
								Sulit5(1);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
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
							do{
								Mudah5(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);
							
						case 6:
							do{
								Menengah3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 10:
							do{
								Menengah5(2);	
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
								
						case 9:
							do{
								Sulit3(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
							
						case 15:
							do{	
								Sulit5(2);
								gotoxy(45,29);system("pause");
								game++;
							}while (game < 11);	
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
