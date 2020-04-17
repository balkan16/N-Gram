/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020  
* MODUL 9 – TUGAS BESAR  
* Kelompok   		: B6  
* Hari dan Tanggal 	: Jumat, 17 April 2020  
* Asisten (NIM)  	: Ryan Dharma Chandra (13217018)  
* Nama File   		: output.c  
* Deskripsi   		: Mengeluarkan menu untuk pengguna dengan 5 pilihan
*/
void deskripsi()
{
	printf("=======================================");
	printf(" >>>>>>>WORDS GUESSING FROM WORDS N-GRAM<<<<<<< ");
	printf("=================================\n\n");
	printf(" Deskripsi Program: \n\n");
	printf(" Program akan memberikan keluaran berupa string acak yang didapat dari\n membuat n-gram dari inputan file eksternal yang berupa text.");
	printf("Input dari\n program ini akan berupa, file ekstenal berupa text, n yang berupa bi-\n langan dalam pengamabilan n kata dan N kata acak yang diambil dari kata\n yang terbentuk dari n-gram.");
	printf(" Program akan kembali meminta jumlah kata ran-\n dom setelah memberikan keluaran. Jika pengguna tidak ingin memberikan\n masukan, program akan beralih ke pemilihan file referensi.");
	printf("Jika pengguna\n tidak ingin mengganti file referensi, program akan berakhir.");
	printf("\n-----------------------------------------------------------------------------");
}


//menu pada program
void menu()
{
	
	char namafile[100];
	int input = 9,n=0,N=0;     //inisialisasi nilai input sebarang
	deskripsi();
	
	while(input != 0)
	{
	printf("\n\n Menu:\n ");
	printf("0. Exit\n ");
	printf("1. Memasukkan nama file\n ");
	printf("2. Memasukkan n dalam pengambilan n-gram\n ");
	printf("3. Memasukkan N buah kata acak yang ingin dicetak\n ");
	printf("4. Cetak Hasil\n");
	printf("Input:");
	scanf("%d", &input);

	
	
	
	if ((input < 0) || (input > 4))
        	printf("\nInputan Salah");
   	 else if (input == 1){	
   		 printf(" Masukkan nama file:");
   	 	scanf(" %[^\n]%*c",namafile);
   	 	printf(" %s", namafile);
	}
	else if (input == 2){
		printf(" Masukkan n pengambilan kata pada n-gram: ");
		scanf(" %d", &n);
		printf(" %d",n);
	}
	else if (input == 3){
		printf(" Masukkan N kata yang ingin dicetak: ");
		scanf(" %d",&N);
		printf(" %d",N);
	}
	else if(input==4){
		if((n==0)&&(N==0))
		{
			printf("Anda belum memasukkan 'n' dan 'N'\n ");
		}
		
		else
		{
    			printf("... string goes here ...\n");
		    //	display(x,N,n);
    			printf("... string goes here ...\n");
		}
		}

	}
	
	printf("program selesai\n");
}


//fungsi utama 
int main()
{
menu();
return 0;
} 

