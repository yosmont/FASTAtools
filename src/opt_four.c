/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** option 4
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project.h"

static charlist_t *add_tolist(charlist_t *list, int k, char *str)
{
	void *begin = list;
	charlist_t *new = malloc(sizeof(charlist_t));

	while (list && list->next)
		list = list->next;
	new->prev = list;
	new->str = my_strndup(str, k);
	new->next = NULL;
	if (list) {
		list->next = new;
		return (begin);
	}
	return (new);
}

static int check_isincharlist(charlist_t *list, int k, char *str)
{
	void *begin = list;
	int check = 0;

	while (list && check == 0) {
		if (strncmp(str, list->str, k) == 0)
			check = 1;
		list = list->next;
	}
	list = begin;
	return (check);
}

static charlist_t *add_seqtolist(charlist_t *list, int k, char *seq)
{
	int check = 0;

	for (int i = 0; (int)strlen(&seq[i]) >= k; i++) {
		check = check_isincharlist(list, k, &seq[i]);
		if (check == 0)
			list = add_tolist(list, k, &seq[i]);
	}
	return (list);
}

charlist_t *bubblesort(charlist_t *list)
{
	int check = 0;
	void *begin = list;
	char *tmp;

	while (list && list->next) {
		if (strcmp(list->str, list->next->str) > 0) {
			tmp = list->str;
			list->str = list->next->str;
			list->next->str = tmp;
			check = 1;
		}
		list = list->next;
	}
	list = begin;
	if (check == 1)
		bubblesort(list);
	return (list);
}

charlist_t *four_create_charlist(seqlist_t *seqlist, int k)
{
	charlist_t *list = NULL;

	while (seqlist) {
		if ((int)strlen(seqlist->seq) >= k)
			list = add_seqtolist(list, k, seqlist->seq);
		seqlist = seqlist->next;
	}
	list = bubblesort(list);
	return (list);
}
