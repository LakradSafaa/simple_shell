#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exitShell()
{
	printf("Exiting the shell...\n");
	exit(0);
}

int main()
{
	char input[256];
debut:
	printf("Shell> ");
	fgets(input, sizeof(input), stdin);
	size_t len = strlen(input);

	if (len > 0 && input[len - 1] == '\n')
		{
		input[len - 1] = '\0';
		}
	if (strcmp(input, "exit") == 0)
	{
		exitShell(); "exit"
	}
	else
	{
		printf("Commande non reconnue : %s\n", input);
	}
	goto debut;
	return (0);
}
