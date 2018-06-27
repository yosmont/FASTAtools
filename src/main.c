/*
** EPITECH PROJECT, 2018
** yet another main
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "project.h"

void exit_comment(int fd, char *str, int rtn)
{
	write(fd, str, strlen(str));
	exit(rtn);
}

static int my_atoi(char *str)
{
	int nb = 0;

	if (str == NULL || str[0] == '\0')
		exit_comment(2, "Error: void string\n\0", 84);
	for (size_t i = 0; str[i] != '\0'; i++) {
		if (isdigit(str[i]) == 0)
			exit_comment(2, "Error: bad option\n\0", 84);
		nb = (nb * 10) + (str[i] - '0');
	}
	return (nb);
}

int choose_opt_two(seqlist_t *seqlist, int opt)
{
	switch (opt) {
	case 5:
		print_five(seqlist);
		break;
	case 6:
		print_six(seqlist);
		break;
	case 7:
		print_seven(seqlist);
		break;
	default:
		return (84);
		break;
	}
	return (0);
}

int choose_opt(seqlist_t *seqlist, int opt, int k)
{
	switch (opt) {
	case 1:
		print_one(seqlist);
		break;
	case 2:
		print_two(seqlist);
		break;
	case 3:
		print_three(seqlist);
		break;
	case 4:
		if (k == 0)
			return (84);
		print_four(seqlist, k);
		break;
	default:
		return (choose_opt_two(seqlist, opt));
		break;
	}
	return (0);
}

int main(int ac, char **av)
{
	seqlist_t *seqlist;
	int opt = 0;
	int k = 0;
	int rtn = 0;

	if (ac < 2)
		return (84);
	seqlist = get_fasta();
	opt = my_atoi(av[1]);
	if (ac > 2) {
		k = my_atoi(av[2]);
		opt = (opt != 4 || ac > 3) ? -1 : opt;
	}
	rtn = choose_opt(seqlist, opt, k);
	free_seqlist(seqlist);
	return (rtn);
}
