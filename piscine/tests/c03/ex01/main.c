#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int main()
{
    char    *s1 = "abc";
    char    *s2 = "abchsdsbg";
    unsigned int n;
    int a;
    int b;
    
    n = 0;
    a = strncmp(s1, s2, n);
    b = ft_strncmp(s1, s2, n);
    printf("La de verdad: %d\n", a);
    printf("La mía: %d\n", b);
}