#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2);

int main()
{
    char    *s1 = "abc";
    char    *s2 = "abcbevfas";
    int a;
    int b;
    
    a = strcmp(s1, s2);
    b = ft_strcmp(s1, s2);
    printf("La de verdad: %d\n", a);
    printf("La mía: %d\n", b);
}