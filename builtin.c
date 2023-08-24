#include "shell.h"
/**
 * main - this function implements the environement which prints the curent environment
 *
 * Return: 0 (success)
 */

int main()
{
	char *enviab = getenv("PATH");

	if (enviab == NULL)
	{
		printf("PATH environment variable is not defined.\n");
	}
	else
	{
		printf("Content of the PATH environment variable : %s\n", enviab);
	}
	return (0);
}
