#include <stdio.h>
#include <string.h>

const int max_lenght_strings = 400;
const int max_length_text = 400;
const char const * keyword = "end";

int max(int a, int b) {
	return (a > b ? a : b);
}

int main() {
	printf("Enter your text");
	printf("Max number of string is %d, max length of one line is %d\n",
		max_lenght_strings, max_length_text);
	printf("To finish the text, press \"%s\".\n\n", keyword);
	int i, j, n = 0, mx = 0;
	char a[max_lenght_strings][max_length_text];

	while (1) {
		int flag = 0;
		char temp_string[max_length_text], changed[max_length_text];
		gets(temp_string);
		for (i = 0; i < strlen(temp_string); ++i) {
			if (temp_string[i] != ' ') {
				if (i > 0 && temp_string[i - 1] == ' ')
					changed[flag++] = ' ';
				changed[flag++] = temp_string[i];
			}
		}
		strncpy(a[n], changed, flag);
		mx = max(strlen(a[n]), mx);
		if (n == max_lenght_strings) {
			puts("Limit is reached.");
			break;
		}
		if (!strcmp(a[n], keyword))
			break;
		n++;
	}

	printf("\nFormatted text:\n\n");

	for (i = 0; i < n; ++i) {
		int spaces = 0;
		int number_space = 0;
		for (j = 0; j < strlen(a[i]); ++j) {
			if (a[i][j] == ' ')
				spaces++;
			else {
				if (j == 0)
					continue;
				if (a[i][j - 1] == ' ')
					number_space++;
			}
		}
		if (number_space == 0) {
			printf("%s\n", a[i]);
			continue;
		}
		if (a[i][0] == ' ')
			number_space--;
		if (number_space == 0) {
			for (j = 0; j < strlen(a[i]); ++j)
				if (a[i][j] != ' ')
					printf("%c", a[i][j]);
			printf("\n");
			continue;
		}
		int between_words = (mx - strlen(a[i]) + spaces) / number_space;
		int rest = mx - between_words * number_space - strlen(a[i]) + spaces;
		int is_writed = 0;
		for (j = 0; j < strlen(a[i]); ++j) {
			if (j > 0 && a[i][j] != ' ' && a[i][j - 1] == ' ' && is_writed) {
				int sym;
				if (rest) {
					rest--;
					printf(" ");
				}
				for (sym = 0; sym < between_words; ++sym)
					printf(" ");
			}
			if (a[i][j] != ' ') {
				is_writed = 1;
				printf("%c", a[i][j]);
			}
		}
		printf("\n");
	}
	getchar();
	return 0;
}
