/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

typedef struct Pokemon {
   char id[MAX_LEN];
   char name[MAX_LEN];
   char type[MAX_LEN];
}Pokemon;

//Fungsi untuk melakukan print sesuai input structure
void printPokemon(Pokemon *p) {
   p->name[0] = toupper(p->name[0]); //uppercase letter pertama
   p->type[0] = toupper(p->type[0]); 
   for (int i = 1; i<MAX_LEN; i++){ 
      if (p->type[i] == ','){
         p->type[i+1] = toupper(p->type[i+1]);
      }
   }

   printf("\nID: %s\nNama: %s\nType: %s\n", p->id, p->name, p->type);
}

//Fungsi untuk melakukan pencarian ID pada array structure
void searchID(Pokemon *p[], int n, int ID) {
   int i, found = 0;
   char *ID_str;
   char *temp;
   sprintf(ID_str, "%d", ID);
   
   for (i = 0; i < n; i++) {
      temp = strstr(p[i]->id, ID_str); //cari needle di haystack
      if (temp!=NULL) {
         found = 1;
         printPokemon(p[i]);
      }
   }

   if (!found) {
      printf("\nPokemon yang memiliki ID %d belum ditangkap!", ID);
   }
}

//Fungsi untuk melakukan pencarian name pada array structure
void searchName(Pokemon *p[], int n, char name[]) {
   int i, found = 0;
   char *temp;
    
   for (i = 0; i < n; i++) {
      temp = strstr(p[i]->name, name); //cari needle di haystack
      if (temp!=NULL) {
         found = 1;
         printPokemon(p[i]);
      }
   }

   if (!found) {
      printf("\nPokemon dengan inisial nama %s belum ditangkap!", name);
   }
}

//Fungsi untuk melakukan pencarian type pada array structure
void searchType(Pokemon *p[], int n, char type[]) {
   int i, found = 0;
   char *temp;

   for (i = 0; i < n; i++) {
      temp = strstr(p[i]->type, type); //cari needle di haystack
      if (temp!=NULL) {
         found = 1;
         printPokemon(p[i]);
      }
   }

   if (!found) {
      printf("\nPokemon dengan type %s belum ditangkap!", type);
   }
}

int main() {
   char name[20], type[20];
   int ID_int;
   
   char filename[MAX_LEN];
   printf("Masukkan nama file input: ");
   scanf("%s", &filename);
   FILE* fp = fopen(filename, "r");
   if (fp == NULL){
      printf("\nError: file tidak tersedia!\n");
      return 0;
   }

   char line[MAX_LEN];
   int len=(-1);
   while (fgets(line, MAX_LEN, fp)) { //hitung jumlah baris
      len++;
   }
   rewind(fp); //atur posisi file ke awal lagi
   
   //inisiasi array dinamis
   Pokemon **pokedex = malloc(len * sizeof(Pokemon*));
   for (int i = 0; i < len; i++) {
      pokedex[i] = malloc(sizeof(Pokemon));
   } 

   char* token; 
   int i =(-1);
   int input;
   
   while (fgets(line, MAX_LEN, fp)) {
      if (i==(-1)){ //ambil input
         token = strtok(line, "\n");
         input = atoi(token);        
         i++;
      }
      else{ //ambil data pokemon
         token = strtok(line, ";");
         strcpy(pokedex[i]->id, token);
         token = strtok(NULL, ";");
         strcpy(pokedex[i]->name, strlwr(token));
         token = strtok(NULL, "\n");
         strcpy(pokedex[i]->type, strlwr(token));
         i++;
      }
   }

   if (input == 1){
      printf("\nProgram mencari ID pokemon\nMasukkan ID pokemon yang ingin dicari: ");
      scanf("%d", &ID_int);
      searchID(pokedex, len, ID_int);
   }
   else if (input == 2){
      printf("\nProgram mencari Nama pokemon\nMasukkan Nama pokemon yang ingin dicari: ");
      scanf("%s", &name);
      searchName(pokedex, len, strlwr(name));
   }
   else if (input == 3){
      printf("\nProgram mencari Type pokemon\nMasukkan Type pokemon yang ingin dicari: ");
      scanf("%s", &type);
      searchType(pokedex, len, strlwr(type));
   }

   free(pokedex);
   fclose(fp);
   return 0;
}
