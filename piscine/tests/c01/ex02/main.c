#include <stdio.h>

void	ft_swap(int *a, int *b);

int main()
{
    int a;
    int b;

    a = 2;
    b = 3;
    printf("%d\n", a);
    printf("%d\n", b);
    ft_swap(&a, &b);
    printf("%d\n", a);
    printf("%d\n", b);

    return (0);
}

