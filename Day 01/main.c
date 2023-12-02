#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int checkString(char *str, int i)
{
    if(str[i] == 'o' && str[i+1] == 'n' && str[i+2] == 'e')
        return 1;
    if(str[i] == 't' && str[i+1] == 'w' && str[i+2] == 'o')
        return 2;
    if(str[i] == 't' && str[i+1] == 'h' && str[i+2] == 'r' && str[i+3] == 'e' && str[i+4] == 'e')
        return 3;
    if(str[i] == 'f' && str[i+1] == 'o' && str[i+2] == 'u' && str[i+3] == 'r')
        return 4;
    if(str[i] == 'f' && str[i+1] == 'i' && str[i+2] == 'v' && str[i+3] == 'e')
        return 5;
    if(str[i] == 's' && str[i+1] == 'i' && str[i+2] == 'x')
        return 6;
    if(str[i] == 's' && str[i+1] == 'e' && str[i+2] == 'v' && str[i+3] == 'e' && str[i+4] == 'n')
        return 7;
    if(str[i] == 'e' && str[i+1] == 'i' && str[i+2] == 'g' && str[i+3] == 'h' && str[i+4] == 't')
        return 8;
    if(str[i] == 'n' && str[i+1] == 'i' && str[i+2] == 'n' && str[i+3] == 'e')
        return 9;
    return -1;
}

int checkReverseString(char *str, int i)
{
    if(str[i] == 'e' && str[i-1] == 'n' && str[i-2] == 'o')
        return 1;
    if(str[i] == 'o' && str[i-1] == 'w' && str[i-2] == 't')
        return 2;
    if(str[i] == 'e' && str[i-1] == 'e' && str[i-2] == 'r' && str[i-3] == 'h' && str[i-4] == 't')
        return 3;
    if(str[i] == 'r' && str[i-1] == 'u' && str[i-2] == 'o' && str[i-3] == 'f')
        return 4;
    if(str[i] == 'e' && str[i-1] == 'v' && str[i-2] == 'i' && str[i-3] == 'f')
        return 5;
    if(str[i] == 'x' && str[i-1] == 'i' && str[i-2] == 's')
        return 6;
    if(str[i] == 'n' && str[i-1] == 'e' && str[i-2] == 'v' && str[i-3] == 'e' && str[i-4] == 's')
        return 7;
    if(str[i] == 't' && str[i-1] == 'h' && str[i-2] == 'g' && str[i-3] == 'i' && str[i-4] == 'e')
        return 8;
    if(str[i] == 'e' && str[i-1] == 'n' && str[i-2] == 'i' && str[i-3] == 'n')
        return 9;
    return -1;
}

int get_first_number(char *str)
{
    int i = 0;
    int n = -1;
    while(str[i] != '\0')
    {
        if(str[i] == 'o' || str[i] == 't' || str[i] == 'f' || str[i] == 's' || str[i] == 'e' || str[i] == 'n')
        {
           n = checkString(str, i);
           if(n >= 0 && n <= 9)
               return n;
        }
        if(str[i] >= '0' && str[i] <= '9')
            return (str[i] - '0');
        i++;
    }
}

int get_last_number(char *str)
{
    int i = 0;
    int n = -1;
    while(str[i] != '\0')
        i++;
    while(i >= 0)
    {
        if(str[i] == 'e' || str[i] == 'o' || str[i] == 'r' || str[i] == 'x' || str[i] == 'n' || str[i] == 't')
        {
            n = checkReverseString(str, i);
            if(n >= 0 && n <= 9)
                return n;
        }
        if(str[i] >= '0' && str[i] <= '9')
            return (str[i] - '0');
        i--;
    }
}

int	main(void)
{
    int numero1 = 0;
    int numero2 = 0;
    int file;
    char *pnt;

    file = open("advent.txt", O_RDONLY);
    while(((pnt = get_next_line(file)) != NULL))
    {
        numero1 = get_first_number(pnt) * 10 + get_last_number(pnt);
        numero2 += numero1;
        free(pnt);
    }
    printf("%d\n", numero2);
    close(file);
    return 0;
}