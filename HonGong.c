#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int hangman();
void score(int);

void main() {
	printf("Game start!\n\n);");
	hangman();
}

int hangman()
{
	int select;
	int num = 25;
	char words[25][10] = {
		{"dog"},{"cat"},{"tiger"} ,{"monkey"},{"rabit"},{"duck"},{"turtle"},{"cow"},{"chicken"},{"lion"},{"snake"},{"horse"},{"mouse"},{"giraffe"},
		{"penguin"},{"whale"},{"deer"},{"sheep"},{"goat"},{"wolf"},{"fox"},{"elephant"},{"bear"},{"camel"},{"dolphin"}
	};
	srand(time(NULL));
	select = rand() % num;

	char problem[10] = { 0, };
	char answer[10] = { 0, };
	char char_answer;

	int len_answer;
	int count = 0;

	len_answer = strlen(words[select]);
	strcpy(problem, words[select]);

	for (int i = 0; i < len_answer; i++)
	{
		answer[i] = '_';
		printf(" %c", answer[i]);
	}

	while (1)
	{
		printf("\nPlease type an alphabet : ");
		scanf("%c", & char_answer);
		int right = 0;

		for (int i = 0; i < len_answer; i++)
		{
			if (problem[i] == char_answer)
			{
				answer[i] = problem[i];
				right = 1;
			}
		}

		if (right == 0)
		{
			printf("wrong!\n");
			count++;
			score(count);
		}

		for (int i = 0; i < len_answer; i++)
		{
			printf("%c", answer[i]);
		}
		printf("\n");
		if (strcmp(answer, problem) == 0)
		{
			printf("¡Ú¡Ù¡Ú YOU WIN ¡Ù¡Ú¡Ù\n");
			break;
		}
		if (count == 6)
		{
			printf("You lost. Try again\n");
			printf("The answer is \"%s\"\n", problem);
			break;
		}
		return 0;
	}
}
void score(int count)
{
	if (count == 0)
	{
		printf("   |-------|\n");
		printf("           |\n");
		printf("           |\n");
		printf("           |\n");
		printf("           ^\n");
	}
	else if (count == 1)
	{
		printf("   |-------|\n");
		printf("   o       |\n");
		printf("           |\n");
		printf("           |\n");
		printf("           ^\n");
	}
	else if (count == 2)
	{
		printf("   |-------|\n");
		printf("   o       |\n");
		printf("   |  	   |\n");
		printf("           |\n");
		printf("           ^\n");
	}
	else if (count == 3)
	{
		printf("   |-------|\n");
		printf("   o       |\n");
		printf(" ¡ç|  	   |\n");
		printf("           |\n");
		printf("           ^\n");
	}
	else if (count == 4)
	{
		printf("   |-------|\n");
		printf("   o       |\n");
		printf(" ¡ç|¡æ 	   |\n");
		printf("           |\n");
		printf("           ^\n");
	}
	else if (count == 5)
	{
		printf("   |-------|\n");
		printf("   o       |\n");
		printf(" ¡ç|¡æ 	   |\n");
		printf("  ¡é       |\n");
		printf("           ^\n");
	}
	else if (count == 6)
	{
		printf("   |-------|\n");
		printf("   o       |\n");
		printf(" ¡ç|¡æ 	   |\n");
		printf("  ¡é¡é     |\n");
		printf("           ^\n");
	}
}