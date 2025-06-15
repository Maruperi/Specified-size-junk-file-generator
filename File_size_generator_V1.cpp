/*
 *	Program that creates a file of specified size.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KB 1024
#define MB 1024*KB
#define GB 1024*MB

int main (void)
{
	int num_size;
	char unit_size;
	FILE *file;
	char file_name[] = "FILE";
	long int current_bytes;
	long int total_bytes;
	char rand_char;
	
	srand(time(NULL));

	
	printf("Enter the size of the file (format -> int char)\n");
	printf("\t- K = KiloByte\n");
	printf("\t- M = MegaByte\n");
	printf("\t- G = GigaByte\n");
	
	/*User input*/
	scanf("%d %c", &num_size, &unit_size);
	
	if (unit_size == 'K' || unit_size == 'k'){
		total_bytes = num_size * KB;
		printf("The file will be %d KiloBytes (%ld Bytes)\n", num_size, total_bytes);	
	} else if (unit_size == 'M' || unit_size == 'm'){
		total_bytes = num_size * MB;
		printf("The file will be %d MegaBytes (%ld Bytes)\n", num_size, total_bytes);
	} else if (unit_size == 'G' || unit_size == 'g'){
		total_bytes = num_size * GB;
		printf("The file will be %d GigaBytes (%ld Bytes)\n", num_size, total_bytes);
	} else {
		printf("Unidad no válida (%c)", unit_size);
	}
	
	/*file opening*/
	file = fopen(file_name, "wt");
	
	if (file == NULL){
		printf("Error: was not able to open the file");
		return 1;
	}
	
	current_bytes = 0;
	while (current_bytes < total_bytes){
		rand_char = (char) (rand() % 94 + 33); //Random readable character generator
		fprintf(file, "%c", rand_char);
		current_bytes++;
	}
	
	fclose(file);
	
 	return 0;
}

