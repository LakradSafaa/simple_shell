#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * ordre - sort the elements of the array in descending order
 *
 * Return: 0 (success)
 */

int ordre(void)
{
	int t[8] = {10, 12, 15, 13, 14, 19, 20, 18};
	int i, j, tmp;

	for (i = 0 ; i < 8 ; i++)
	{
		for (j = i + 1 ; j < 8 ; j++)
		{
			if (t[i] < t[j])
			{
				tmp = t[i];
				t[i] = t[j];
				t[j] = tmp;
			}
		}
	}

	printf("\n les elements du tableau par ordre croissant sont :");
	for (i = 0 ; i < 8 ; i++)
	printf("\n%d", t[i]);
	return (0);
}
