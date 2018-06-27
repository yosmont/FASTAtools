/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** option seven function
*/

#include <string.h>
#include <stdlib.h>
#include "project.h"

int c_value(char c)
{
	switch (c) {
	case 'A':
		return (1);
	case 'C':
		return (2);
	case 'G':
		return (3);
	case 'T':
		return (4);
	default:
		return (0);
	}
}

static al_t al_step_two(matinfo_t matinfo, al_t al)
{
	while (al.count[0] >= 0) {
		al.al_a = straddc(al.al_a, matinfo.str_one[al.count[0]]);
		al.al_b = straddc(al.al_b, 'N');
		al.count[0] -= 1;
	}
	while (al.count[1] >= 0) {
		al.al_b = straddc(al.al_b, matinfo.str_two[al.count[1]]);
		al.al_a = straddc(al.al_a, 'N');
		al.count[1] -= 1;
	}
	return (al);
}

static al_t add_to_alignment(al_t al, matinfo_t matinfo)
{
	if (al.score[0] == (al.score[1] +
	(c_value(matinfo.str_one[al.count[0]])	-
	c_value(matinfo.str_two[al.count[1]])))) {
		al.al_a = straddc(al.al_a, matinfo.str_one[al.count[0]]);
		al.al_b = straddc(al.al_b, matinfo.str_two[al.count[1]]);
		al.count[0] -= 1;
		al.count[1] -= 1;
	} else if (al.score[0] == (al.score[3] - 5)) {
		al.al_a = straddc(al.al_a, matinfo.str_one[al.count[0]]);
		al.al_b = straddc(al.al_b, 'N');
		al.count[0] -= 1;
	} else {
		al.al_a = straddc(al.al_a, 'N');
		al.al_b = straddc(al.al_b, matinfo.str_two[al.count[1]]);
		al.count[1] -= 1;
	}
	return (al);
}

static al_t calc_alignment(matinfo_t matinfo)
{
	al_t al = {malloc(sizeof(char) * 2), malloc(sizeof(char) * 2),
		{matinfo.x - 1, matinfo.y - 1}, {0, 0, 0, 0}};

	al.al_a[0] = '\0';
	al.al_b[0] = '\0';
	while (al.count[0] > 0 && al.count[1] > 0) {
		al.score[0] = matinfo.mat[al.count[0]][al.count[1]];
		al.score[1] = matinfo.mat[al.count[0] - 1][al.count[1] - 1];
		al.score[2] = matinfo.mat[al.count[0]][al.count[1] - 1];
		al.score[3] = matinfo.mat[al.count[0] - 1][al.count[1]];
		al = add_to_alignment(al, matinfo);
	}
	return (al_step_two(matinfo, al));
}

al_t opt_seven(seqlist_t *seqlist)
{
	matinfo_t matinfo = {0, 0, NULL, NULL, NULL};
	al_t al;

	if (seqlist && seqlist->seq && seqlist->next && seqlist->next->seq) {
		matinfo.x = (int)strlen(seqlist->seq);
		matinfo.y = (int)strlen(seqlist->next->seq);
		matinfo.str_one = seqlist->seq;
		matinfo.str_two = seqlist->next->seq;
	} else
		exit_comment(2, "Error: bad number of DNA\n", 84);
	matinfo.mat = create_matrice(matinfo.y, matinfo.x, matinfo.str_two,
	matinfo.str_one);
	al = calc_alignment(matinfo);
	free_mat(matinfo);
	return (al);
}
