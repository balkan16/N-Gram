#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "file_eks2.h"

//Judul dan deskripsi program
void deskripsi()
{
	printf("=======================================");
	printf(" >>>>>>>RANDOM STRINGS FROM WORDS N-GRAM<<<<<<< ");
	printf("=================================\n\n");
	printf(" Deskripsi Program: \n\n");
	printf(" Program akan memberikan keluaran berupa string acak yang didapat dari\n membuat n-gram dari inputan file eksternal yang berupa text. Lalu memilih\n kata selanjutnya dari value yang terbentuk.");
	printf("Input dari program ini akan berupa,\n file ekstenal berupa text, n yang berupa bilangan dalam pengamabilan n kata\n dan N kata yang diambil dari kata yang terbentuk dari n-gram.");
	printf(" Pengguna dapat\n memberikan masukan jumlah kata setelah program memberikan keluaran. Jika\n pengguna tidak ingin memberikan masukan, pengguna dapat mengganti file referensi.");
	printf("\n Jika pengguna tidak ingin mengganti file referensi, program akan berakhir.");
	printf("\n-----------------------------------------------------------------------------");
}


//menu pada program
void menu()
{
	file_tubes *f;
	f =(file_tubes*) malloc(sizeof(file_tubes));
	char namafile[100];
	int input = 9,n,N;     //inisialisasi nilai input sebarang
	deskripsi();
	
	while(input != 0)
	{
	printf("\n\n Menu:\n ");
	printf("0. Exit\n ");
	printf("1. Memasukkan nama file\n ");
	printf("2. Memasukkan n dalam pengambilan n-gram\n ");
	printf("3. Memasukkan N buah kata acak yang ingin dicetak\n ");
	printf("Input:");
	scanf("%d", &input);

	
	
	
	if ((input < 0) || (input > 3))
        printf("\nInputan Salah");
    else if (input == 1){	
    printf(" Masukkan nama file:");
    scanf(" %[^\n]%*c",namafile);
    printf(" %s", namafile);
	openfile(f, namafile);
   

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
	else
    	printf(" program selesai");
    	printlist(f);
	}

			
}


//fungsi utama 
int main()
{

menu();
return 0;
} 
