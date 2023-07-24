#include <string.h>
#include <stdio.h>

int main()
{
    char    dest1[100] = "buenos dias";
    char    dest2[100] = "buenos dias";
    char    src[100] = " princesa";
    char    *s1;
    char    *s2;

    s1 = strcat(dest1, src);
    s2 = ft_strcat(dest2, src);
    printf("%s\n", s1);
    printf("%s\n", s2);
}