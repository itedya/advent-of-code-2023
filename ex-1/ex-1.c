#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
	FILE *file = fopen("ex-1-input.txt", "r");
	if (!file) {
		printf("Could not open an input file!\n");
		return 1;
	}

	int sum = 0;

	char first_num = EOF;
	char second_num = EOF;

	char buf;

	while ((buf = getc(file)) != EOF) {
		if (buf == '\n') {
			if (second_num == EOF) {
				second_num = first_num;
			}

			char final_number[2];
			final_number[0] = first_num;
			final_number[1] = second_num;

			printf("One liner: %s\n", final_number);

			sum += atoi(final_number);

			second_num = EOF;
			first_num = EOF;
		}

		if (!isdigit(buf)) {
			continue;
		}

		if (first_num == -1) first_num = buf;
		else second_num = buf;
	}

	fclose(file);

	printf("Result is: %d\n", sum);

	return 0;
}
