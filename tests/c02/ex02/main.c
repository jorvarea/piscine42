#include <stdio.h>

int	ft_str_is_alpha(char *str);

int main()
{
    int is_alpha;
    char    str1[50] = "";
    char    str2[50] = "hola";
    char    str3[50] = "2hola";
    char    str4[50] = "$%·!$$";

    is_alpha = ft_str_is_alpha(str1);
    printf("str1: %d\n", is_alpha);
    is_alpha = ft_str_is_alpha(str2);
    printf("str2: %d\n", is_alpha);
    is_alpha = ft_str_is_alpha(str3);
    printf("str3: %d\n", is_alpha);
    is_alpha = ft_str_is_alpha(str4);
    printf("str4: %d\n", is_alpha);
    return (0);
}