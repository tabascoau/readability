#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <math.h>

bool isPunctuations(char s) {
	if (s == '.' || s == '!') {
		return true;
	}
	return false;
}

float calculateReadLevel(int averageNumOfLetters, int averageNumOOfSentence) {
	return 0.0588 * averageNumOfLetters - 0.296 * averageNumOOfSentence - 15.8;
}
void main() {
	const int MAX_SIZE = 1000;
	int letters = 0;
	int sentences = 0;
	int words = 0;
	char userInput[MAX_SIZE];
	printf("Readability program\n");
	printf("Please input sentence:");
	fgets(userInput, sizeof(userInput), stdin);
	printf("\n");

	for (int i = 0; i < MAX_SIZE; i++) {
		if (userInput[i] == '\0') {
			break;
		}
		else {
			if (isalpha(userInput[i])) {
				letters++;
			}
			else if (isPunctuations(userInput[i])) {
				sentences++;
			}
			else if (isspace(userInput[i])) {
				words ++;
			}
		}
	}
	float averageNumOfLetters = letters * 1.0 / words * 1.0 * 100.0f;
	float averageNumOOfSentence = sentences * 1.0 / words * 1.0 * 100.0f;
	float result = round(calculateReadLevel(averageNumOfLetters, averageNumOOfSentence));
	printf("Grade: %f", result);
	printf("\n");
}
