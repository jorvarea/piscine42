#include <string.h>
#include <stdio.h>

int main()
{
    char *s1;
    char *s2;
    char *s3;
    char *s4;

    s1 = "hola soy ManManolo";
    s2 = "Manolo";
    s3 = strstr(s1, s2);
    s4 = ft_strstr(s1, s2);
    printf("%s\n", s3);
    printf("%s\n", s4);
    return (0);
}