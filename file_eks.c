#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//linked list yang memisahkan satu kata dengan kata yang lain dalam file menggantikan spasi
typedef struct node {
    char data[100]; //asumsi satu kata maksimal 100 karakter
    struct node *next;
}file_tubes;

//fungsi-fungsi yg dipakai
void inputfile(file_tubes *f);
void filedinamic(FILE *file, file_tubes *current, char temp[100]);
void printlist(file_tubes *f);

//program utama
int main(){
	
	//yg program file_eks butuhkan (nama bisa dirubah)
	/*
	* file_tubes *f;
	* f =(file_tubes*) malloc(sizeof(file_tubes));
    * inputfile(f);
    */
    
	//printlist(f); // buat ngecek doang
	return 0;
}

//fungsi input file
void inputfile(file_tubes *f){
	file_tubes *current = f;
	char temp[150];
	FILE *file;
	
	//input nama file
	printf("masukkan nama file referensi : ");
	scanf("%s", temp);
	file = fopen(temp, "r");
	
	if (file == NULL) { //jika file tidak ada
		printf("error!! file tidak ditemukan!\n");
		strcpy(current->data, " ");
		current->next = NULL;
	}
	else {
		filedinamic(file, current, temp);
		fclose(file);
	}
}

//fungsi menyimpan isi file dalam dinamic array
void filedinamic(FILE *file, file_tubes *current, char temp[100]){
	int i, j=0, k, p, q;
	char temp2[150];
	const char s[2] = " ";
	
	while (feof(file)==0){ //jika isi sudah dibaca semua
		fgets(temp,150,file); //mengambil 1 baris (yg dipisahkan enter (\n)), asumsi maksimal 1 baris 150 karakter
		j = strlen(temp); //panjang 1 baris yang diambil
		k = 0; p = 0; q = 0;
		
		for (i=0;i<j;i++){
			if (temp[i] == '\t'){ //jika ada tab diubah menjadi spasi
				temp[i] = ' ';
			}
		}
		
		for (i=0;i<j;i++){
			if (temp[i] == ' '){ //jika ada k spasi, asumsi jumlah kata adalah k+1
				if (i!=0 && temp[i+1] != '\n' && temp[i+1] != ' ' && q == 1){ //jika ada spasi double/ diawal/ diakhir
					k++;
				}
			}
			else if (temp[i] == '\n'){
				temp[i] = 0;
				if (i == 0){ //jika ada double \n atau pemisahan paragraf
					p = 1;
				}
			}
			else { //untuk menemukan karakter pertama yg bukan spasi
				q = 1;
			}
		}
		
		if (feof(file) != 0 && temp[0] == 0){ //jika di akhir teks terdapat baris kosong
			p = 1;
		}
		
		if (p==0){
			strcpy(temp2, strtok(temp,s)); //mengambil 1 kata dr temp yg dipisahkan oleh spasi (s)
			strcpy(current->data, temp2); //memasukan data ke dalam dinamic array
			current->next = NULL;
			i = 0;
			while (i < k){ //k = jumlah spasi = jumlah kata - 1
				current->next =(file_tubes*) malloc(sizeof(file_tubes));
				strcpy(temp2, strtok(NULL,s)); //mengambil 1 kata dr temp (sebelumnya) yg dipisahkan oleh spasi (s)
				strcpy(current->next->data, temp2); //memasukan data ke dalam dinamic array
				current = current->next;
				current->next = NULL;
				i++;
			}
			if (feof(file)==0){ //jika file blm dibaca semua
				//inisiasi untuk menyambung kan dengan kata pertama di baris selnjutnya
				current->next =(file_tubes*) malloc(sizeof(file_tubes));
				current = current->next;
				current->next = NULL;
			}
		}
		
		for (i=0;i<j;i++){ 
			temp[i] = 0; //membersihkan isi temp aga jika sewaktu-waktu isi baris kosong tempnya juga kosong
		}
	}
}

//fungsi pengecekan isi linked list
void printlist(file_tubes *f){
    file_tubes *current=f;

    while(current != NULL && current->data[0] != 0){ //sampai data terbaca semua atau data terakhir adalah data kosong yg diakibatkan pengolahan sebelumnya
        printf("%s\n", current->data);
        current=current->next;
    }
    printf("done");
}
