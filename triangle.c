#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILE_NAME "triangle1.txt"

int* split(char* arr) {
	char *end = arr;
	int* numbers = malloc(sizeof(int) * 255);
	int i = 0;
	while(*end) {
		if(isdigit(*arr)) {
			int n = strtol(arr, &end, 10);
			*(numbers + i) = n;
			i++;
			while (*end == ' ') {
				end++;
			}
			arr = end;
		}
		else break;
	}
	return numbers;
}

int findTheBiggestIndex(int i1, int n1, int i2, int n2) {
	return n1 > n2 ? i1 : i2;
}

int main() {
	FILE* file;
	
	int line_number = 0, c;
	if((file = fopen(FILE_NAME, "r")) == NULL) printf("'%s' could not be found\n", FILE_NAME);
	else {
		/* Count the number of lines of the document */
		for (c = getc(file); c != EOF; c = getc(file)) 
			if (c == '\n') line_number = line_number + 1;
		fclose(file);
		file = fopen(FILE_NAME, "r");


		char line[256];
		int i = 0, j, last_index = 0, sum = 0;
		int* split_array;
		for(j = 1; j <= line_number + 1; j++) {
			while (fgets(line, sizeof(line), file)) {
				i++;
				if(j == i)
				{
					split_array = split(line);
					if(j == 1) {
						last_index = 0;
						sum += split_array[0];
						printf("%d + ", split_array[last_index]);
					}
					else {
						last_index = findTheBiggestIndex(last_index, split_array[last_index], last_index + 1, split_array[last_index + 1]);
						sum += split_array[last_index];
						printf("%d", split_array[last_index]);
						if(j == line_number + 1) printf(" = ");
						else printf(" + ");
					}
					break;
				}
			}
		}
		printf("%d\n", sum);
		fclose(file);
	}
	return 0;
}