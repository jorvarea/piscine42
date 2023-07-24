#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int main()
{
    int a;
    int b;
    int div;
    int mod;

    a = 4;
    b = 2;
    ft_div_mod(a, b, &div, &mod);
    printf("%d\n", div);
    printf("%d\n", mod);
}
