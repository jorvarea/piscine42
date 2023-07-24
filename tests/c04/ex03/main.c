#include <stdio.h>

int	ft_atoi(char *str);

int main()
{
    char *str;
    int num;

    str = " ---+--+1234ab567";
    num = ft_atoi(str);
    printf("%i\n", num);
    return (0);
}