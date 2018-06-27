/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** requirement
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char capitalize(char c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
}

char *my_strcapitalize_synthesis(char *str)
{
	int check = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if ((str[i] >= '0' && str[i] <= '9') ||
		(str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)) {
			str[i] = (check == 0)? capitalize(str[i]) : str[i];
			check = 1;
		} else if (check == 1)
			check = 0;
	}
	return (str);
}
