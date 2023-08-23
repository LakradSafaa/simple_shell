#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char *input = NULL;
	size_t input_length = 0;
	char *prompt = "$: ";
debut:
	printf("%s", prompt);
	if (getline(&input, &input_length, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("\nCtrl+D pressed. Exiting shell...\n");
			return (0);
		}
		else
		{
			perror("Error reading input");
			exit(EXIT_FAILURE);
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

	while (token != NULL && arg_count < 25)
	{
		arguments[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	arguments[arg_count] = NULL;
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *path_token = strtok(path_copy, ":");
	char command_path[256];

	while (path_token != NULL)
	{
		snprintf(command_path, sizeof(command_path), "%s/%s", path_token, arguments[0]);
		if (access(command_path, X_OK) == 0)
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
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (fork() == 0)
	{
		if (execv(command_path, arguments) == -1)
		{
			perror("Command execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;
		
		waitpid(ps, &status, 0);
	}
	goto debut;
	if (input)
	{
		free(input);
	}
	return (0);
}
