//2502141990
//Muhammad Faza
//Compiler - Dev C++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int heap[10] = {0};
int curr = 0;

struct cust{
	int skala;
	char nama[20];
	char merk[20];
}id[10];

void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

void check(int child){
	//function untuk cek jika parent < child
	
	char temp[20];
	
	if (child == 1){
		return;
	}
	
	else{
		do{
			int parent = child/2;
			if (id[child].skala < id[parent].skala){
				swap(&id[child].skala, &id[parent].skala);
				
				//swap char nama
				strcpy(temp, id[child].nama);
				strcpy(id[child].nama, id[parent].nama);
				strcpy(id[parent].nama, temp);
				//swap char merk
				strcpy(temp, id[child].merk);
				strcpy(id[child].merk, id[parent].merk);
				strcpy(id[parent].merk, temp);
				
				child = child/2;
			}
			else{
				break;
			}
		}while(1);
	}
		
}

void view(){
	//untuk melihat isi data heap
	for(int i=1; i<=curr; i++){
		printf("| %d ", id[i].skala);
	}
	printf("|\n\n");
}

void view_all(){
	system("cls");
	if (curr < 1){
		printf("Tidak ada antrian\n");
		return;
	}
	view();
	for(int i=1; i<=curr; i++){
		printf("Skala: %d \n", id[i].skala);
		printf("Nama: %s \n", id[i].nama);
		printf("Merk Motor: %s \n\n\n", id[i].merk);
	}
}

void insert(){
	int input = 0;
	
	if (curr == 9){
		printf("\n\nHEAP FULL");
		return;
	}
	
	while(1){
		system("cls");
		view();
    	printf("Masukkan angka skala perbaikan (-1 untuk keluar): ");
		scanf("%d", &input); getchar();
		if (input < 0)break;
		
		curr++;
		
		printf("Masukkan nama customer: ");
		scanf("%[^\n]", id[curr].nama); getchar();
		
		printf("Masukkan merk motor: ");
		scanf("%[^\n]", id[curr].merk); getchar();
	
		id[curr].skala = input;
		
		check(curr);
		
		
        	printf("\nAntrian berhasil dimasukkan!");
        	getchar();
	}
}

void deletechar(int element){
	for(int i = 0; i <= 20; i++){
		id[element].nama[i] = '\0';
		id[element].merk[i] = '\0';
	}
}

void view_priority(){
	printf("Skala: %d \n", id[1].skala);
	printf("Nama: %s \n", id[1].nama);
	printf("Merk Motor: %s \n\n\n", id[1].merk);
}

void downheap(){
	char temp[20];
	//var succ adalah successor / penerus
	int succ = 1; int index;
	int left; int right;
	while(1){
		index = succ;
		left = 2 * succ;
		right = 2 * succ + 1;
		
		if(left <= curr && id[succ].skala > id[left].skala){
			succ = left;
		}
		else if(right <= curr && id[succ].skala > id[right].skala){
			succ = right;
		}
		
		//kalo tidak ada perbaikan
		else if (succ == index){
			break;
		}
		
		swap(&id[succ].skala, &id[index].skala);
		
		//swap char nama
		strcpy(temp, id[succ].nama);
		strcpy(id[succ].nama, id[index].nama);
		strcpy(id[index].nama, temp);
		//swap char merk
		strcpy(temp, id[succ].merk);
		strcpy(id[succ].merk, id[index].merk);
		strcpy(id[index].merk, temp);
	}
}

void deletemin(){
	if (curr == 0){
		printf("Tidak ada antrian\n"); getchar();
		return;
	}
	else if (curr == 1){
		view();
		view_priority();
		
		id[curr].skala = NULL;
		deletechar(curr);
		curr--;
		
		printf("Antrian berhasil dikeluarkan dan terhapus!\n");
		return;
	}
	view();
	view_priority();
	
	//replace root dgn curr lalu delete curr
	id[1].skala = id[curr].skala;
	strcpy(id[1].nama, id[curr].nama);
	strcpy(id[1].merk, id[curr].merk);
	
	id[curr].skala = NULL;
	deletechar(curr);
	curr--;
	
	downheap();
	
	printf("Antrian berhasil dikeluarkan dan terhapus!\n\n");
	view();
	
}

int main(){
	
	int selectMenu;
    while(1){
        system("cls");
        printf("    PROGRAM BENGKEL MOTOR\n");
        printf("=============================\n");
        printf(" Muhammad Faza - 2502141990\n\n");
        printf("1. Masuk Antrian\n");
        printf("2. Keluar Antrian\n");
        printf("3. Cari Prioritas Utama\n");
        printf("4. Lihat Semua Data\n");
        printf("5. Exit Program\n\n");
        printf("Masukkan Input: ");
        scanf("%d", &selectMenu); getchar();

        if(selectMenu == 1){
        	insert();
        }
        else if(selectMenu == 2){
            system("cls"); 
            deletemin();
            getchar();
        }
        else if(selectMenu == 3){
            system("cls"); 
            view_priority();
            printf("Berikut adalah prioritas utama.");
            getchar();
        }
        else if(selectMenu == 4){
        	view_all();
        	getchar();
        }
        else if(selectMenu == 5){
            break;
        }
        else{
        printf("input tidak dikenal");
        getchar();
        system("cls");
        }
    }
	
	
	
	
	return 0;
}
