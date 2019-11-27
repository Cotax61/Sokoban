/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_revstr
*/

static int is_lowcase(char *str, int i)
{
    if (str[i] >= 'a' && str[i] < 'z')
        return (1);
    return (0);
}

static int is_upcase(char *str, int i)
{
    if (str[i] >= 'A' && str[i] < 'Z')
        return (1);
    return (0);
}

static int is_numerical(char *str, int i)
{
    if (str[i] >= '0' && str[i] <= '9')
        return (1);
    return (0);
}

static int is_alphabetic(char *str, int i)
{
    if (str[i] >= 'A' && str[i] <= 'Z')
        return (1);
    else if (str[i] >= 'a' && str[i] <= 'z')
        return (1);
    if (str[i] >= '0' && str[i] <= '9')
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    if (str == 0)
        return (0);
    if (is_lowcase(str, 0))
        str[0] -= 32;
    while (str[i] != '\0') {
        if (is_upcase(str, i) && is_upcase(str, i - 1))
            str[i] += 32;
        else if (is_lowcase(str, i) && !is_alphabetic(str, i - 1))
            str[i] -= 32;
        if (is_upcase(str, i) && is_lowcase(str, i - 1))
            str[i] += 32;
        if (is_numerical(str, i - 1) && is_upcase(str, i))
            str[i] += 32;
        i++;
    }
    return (str);
}