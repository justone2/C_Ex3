#include <stdio.h>

#define LINE 		256
#define MAXLINES 	250
#define WORD 		30

/* Get length of a string */

int get_len(char* word) {
	int len = 0;

	while (*(word+len) != '\0')
		len++;

	return len;
}

/* Check if line contains word */

int substring(char* line, char* word) {
	int i = 0;

	while (*(line+i) != '\0') {
		if (*(line+i) == *(word+0)) {
			int j = i;
			int a = 0;

			while (*(line+(j++)) == *(word+(a++)))
				if (*(word+a) == '\0' && a == get_len(word))
					return 1;
		}

		i++;
	}

	return 0;
}

/* Looking for word2 inside of word1 */

int similar(char* word1, char* word2) {
	int len1 = get_len(word1);
	int len2 = get_len(word2);
	
	if( (len1 > len2 && len1 - len2 > 1) || (len2 > len1 && len2 - len1 > 1) )
		return 0;
	
	int j = 0;

	for (int i = 0; i < len1; i++) {
		if (*(word1+i) == *(word2+j))
		j++;
	}
	
	return j == len2;
}

/* String copy */

void str_cpy(char* str1, char* str2) {
	int i = 0;

	while((*(str1+i) = *(str2+i)) != '\0')
		i++;
}

/* A */

void TargilA(char txt[MAXLINES][LINE], int len, char* lookingfor) {
	for(int i = 0; i < len; i++) {
		if(substring(*(txt+i), lookingfor))
			printf("%s", *(txt+i));
	}
}

/* B */

void TargilB(char txt[MAXLINES][LINE], int len, char* lookingfor) {
 	char word[LINE];
 	int id = 0;

 	for(int i = 0; i < len; i++) {
 		 for (int j = 0; j < get_len(*(txt+i)); j++) {
			if (*(*(txt+i)+j) == '\t' || *(*(txt+i)+j) == '\n' || *(*(txt+i)+j) == ' ') {
				*(word+(id++)) = '\0';
				id = 0;

				if (similar(word, lookingfor)) {
					printf("%s\n", word);
				}
			}
			else {
				*(word+(id++)) = *(*(txt+i)+j);
			}
		}
	}
}

int main()
{
	char buffer[LINE];
	char file[MAXLINES][LINE];

	int len = 0;
	int i = 0;
	int flag = 0;

	char word[WORD];
	char option;
	
	/* Read from stdin */

	while(fgets(buffer, LINE , stdin)) {
		i++;
		if(i == 1) {
			for(int j = 0; j < get_len(buffer); j++) {
				if(!flag)
					*(word+j) = *(buffer+j);
				else {
					option = *(buffer+j);
					break;
				}

				if(*(buffer+j) == ' ' || *(buffer+j) == '\n' || *(buffer+j) == '\t') {
					flag = 1;
					*(word+j) = '\0';
				}
			}
			printf("Word is: %s char is: %c\n", word, option);
		} 
		else if(i>=3)
			str_cpy(*(file+(len++)), buffer);
	}

	switch(option) {
		case 'a': {
			printf("Targil A\n\n");
			TargilA(file, len, word);
			break;
		}
		case 'b': {
			printf("Targil B\n\n");
			TargilB(file, len, word);
			break;
		}
		default: {
			printf("Wrong input option\n");
			break;
		}
	}
}

