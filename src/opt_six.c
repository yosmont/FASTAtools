/*
** EPITECH PROJECT, 2018
** SYN_FASTAtools_2017
** File description:
** option six function
*/

#include <string.h>
#include <stdlib.h>
#include "project.h"

static char get_acid_letter(char *to_check)
{
	char codons_t[64][3] = {"GCT", "GCC", "GCA", "GCG", "TGT", "TGC", "GAT",
	"GAC", "GAA", "GAG", "TTT", "TTC", "GGT", "GGC", "GGA", "GGG", "CAT",
	"CAC", "ATT", "ATC", "ATA", "AAA", "AAG", "TTA", "TTG", "CTT", "CTC",
	"CTA", "CTG", "ATG", "AAT", "AAC", "CCT", "CCC", "CCA", "CCG", "CAA",
	"CAG", "AGA", "AGG", "CGT", "CGC", "CGA", "CGG", "TCT", "TCC", "TCA",
	"TCG", "AGT", "AGC", "ACT", "ACC", "ACA", "ACG", "GTT", "GTC", "GTA",
	"GTG", "TGG", "TAT", "TAC", "TAA", "TAG", "TGA"};
	char acid_t[65] = "AAAACCDDEEFFGGGGHHIIIKKLLLLLLMNNPPPPQQRRRRRRSSSSSSTT"
	"TTVVVVWYYOOOX";
	int i = 0;

	for (; strncmp(codons_t[i], to_check, 3) && i != 64; i++);
	return (acid_t[i]);
}

static char *change_str(char *str)
{
	int len = strlen(str) / 3;
	char *new = malloc(sizeof(char) * (len + 1));

	for (int i = 0; i < len; i++) {
		new[i] = get_acid_letter(&str[i * 3]);
	}
	new[len] = '\0';
	free(str);
	return (new);
}

charlist_t *six_create_charlist(seqlist_t *seqlist)
{
	charlist_t *list = five_create_charlist(seqlist);
	void *begin = list;

	while (list) {
		list->str = change_str(list->str);
		list = list->next;
	}
	return (bubblesort(begin));
}
