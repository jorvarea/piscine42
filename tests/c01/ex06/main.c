#include <stdio.h>

int	ft_strlen(char *str);

int main()
{
    char *str1;
    char *str2;
    char *str3;
    int l1;
    int l2;
    int l3;

    str1 = "";
    str2 = "hola";
    str3 = "tonto el que lo lea";
    l1 = ft_strlen(str1);
    l2 = ft_strlen(str2);
    l3 = ft_strlen(str3);
    printf("%d\n", l1);
    printf("%d\n", l2);
    printf("%d\n", l3);
    return (0);
}