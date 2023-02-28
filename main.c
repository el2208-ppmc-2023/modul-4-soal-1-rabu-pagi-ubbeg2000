/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef struct Pokemon {
   char id[MAX_LEN];
   char name[MAX_LEN];
   char type[MAX_LEN];
} Pokemon;

//Fungsi untuk melakukan print sesuai input structure
void printPokemon(Pokemon *p) {
   ...

   printf("\nID: %s\nNama: %s\nType: %s\n", ..., ..., ...);
}

//Fungsi untuk melakukan pencarian ID pada array structure
void searchID(Pokemon *p, int n, int ID) {
   ...

   printf("\nPokemon yang memiliki ID %d belum ditangkap!", ...);
}

//Fungsi untuk melakukan pencarian name pada array structure
void searchName(Pokemon *p, int n, char name[]) {
   ...

   printf("\nPokemon dengan inisial nama %s belum ditangkap!", ...);
}

//Fungsi untuk melakukan pencarian type pada array structure
void searchType(Pokemon *p, int n, char type[]) {
   ...

   printf("\nPokemon dengan type %s belum ditangkap!", ...);
}

int main() {
    
    printf("Masukkan nama file input: ");
   
    //Inisiasi array dinamis structure
    Pokemon ... = ...;


    printf("\nProgram mencari ID pokemon\nMasukkan ID pokemon yang ingin dicari: ");
    searchID(..., ..., ...);

    printf("\nProgram mencari Nama pokemon\nMasukkan Nama pokemon yang ingin dicari: ");
    searchName(..., ..., ...);

    printf("\nProgram mencari Type pokemon\nMasukkan Type pokemon yang ingin dicari: ");
    searchType(..., ..., ...);

    return 0;
}
