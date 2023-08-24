#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - handling command lines with arguments
 *
 * Return: 0 (success)
 */

int main()
{
	char input[256];
	char *prompt = "$ :";

debut:
	printf("%s", prompt);
	if (fgets(input, sizeof(input), stdin) == NULL)
	{
		if (!feof(stdin))
		{
			perror("Error input");
			exit(0);
		}
		else
		{
			printf("\n press Ctrl+D to exit \n");
			return (0);
		}
	}
	input[strcspn(input, "\n")] = '\0';
	if (strlen(input) == 0)
	{
		goto debut;
	}
	char *arguments[25];
	int arg_count = 0;
	char *token = strtok(input, " ");
	while (token != NULL)
	{
		arguments[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	arguments[arg_count] = NULL;
	pid_t ps = fork();
	if (ps < 0)
	{
		perror("ERROR Fork");
		exit(0);
	}
	else if (ps == 0)
	{
		if (execvp(arguments[0], arguments) == -1)
		{
			perror("Command not found");
			exit(0);
		}
	}
	else if (ps > 0)
	{
		int status;
		waitpid(ps, &status, 0);
	goto debut;
	}
	return(0);
}
