/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** matrice function
*/

#include <string.h>
#include <stdlib.h>
#include "project.h"

int **create_matrice(int x, int y, char *str_a, char *str_b)
{
	int **mat = malloc(sizeof(int *) * (y + 1));
	int c[2] = {0, 0};

	for (int k = 0; k < y; k++)
		mat[k] = malloc(sizeof(int) * (x + 1));
	mat[y] = NULL;
	for (int i = 0; i < x; i++)
		mat[0][i] = (-5) * i;
	for (int i = 0; i < y; i++)
		mat[i][0] = (-5) * i;
	for (int i = 1; i < y; i++)
		for (int j = 1; j < x; j++) {
			mat[i][j] = mat[i - 1][j - 1] + c_value(str_a[j]) -
			c_value(str_b[i]);
			c[0] = mat[i - 1][j] - 5;
			c[1] = mat[i][j - 1] - 5;
			mat[i][j] = (c[0] > mat[i][j]) ? c[0] : mat[i][j];
			mat[i][j] = (c[1] > mat[i][j]) ? c[1] : mat[i][j];
		}
	return (mat);
}

void free_mat(matinfo_t matinfo)
{
	for (int i = 0; i < matinfo.x; i++)
		free(matinfo.mat[i]);
	free(matinfo.mat);
}
