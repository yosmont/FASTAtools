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

void print_one(seqlist_t *seqlist)
{
	seqlist_t *begin = seqlist;

	while (seqlist) {
		write(1, seqlist->title, strlen(seqlist->title));
		write(1, seqlist->seq, strlen(seqlist->seq));
		write(1, "\n", 1);
		seqlist = seqlist->next;
	}
	seqlist = begin;
}

void print_two(seqlist_t *seqlist)
{
	seqlist_t *begin = seqlist;

	while (seqlist) {
		printf("%s", seqlist->title);
		for (int i = 0; seqlist->seq[i] != '\0'; i++)
			putchar(seqlist->seq[i] == 'T' ? 'U' : seqlist->seq[i]);
		putchar('\n');
		seqlist = seqlist->next;
	}
	seqlist = begin;
}

char three_search_letter(char c)
{
	switch (c) {
	case 'T':
		return ('A');
	case 'A':
		return ('T');
	case 'G':
		return ('C');
	case 'C':
		return ('G');
	default:
		return (c);
	}
}

void print_three(seqlist_t *seqlist)
{
	seqlist_t *begin = seqlist;

	while (seqlist) {
		printf("%s", seqlist->title);
		seqlist->seq = my_strrev(seqlist->seq);
		for (int i = 0; seqlist->seq[i] != '\0'; i++)
			putchar(three_search_letter(seqlist->seq[i]));
		putchar('\n');
		seqlist = seqlist->next;
	}
	seqlist = begin;
}

void print_four(seqlist_t *seqlist, int k)
{
	charlist_t *list = four_create_charlist(seqlist, k);
	void *tmp = NULL;

	while (list) {
		tmp = list->next;
		printf("%s\n", list->str);
		free(list->str);
		free(list);
		list = tmp;
	}
}
