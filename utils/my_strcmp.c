/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** compare char and return int
*/

int my_lenstr(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] < s2[i])
            return (-1);
        else if (s1[i] > s2[i])
            return (1);
    }
    if (my_lenstr(s1) < my_lenstr(s2))
        return (-1);
    return (0);
}
