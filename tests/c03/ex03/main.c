#include <string.h>
#include <stdio.h>

int main()
{
    char    dest1[100] = "buenos dias";
    char    dest2[100] = "buenos dias";
    char    src[100] = " mi principe";
    char    *s1;
    char    *s2;
    unsigned int n;

    n = 5;
    s1 = strncat(dest1, src, n);
    s2 = ft_strncat(dest2, src, n);
    printf("%d\n", n);
    printf("%s\n", s1);
    printf("%s\n", s2);
}