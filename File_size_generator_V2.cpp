/*
 *	Program that creates a file of specified size.
 * 	Contains a buffer and writes with fwrite (faster than fprintf).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KB 1024
#define MB 1024*KB
#define GB 1024*MB
#define BUFFER_SIZE 5*KB

int main (void)
{
	int num_size;
	char unit_size;
	long int total_bytes;
	long int current_bytes;
	FILE *file;
	char file_name[] = "FILE";
	char buffer[BUFFER_SIZE];
	size_t	bytes_to_write, bytes_written;
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
		return 1;
	}
	
	/*file opening*/
	printf("\nOpening file...");
	file = fopen(file_name, "wt");
	
	if (file == NULL){
		printf("\nError: was not able to open the file");
		return 1;
	}
	
	printf("\nFile openned sucesfully...");
	
	printf("\nWritting data in file...");
	
	current_bytes = 0;
	while (current_bytes < total_bytes){
		bytes_to_write = (total_bytes - current_bytes > BUFFER_SIZE) ? BUFFER_SIZE : (size_t)(total_bytes - current_bytes);
		
		int i;
		for (i = 0; i < bytes_to_write; i++){
			rand_char = (char) (rand() % 94 + 33); //Random readable character generator
			buffer[i] = rand_char;
		}
		
		bytes_written = fwrite(buffer, 1, bytes_to_write, file);
		
		if (bytes_written != bytes_to_write){
			printf("\nError: writing file failed...");
			fclose(file);
			return 1;
		}
		
		current_bytes += bytes_written;
	}
	
	printf("\nClosing file...");
	fclose(file);
	
	printf("\nDone.");
	
 	return 0;
}

