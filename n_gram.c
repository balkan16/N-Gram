#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct LUT {
    char *key;
    char value[20][100];
    struct LUT* go;
};

typedef struct node {
    char data[100];
    struct node *next;
}file_tubes;

void push(char data[100], file_tubes** stack){
    file_tubes* Element = (file_tubes*)malloc(sizeof(file_tubes));
    strcpy(Element->data , data);
    Element->next = (*stack);
    (*stack) = Element;
}

void pop(file_tubes* stack){
    if(stack != NULL){
        file_tubes* tempPtr = stack;
        *stack = *(stack)->next;
        free(tempPtr);
    }
}

// fungsi untuk cek tabel pada saat debugging
void printtabel(struct LUT* stack){
    int j=0;
    while ( stack != NULL) {
        printf("%s", stack->key);
        while(strcmp(stack->value[j],"\0") != 0){
            printf("%s", stack->value[j]);
            j++;
        }
        stack = stack->go;
    }
}

//fungsi untuk memasukan value ketika key nya sama
void masukvalue(struct LUT** stack,char v[100],int j){
    struct LUT* Element = (struct LUT*)malloc(sizeof(struct LUT));
    strcpy(Element->value[j], v);
    Element->go = (*stack);
    (*stack) = Element;

}

// fungsi untuk memasukan key dan value secara bersamaan
void masukall(struct LUT** stack,char k[100],char v[100]){
    struct LUT* Element = (struct LUT*)malloc(sizeof(struct LUT));
    strcpy(Element->key , k);
    strcpy(Element->value[0], v);
    Element->go = (*stack);
    (*stack) = Element;
}

void n_gram(int n, file_tubes* head){ 
    // untuk looping utama pakai head
    // agar setelah looping bisa mulai dari kata setelahnya
    file_tubes* body = (file_tubes*)malloc(sizeof(file_tubes));
    // untuk looping cek value
    file_tubes* tail = (file_tubes*)malloc(sizeof(file_tubes));
    // untuk menyimpan hasil
    struct LUT* tabel = (struct LUT*)malloc(sizeof(struct LUT));
    int i = 0;
    int j = 0;
    char isi[100];

    char* temp_k = (char*)malloc((n*100)*sizeof(char));
    char* temp_v = (char*)malloc(100*sizeof(char));

    // langsung di looping sampe end buat masukin key
    while(head->data[0] != 0){
        body = head;
        // looping tiap n
        while(i<n){
            // satuin stringnya masukin temp_k
            if (i == 0){
                temp_k = strcat(temp_k,head->data);
            } else if ((i > 0) && (i <= n - 1)){
                // biar ada spasinya antar kata yang disatuin jadi key nya
                temp_k = strcat(temp_k, " ");
                temp_k = strcat(temp_k,head->data);
            }
            //kalo udh selesai
            tail = head->next;
            if (i == n-1){
                //cek value nya pake tail
                if (tail != NULL){
                    // itung lengthnya biar bisa di definisiin key nya
                    tabel->key = malloc((strlen(temp_k))*sizeof(char));
                    // cek temp_k nya ada yang sama ga kaya sebelumnya
                    strcpy(temp_v,tail->data);
                    if (strcmp(tabel->key,"\0") != 0){
                        while(strcmp(tabel->key,"\0") != 0){
                            if(strcmp(temp_k,tabel->key) == 0){
                                // klo ada yg ini gausah dimasukin key tpi value nya aja
                                while(strcmp(tabel->value[j],"\0") != 0){
                                    j++;
                                }
                                masukvalue(&tabel,temp_v,j);
                            }
                            tabel = tabel->go;
                        }
                        masukall(&tabel,temp_k,temp_v);
                    } else {
                        // masukin key nya
                        // masukin value nya, value[j]=value
                        masukall(&tabel,temp_k,temp_v);
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
        pop(body);
        head = body;
    }

}


int main(){
    // ini harusnya udah ada di menu
        // masukin input struct hasil nya tegar
        // masukan jumlah n pada n gram
       // int n;

    //deklarasi


    //printf("masukan n pada n-gram : "); scanf("%d", &n);
    //asumsi punya struct hasil dri file dimasukin manual
    //do{
    //    printf("masukkan isi struct (masukkan 0 untuk berhenti) :"); scanf("%s", &isi);
    //    push(isi, &head);
    //} while ((strcmp(isi,"0") != 0) || (strcmp(isi,"0") != 0));


    // output
    //printtabel(tabel);

    return(0);
}
