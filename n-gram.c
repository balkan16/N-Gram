#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node { 
	char *key;
    char value[20][100];
	struct node* go; 
}; 

//asumsi ini nnti hasil dri file eksternal, ilangin aja klo udh disatuin dan disesuain
struct kalimat {
    char isi[100];
    struct kalimat* next;
}

// reminder
// kalo ada salah2 syntax yang di bagian yang bisa diganti pake fungsi dri string.h ganti2 aja

void n-gram(int n, kalimat *temp){ // parameter nya cek dulu takutnya salah, soalnya ku rasa2nya kaya bikin main
                // kalimat tergantung nama struct nya tegar
                // jangan sampe namanya ada yang sama pas disatuin
    //deklarasi
    struct node* tabel = (struct node*)malloc(sizeof(struct node));
    // untuk looping utama
    struct kalimat* head = (struct kalimat*)malloc(sizeof(struct kalimat));
    // agar setelah looping bisa mulai dari kata setelahnya 
    struct kalimat* body = (struct kalimat*)malloc(sizeof(struct kalimat));
    // untuk looping cek value
    struct kalimat* tail = (struct kalimat*)malloc(sizeof(struct kalimat));
    int i = 0;
    int j = 0;
    char temp_k = malloc((n*100)*sizeof(char));
    char temp_v = malloc(100*sizeof(char));
    // langsung di looping sampe end buat masukin key
    while(head->next != NULL){
        body = head->next;
        // looping tiap n
        while(i<n){
            // satuin stringnya masukin temp_k
            if (i == 0){
                temp_k = strcat(temp_k,head->isi);
            } else if ((i >= 0) && (i <= n - 1)){
                // biar ada spasinya antar kata yang disatuin jadi key nya
                temp_k = strcat(temp_k, " ");
                temp_k = strcat(temp_k,head->isi);
            }
            //kalo udh selesai
            tail = head->next;
            if (i == n-1){
                //cek value nya pake tail
                if (tail != NULL){
                    // itung lengthnya biar bisa di definisiin key nya
                    tabel->key = malloc((strlen(temp_k))*sizeof(char));
                    // cek temp_k nya ada yang sama ga kaya sebelumnya
                    strcpy(temp_v,tail->isi);
                    if (tabel->key != "\0"){
                        while(tabel->key != "\0"){
                            if(strcmp(temp_k,tabel->key) == 0){
                                // klo ada yg ini gausah dimasukin key tpi value nya aja
                                while(tabel->value[j] != "\0"){
                                    j++;
                                }
                                strcpy(tabel->value[j],temp_v);
                            }
                            tabel = tabel->go;
                        }
                    } else {
                        // masukin key nya
                        strcpy(tabel->key,temp_k);
                        // masukin value nya, value[j]=value 
                        strcpy(tabel->value[j],temp_v);
                    }
                    j = 0;
                }
            }
            // for looping purposes
            i++;
            head = head->next;
        }
        // biar ke bagi per key
        i = 0;
        // ilangin awalnya
        // mulai laginya dari setelah awalnya
        head = body;
    }
}


main(){
    // ini harusnya udah ada di menu
        // masukin input dari file eksternal   
        // masukan jumlah n pada n gram


    // fungsi n gram (n , string input) 

    return(0);
}