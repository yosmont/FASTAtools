/*
** EPITECH PROJECT, 2018
** yet another header
** File description:
** header
*/

#include <stdio.h>

#ifndef PROJECT_H_
	#define PROJECT_H_

typedef struct fasta_sequence_list_s {
	char *title;
	char *seq;
	struct fasta_sequence_list_s *prev;
	struct fasta_sequence_list_s *next;
} seqlist_t;

typedef struct linked_list_of_char_s {
	char *str;
	struct linked_list_of_char_s *prev;
	struct linked_list_of_char_s *next;
} charlist_t;

typedef struct seven_matriciel_info_s {
	int x;
	int y;
	int **mat;
	char *str_one;
	char *str_two;
} matinfo_t;

typedef struct alignment_s {
	char *al_a;
	char *al_b;
	int count[2];
	int score[4];
} al_t;

void exit_comment(int fd, char *str, int rtn);
char *gnl(FILE *fd);
char *my_strcat(char *dest, char *src);
char *my_strrev(char *str);
char *my_strndup(char *str, int n);
char *straddc(char *str, char c);
seqlist_t *get_fasta(void);
void free_seqlist(seqlist_t *seqlist);
void print_one(seqlist_t *seqlist);
void print_two(seqlist_t *seqlist);
void print_three(seqlist_t *seqlist);
charlist_t *four_create_charlist(seqlist_t *seqlist, int k);
charlist_t *bubblesort(charlist_t *list);
void print_four(seqlist_t *seqlist, int k);
charlist_t *five_create_charlist(seqlist_t *seqlist);
void print_five(seqlist_t *seqlist);
charlist_t *six_create_charlist(seqlist_t *seqlist);
void print_six(seqlist_t *seqlist);
int c_value(char c);
int **create_matrice(int x, int y, char *str_a, char *str_b);
void free_mat(matinfo_t matinfo);
al_t opt_seven(seqlist_t *seqlist);
void print_seven(seqlist_t *seqlist);

#endif /* !PROJECT_H_ */
