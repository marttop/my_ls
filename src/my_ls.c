/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** flag_founder
*/

#include "my_ls.h"

char *get_date(struct stat *sb)
{
    char *my_time = ctime(&sb->st_mtime);
    char *new_time = malloc(sizeof(char) * my_strlen(ctime(&sb->st_mtime)));
    int i = 0;

    for (int j = 4; j < 16; i++, j++)
        new_time[i] = my_time[j];
    new_time[i] = '\0';
    return (new_time);
}

char *get_mode(struct stat *sb)
{
    char *mode = malloc(sizeof(char) * 11);
    S_ISREG(sb->st_mode) ? (mode[0] = '-') : '\0';
    S_ISDIR(sb->st_mode) ? (mode[0] = 'd') : '\0';
    S_ISLNK(sb->st_mode) ? (mode[0] = 'l') : '\0';
    S_ISBLK(sb->st_mode) ? (mode[0] = 'b') : '\0';
    S_ISFIFO(sb->st_mode) ? (mode[0] = 'p') : '\0';
    S_ISSOCK(sb->st_mode) ? (mode[0] = 's') : '\0';
    S_ISCHR(sb->st_mode) ? (mode[0] = 'c') : '\0';
    mode[1] = (S_IRUSR & sb->st_mode) ? 'r' : '-';
    mode[2] = (S_IWUSR & sb->st_mode) ? 'w' : '-';
    mode[3] = (S_IXUSR & sb->st_mode) ? 'x' : '-';
    mode[4] = (S_IRGRP & sb->st_mode) ? 'r' : '-';
    mode[5] = (S_IWGRP & sb->st_mode) ? 'w' : '-';
    mode[6] = (S_IXGRP & sb->st_mode) ? 'x' : '-';
    mode[7] = (S_IROTH & sb->st_mode) ? 'r' : '-';
    mode[8] = (S_IWOTH & sb->st_mode) ? 'w' : '-';
    if (S_ISVTX & sb->st_mode) mode[9] = 'T';
    else mode[9] = (S_IXOTH & sb->st_mode) ? 'x' : '-';
    mode[10] = '\0';
    return (mode);
}

node_t *fill_sub_node(node_t *file_infos, struct dirent *my_dirent,
                        infos_t *main_node, char *filepath)
{
    node_t *new_infos = malloc(sizeof(node_t));
    char *new_filepath = malloc(sizeof(char) * my_strlen(filepath)
    + my_strlen(my_dirent->d_name) + 2);
    new_filepath[0] = '\0';
    struct group *grp;
    struct passwd *pwd;
    struct stat sb = {0};
    my_strcat(new_filepath, filepath);
    my_strcat(new_filepath, "/");
    my_strcat(new_filepath, my_dirent->d_name);
    stat(new_filepath, &sb);
    pwd = getpwuid(sb.st_uid), grp = getgrgid(sb.st_gid);
    main_node->total_blocks += sb.st_blocks/2, new_infos->time = sb.st_mtime;
    new_infos->mode = get_mode(&sb), new_infos->device = sb.st_rdev/256;
    new_infos->date = get_date(&sb);
    new_infos->usr_name = my_strdup(pwd->pw_name);
    new_infos->grp_name = my_strdup(grp->gr_name);
    new_infos->link = sb.st_nlink, new_infos->size = sb.st_size;
    new_infos->next = file_infos;
    return (new_infos);
}

infos_t *fill_main_node(infos_t *main_node, char *filepath)
{
    infos_t *new_node = malloc(sizeof(infos_t));
    node_t *file_infos = NULL;
    new_node->__dirp = opendir(filepath);
    struct dirent *my_dirent = readdir(new_node->__dirp);
    struct stat sb;
    stat(filepath, &sb);
    new_node->filepath = filepath;
    new_node->total_blocks = 0, new_node->time = sb.st_mtime;
    while (my_dirent != NULL) {
        if (my_dirent->d_name[0] != '.') {
            file_infos = fill_sub_node(file_infos, my_dirent,
            new_node, filepath);
            file_infos->name = my_dirent->d_name;
        }
        my_dirent = readdir(new_node->__dirp);
    }
    new_node->next = main_node;
    new_node->head = file_infos;
    return (new_node);
}

infos_t *get_data(char **filepath)
{
    infos_t *main_node = NULL;
    for (int i = 0; filepath[i] != NULL; i++) {
        main_node = fill_main_node(main_node, filepath[i]);
    }
    return (main_node);
}