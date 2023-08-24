#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - function manages the path variable
 *
 * Return: 0 (success)
 */

int main()
{
	char *entr = NULL;
	size_t entr_length = 0;
	char *prompt = "$: ";
debut:
	printf("%s", prompt);
	if (getline(&entr, &entr_length, stdin) == -1)
	{
		if (!feof(stdin))
		{
			perror("Error input");
			exit(0);
		}
		else
		{
			printf("\npress Ctrl+D to exit.\n");
			 return (0);
		}
	}
	entr[strcspn(entr, "\n")] = '\0';
	if (strlen(entr) == 0)
	{
		goto debut;
	}
	char *arguments[25];
	int arg_count = 0;
	char *tkn = strtok(entr, " ");

	while (tkn != NULL && arg_count < 25)
	{
		arguments[arg_count++] = tkn;
		tkn = strtok(NULL, " ");
	}
	arguments[arg_count] = NULL;
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *path_token = strtok(path_copy, ":");
	char cmmnd_path[256];

	while (path_token != NULL)
	{
		snprintf(cmmnd_path, sizeof(cmmnd_path), "%s/%s", path_token, arguments[0]);
		if (access(cmmnd_path,X_OK) == 0)
		{
			return (0);
		}
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	if (path_token == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", arguments[0]);
		goto debut;
	}
	pid_t ps = fork();

	if (fork() < 0)
	{
		perror("Fork ");
		exit(0);
	}
	else if (fork() == 0)
	{
		if (execv(cmmnd_path, arguments) == -1)
		{
			perror("Cmmnd failed");
			exit(0);
		}
	}
	else if (fork() > 0)
	{
		int status;
		
		waitpid(ps, &status, 0);
	
	goto debut;
	}
	return (0);
}
