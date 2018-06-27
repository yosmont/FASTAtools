/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** option five function
*/

#include <stdlib.h>
#include <string.h>
#include "project.h"

static char *get_codseq(char *str)
{
	int check = 0;
	int i = 0;

	for (; &str[i] && (int)strlen(&str[i]) >= 3 &&
		strncmp(&str[i], "TAA", 3) && strncmp(&str[i], "TAG", 3) &&
		strncmp(&str[i], "TGA", 3); i += 3)
		check += 1;
	if (!&str[i] || (int)strlen(&str[i]) < 3)
		return (NULL);
	return (my_strndup(str, (check * 3)));
}

static charlist_t *add_tolist(charlist_t *list, char *str)
{
	void *begin = list;
	charlist_t *new = malloc(sizeof(charlist_t));

	while (list && list->next)
		list = list->next;
	new->prev = list;
	new->str = get_codseq(str);
	new->next = NULL;
	if (new->str == NULL) {
		free(new);
		return (begin);
	} else if (list) {
		list->next = new;
		return (begin);
	}
	return (new);
}

static charlist_t *add_seqtolist(charlist_t *list, char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (strncmp(&str[i], "ATG", 3) == 0) {
			list = add_tolist(list, &str[i]);
		}
	}
	return (list);
}

charlist_t *five_create_charlist(seqlist_t *seqlist)
{
	charlist_t *list = NULL;

	while (seqlist) {
		list = add_seqtolist(list, seqlist->seq);
		seqlist = seqlist->next;
	}
	list = bubblesort(list);
	return (list);
}
