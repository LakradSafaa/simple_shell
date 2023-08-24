#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - function exits the shell
 *
 * Return: 0 (success)
 */

void exitShell()
{
	printf("Exit \n");
	exit(0);
}

int main()
{
	char entr[256];
debut:
	printf("Shell> ");
	fgets(entr, sizeof(entr), stdin);
	size_t len = strlen(entr);

	if (len > 0 && entr[len - 1] == '\n')
		{
		entr[len - 1] = '\0';
		}
	if (strcmp(entr, "exit") == 0)
	{
		exitShell();
		goto debut;
	}
	else
	{
		printf("Unrecognized command : %s\n", entr);
		goto debut;
	}
	return (0);
}
