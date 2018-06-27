/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** get fasta file
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "project.h"

static char *cut_string(char *str, int begin)
{
	for (int i = begin; str[i] != '\0'; i++)
		str[i] = str[i + 1];
	return (str);
}

static char *normalize_seqstr(char *str, int i)
{
	int check = 0;

	for (; str[i] != '\0' && (str[i] == 'A' || str[i] == 'T' ||
	str[i] == 'C' || str[i] == 'G' || str[i] == 'N'); i++);
	if (str[i] == '\0')
		return (str);
	while (str[i] != '\0' && !(str[i] == 'A' || str[i] == 'T' ||
	str[i] == 'C' || str[i] == 'G' || str[i] == 'N')) {
		check = 1;
		cut_string(str, i);
	}
	if (check == 1)
		normalize_seqstr(str, i);
	return (str);
}

static char *capitalize_dnaseq(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == 'a' || str[i] == 't' || str[i] == 'g' ||
			str[i] == 'c' || str[i] == 'n')
			str[i] = str[i] - 'a' + 'A';
	return (str);
}

static seqlist_t *get_seq(char *line, seqlist_t *seqlist)
{
	seqlist_t *new = malloc(sizeof(seqlist_t));

	new->title = line;
	new->seq = strdup("");
	new->prev = seqlist;
	line = gnl(stdin);
	while (line != NULL && line[0] != '>') {
		new->seq = my_strcat(new->seq, line);
		free(line);
		line = gnl(stdin);
	}
	if (new->seq == NULL || new->seq[0] == '\0')
		exit_comment(2, "Error: no seq\n", 84);
	new->seq = capitalize_dnaseq(new->seq);
	new->seq = normalize_seqstr(new->seq, 0);
	if (line == NULL)
		new->next = NULL;
	else
		new->next = get_seq(line, new);
	return (new);
}

seqlist_t *get_fasta(void)
{
	seqlist_t *seqlist = NULL;
	char *line = gnl(stdin);

	if (line == NULL || line[0] != '>')
		exit_comment(2, "Error: no file or bad file given\n", 84);
	seqlist = get_seq(line, NULL);
	return (seqlist);
}
