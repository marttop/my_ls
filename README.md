# my_ls

- **Binary name:** my_ls
- **Repository name:** PSU_my_ls_2019
- **Language:** C
- **Group Size:** 1
- **Compilation:** via Makefile, including re, clean and fclean rules

# Goal

You must recode the ls [-lRdrt] [FILE] command.
Options can be given in either order.

## Authorized Functions

The only system calls allowed are the following ones:
- opendir - readdir - closedir
- stat
- lstat
- write
- getpwuid
- getgrgid
- time
- ctime
- readlink
- malloc
- free
- perror
- strerror
- exit
