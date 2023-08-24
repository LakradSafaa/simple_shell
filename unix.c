#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - this function is used to interpret unix commands
 *
 * Return: 0 (success)
 */

int main()
{
	char cmmndline[256];
	char *prompt = "$ :";
	pid_t ps;
debut:
	{
		printf("%s", prompt);
		if (fgets(cmmndline, sizeof(cmmndline), stdin) == NULL)
		{
			if (!feof(stdin))
			{
				perror("No such file or directory ");
				exit(0);
			}
			else
			{
				printf("\n Exit by pressing Ctrl+D.\n");
				return(0);
			}
		}
		cmmndline[strcspn(cmmndline, "\n")] = '\0';
		if (strlen(cmmndline) == 0)
		{
			goto debut;
		}
		ps = fork();
		if (ps < 0)
		{
			perror("Error Fork ");
			exit(0);
		}
		else if (ps == 0)
		{
			execlp(cmmndline, cmmndline, (char *)NULL);
			fprintf(stderr, "Command not found: %s\n", cmmndline);
			exit(0);
		}
		else
		{
			int status;

			waitpid(ps, &status, 0);
		}
		return (0);
	}
}
