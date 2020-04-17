#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct LUT {
	char *key;
    char value[20][100];
	struct LUT* go;
};

//asumsi ini variable global
struct LUT *start=NULL;

typedef struct node {
    char data[100]; 
    struct node *next;
}file_tubes;

void openfile(file_tubes *f, char *namafile);
void filedinamic(FILE *file, file_tubes *current, char *temp);
void printlist(file_tubes *f); 
void display(struct LUT *start,int N,int Ngram);

//fungsi open file
void openfile(file_tubes *f, char *namafile){
	file_tubes *current = f;
	char temp[5000];
	FILE *file;
	
	//open file
	file = fopen(namafile, "r");
	
	if (file == NULL) { //jika file tidak ada
		printf("error!! file tidak ditemukan!\n");
		current->data[0] = 0;
		current->next = NULL;
	}
	else {
		filedinamic(file, current, temp);
		fclose(file);
	}
}

//fungsi menyimpan isi file dalam dinamic array
void filedinamic(FILE *file, file_tubes *current, char *temp){
	int i, j=0, k, p, q;
	char temp2[5000];
	const char s[2] = " ";
	
	while (feof(file)==0){ //jika isi sudah dibaca semua
		fgets(temp,5000,file); //mengambil 1 baris (yg dipisahkan enter (\n)), asumsi maksimal 1 baris 5000 karakter
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
				if (k == 0){ //jika ada double \n atau pemisahan paragraf
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
			temp[i] = 0; //membersihkan isi temp jika sewaktu-waktu isi baris kosong tempnya juga kosong
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
}


void display(struct LUT *start,int N,int Ngram)
{
	struct LUT *ptrls;
	srand(time(0));
    struct LUT *current;
    int count;
    int k;

    int jumlahkata= Ngram;
	int modkata;
	int sisakata;

    //tempvalue digunakan untuk menyiman value dari key yang digunakan
    char *tempvalue;
    //tmpkey digunakan untuk menyimpan kata pertama dari key saat menggunakan strtok
    char tempkey[100];
    int nvalue;
    char *token;

	//menghitung banyaknya node yang ada
	ptrls = start;
		count =0;
		while(ptrls != NULL)
		{
			ptrls = ptrls->go;
			count++;
		}
		printf("\nCount \t:%d\n", count);

	current = start;

	//untuk mengakses key secara random
	k = rand()%count;
	int i=0;
	int j;

	//coval untuk menghitung value yang ada setiap node untuk random
	int coval;
	//menampilkan key pertama jika i sama dengan node yang di random
	printf("...");
    while (current!=NULL)
    {
    	if (i==k)
    	{
    		coval =0;
    		j=0;
    		printf("%s ", current->key);
    		//menghitung banyaknya value dalam satu node
    		while(strlen(current->value[j]) && (j<20))
    		{
    			coval++;
    			j++;
			}
			//mengambil vaue secara random
			nvalue = rand()%coval;
			tempvalue = current->value[nvalue];

		}
		else
		{
			current = current->go;
		}
		i++;
	}
    //mencari kata apabila jumlah kata yang diinginkan
	modkata = N%Ngram;
	sisakata = N-modkata;

    while ((jumlahkata<N))
    {
        //sisa kata jika Ngram bukan kelipatan dari jumlah kata yang ingin ditampilkan
    	if((current!=NULL)&&(jumlahkata == sisakata))
    	{
    		int m=0;
    		token = strtok((current->key), " ");
			while((current!=NULL) && (m<modkata))
			{
				printf("%s ", token);
				token = strtok(NULL, " ");
				m++;
			}
			jumlahkata+= modkata;
		}
    	else if ((current!=NULL))
    	{
    		strcpy(tempkey,"\0");
    		//mengambil kata pertama dari key
    		strcpy(tempkey,(current->key));
    		token = strtok(tempkey, " ");
    		//melakukan pengecekan antara value dengan kata pertama key
    		if (strcmp(tempvalue,token)==0)
    		{
    			printf("%s ", current->key);
    			coval =0;
    			j=0;
    			while(strlen(current->value[j]) && (j<20))
    			{
    				coval++;
    				j++;
				}
                    nvalue = rand()%coval;
                    tempvalue = current->value[nvalue];
                    jumlahkata += Ngram;
			}
			else
			{
				current = current->go;
			}
		}
		else
		{
            current = start;
		}
	}
	printf("...");
	return;
}
