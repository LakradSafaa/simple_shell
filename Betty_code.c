#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - sort the elements of the array in descending order
 *
 * Return: 0 (success)
 */

int main()
{
	int t[8];
	int i, j, tmp;

	printf("Veuillez saisir les elements du tableau : \n");
	for (i = 0; i < 8; i++)
	{
		printf("t[%d] = ", i + 1);
		scanf("%d", &t[i]);
	}
	for (i = 0; i < 8; i++)
	{
		for (j = i + 1; j < 8; j++)
		{
			if (t[i] < t[j])
			{
				tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
		}
	}
	printf("\n les elements du tableau par ordre croissant sont : ");
	for (i = 0; i < 8; i++)
		printf("\n%dt", t[i]);
	return (0);
}
