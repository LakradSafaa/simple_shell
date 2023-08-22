#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	char cmmndline[256];
	char *prompt = "$ :";
	pid_t ps;

	while (1)
	{
		printf("%s", prompt);
		if (fgets(cmmndline, sizeof(cmmndline), stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n Ctrl+D pressed.\n");
				break;
			}
			else
			{
				perror("No such file or directory ");
				exit(EXIT_FAILURE);
			}
		}
		cmmndline[strcspn(cmmndline, "\n")] = '\0';
		if (strlen(cmmndline) == 0)
		{
			continue;
		}
		ps = fork();
		if (ps < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (ps == 0)
		{
			execlp(cmmndline, cmmndline, (char *)NULL);
			fprintf(stderr, "Command not found: %s\n", cmmndline);
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			waitpid(ps, &status, 0);
		}
		return (0);
}
