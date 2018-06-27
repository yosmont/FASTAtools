/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** bonus
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "project.h"

void exit_comment(int fd, char *str, int rtn)
{
	write(fd, str, strlen(str));
	exit(rtn);
}

int count_letter(char c, char *str)
{
	int check = 0;

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			check += 1;
	return (check);
}

void letter_p(char c, char *str)
{
	int per = (count_letter(c, str) * 100) / strlen(str);
	int nb = 0;

	if (count_letter(c, str) == 0)
		return;
	if (c != 'A')
		printf("\n");
	if (c == 'N')
		printf("Error: %d\t\t\033[38;5;9m%d%%\033[0m\n", count_letter(c,
			str), per);
	else
		printf("%c: %d\t\t\t\033[38;5;9m%d%%\033[0m\n", c,
		count_letter(c, str), per);
	for (nb = 0; per >= 2; nb++)
		per = per - 2;
	printf("\xe2\xa6\x97");
	for (int i = 0; i < nb; i++)
		printf("\033[37;1m\xe2\x96\xa0\033[0m");
	nb = 50 - nb;
	for (int i = 0; i < nb; i++)
		printf("\033[30;1m\xe2\x96\xa0\033[0m");
	printf("\xe2\xa6\x98\n");
}

void print_b(seqlist_t *list)
{
	void *begin = list;
	int check = 0;

	while (list) {
		printf((check == 1) ? "\n" : "");
		printf("\033[38;5;5m%s\033[0m", list->title);
		letter_p('A', list->seq);
		letter_p('T', list->seq);
		letter_p('G', list->seq);
		letter_p('C', list->seq);
		letter_p('N', list->seq);
		list = list->next;
		check = 1;
	}
	list = begin;
}

int main(void)
{
	seqlist_t *seqlist = get_fasta();

	print_b(seqlist);
	free_seqlist(seqlist);
	return (0);
}
