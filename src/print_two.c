/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** print
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "project.h"

void print_five(seqlist_t *seqlist)
{
	charlist_t *list = five_create_charlist(seqlist);
	void *tmp = NULL;

	while (list) {
		tmp = list->next;
		printf("%s\n", list->str);
		free(list->str);
		free(list);
		list = tmp;
	}
}

void print_six(seqlist_t *seqlist)
{
	charlist_t *list = six_create_charlist(seqlist);
	void *tmp = NULL;

	while (list) {
		tmp = list->next;
		printf("%s\n", list->str);
		free(list->str);
		free(list);
		list = tmp;
	}
}

void print_seven(seqlist_t *seqlist)
{
	al_t al = opt_seven(seqlist);
	printf("%s\n%s\n", al.al_a, al.al_b);
	free(al.al_a);
	free(al.al_b);
}
