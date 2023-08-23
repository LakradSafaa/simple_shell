#include "shell.h"

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
