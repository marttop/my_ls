/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_ls
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

typedef struct files {
    char **files;
    char **filepath;
    int but;
    int nm;
} files_t;

typedef struct infos {
    char *filepath;
    long int total_blocks;
    struct node *head;
    struct infos *next;
    DIR *__dirp;
} infos_t;

typedef struct node {
    char *name;
    char *grp_name;
    char *usr_name;
    char *mode;
    char *date;
    long unsigned int link;
    long int size;
    struct stat sb;
    struct node *next;
} node_t;

int my_strlen(char *str);
void error(char *msg);
int flag_counter(char **src);
char *parsor(char **src);
int bis_counter(char *src, int counter);
char *bis_parsor(char *src, char *flags, int *w);
char **filepath_parsor(char **src, char *flags, files_t *fa);
char *fill_str(char *res, char *src);
int get_nb_files(char **src);
infos_t *get_data(char **filepath);
char *get_date(struct stat *sb);
infos_t *fill_main_node(infos_t *main_node, char *filepath);
node_t *fill_sub_node(node_t *file_infos, struct dirent *my_dirent,
                        infos_t *main_node, char *filepath);
char *my_strcat(char *dest, char const *src);
char *get_mode(struct stat *sb);
char *my_strdup(char *str);
void no_arg(char *flags);
int my_ptrlen(char **str);
int my_putstr(char const *str);
void my_putchar(char c);
void my_put_nbr(long n);
void print_no_flags(infos_t *node, char **filepath, files_t *fa);
void show_data(infos_t *node, char *flags, char **filepath, files_t *fa);
int flagcheck(char c, char *flags);
void print_l_flag(infos_t *node, char **filepath, files_t *fa);
void print_l_flag_file(char *str);


#endif /* !MY_LS_H_ */
