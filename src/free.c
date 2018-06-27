/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** free function
*/

#include <stdlib.h>
#include "project.h"

void free_seqlist(seqlist_t *seqlist)
{
	void *tmp;

	while (seqlist) {
		tmp = seqlist->next;
		free(seqlist->title);
		free(seqlist->seq);
		free(seqlist);
		seqlist = tmp;
	}
}
