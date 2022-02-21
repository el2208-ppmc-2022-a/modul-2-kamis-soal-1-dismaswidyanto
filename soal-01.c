/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 2 - Strings and External Files
*Percobaan        : -
*Hari dan Tanggal : Kamis, 24 Februari 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(){
	char namafile[10];
	char line[35]; 
	char siswa[25];
	char bpm[5];
	char namasiswa[25];
	char temp_siswa[25];
	int  bpmint, menu, BA, BB, found = 0;
	int minbpm = INT_MAX;
	FILE *filekelas; //pointer of type file

	printf("Masukkan nama file kelas : ");
	scanf("%s", &namafile);

	filekelas = fopen(namafile, "r"); //buka file mode read only

	if (filekelas == NULL){ //jika file tidak ditemukan dalam folder yang sama dengan source code
		printf("Error : file invalid\n");
		return 0;
	}

	printf("Pilihlah nomor menu dibawah ini : \n");
	printf("1. Cari siswa dengan bpm terkecil\n");
	printf("2. Cari siswa dengan nama nya\n");
	printf("3. Cari siswa dengan rentang bpm tertentu\n");
	printf("Masukkan nomor menu 1/2/3 : ");
	scanf("%d", &menu);

	if (menu==2){
		printf("Masukkan nama siswa : ");
		scanf(" %[^\n]s", &namasiswa);
	}
	else if(menu==3){
		printf("Masukkan batas atas bpm : ");
		scanf("%d", &BA);
		printf("Masukkan batas bawah bpm : ");
		scanf("%d", &BB);
	}

	while(fgets(line,35, filekelas)){
		strcpy(siswa, strtok(line, ","));
		strcpy(bpm, strtok(NULL, "\n"));
		
		if (menu==1){
			bpmint = atoi(bpm);
			if(bpmint < minbpm){
				minbpm = bpmint;
				strcpy(temp_siswa, siswa);
			}
		}
		else if (menu==2){
			strcpy(temp_siswa, siswa);
			if(strstr(siswa, namasiswa)){
				printf("Siswa %d\n", found+1);
				printf("Nama siswa : %s\n", temp_siswa);
				printf("Bpm siswa : %s\n", bpm);
				found++;
			} 
		}
		else if(menu==3){
			bpmint = atoi(bpm);
			if (bpmint>= BB && bpmint<= BA){
				printf("Siswa %d\n", found+1);
				printf("Nama siswa : %s\n", siswa);
				printf("Bpm siswa : %s\n", bpm);
				found++;
			}
		}
		else {
			printf("Error : Nomor menu invalid\n");
			fclose(filekelas);
			return 0;
		}

	}

	if(menu==1){
		printf("Siswa %d\n", found+1);
		printf("Nama siswa : %s\n", temp_siswa); 
		printf("Bpm siswa : %d\n", minbpm);
	}
	else if(found==0){
		printf("Hasil pencarian tidak ditemukan :(\n");
	}

	fclose(filekelas);
	return 0;
}
