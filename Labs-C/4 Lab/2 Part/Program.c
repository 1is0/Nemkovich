#include <stdio.h>
#include <string.h>

const int lenght_word = 30;
const int quantity_words = 84095;
const int max_vocabulary_word_size = 200;
const int alphabet_size = 512;

int main() {

	char word[lenght_word];
	int alphabet[alphabet_size];
	int i, j, k;
	char * filepath = "D:\\Programming\\For Github\\Labs-C\\4 Lab\\2 Part\\engmix.txt";
	FILE* vocabulary = fopen(filepath, "r");

	puts("Enter your word: ");
	gets(word);

	for (i = 0; i < alphabet_size; ++i)
		alphabet[i] = 0;
	for (i = 0; i < strlen(word); ++i)
		alphabet[word[i]] = 1;

	int ans = 0;

	for (i = 0; i < quantity_words; ++i) {

		int is_ans = 1;
		char temp[max_vocabulary_word_size];

		fgets(temp, max_vocabulary_word_size, vocabulary);

		for (j = 0; j < strlen(temp) - 1; ++j) {
			if (alphabet[temp[j]] == 0) {
				is_ans = 0;
				break;
			}
		}
		if (is_ans) {
			ans++;
			printf("%s", temp);
		}
	}
	printf("\nTotal words ( and 1st letters ) found: %d.", ans);
	getchar();
	return 0;
}

