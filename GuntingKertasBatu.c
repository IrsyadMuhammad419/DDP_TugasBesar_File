/* -----------------------------------------------
Program 		:	Mudah3.c
Deskripsi		: 	Modul untuk memulai permainan level easy papan 3x3
Author 			: 	Irsyad Muhammad (191524014)
Versi/tanggal	: 	2.0 / 29/12/2019 
Compiler 		:	TDM-GCC 4.9.6.2 64-bit release
---------------------------------------------------*/


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
