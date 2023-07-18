#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int main()
{
    int i;
    int size;
    int my_array[4] = {1, 2, 3, 4};
    
    size = 4;
    ft_rev_int_tab(my_array, size);
    i = 0;
    while(i < size)
    {
        printf("%d,", my_array[i]);
        i++;
    }
    return (0);
}