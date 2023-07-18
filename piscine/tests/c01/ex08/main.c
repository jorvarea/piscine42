#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int main()
{
    int array[11] = {1, 4, 6, 7, 6, 9, 3, 56, 27, 76, 99}; 
    int size;
    int i;

    size = 11;
    i = 0;
    while(i < size)
    {
        printf("%d, ", array[i]);
        i++;
    }
    printf("\n");
    ft_sort_int_tab(&array[0], size);
    i = 0;
    while(i < size)
    {
        printf("%d, ", array[i]);
        i++;
    }
    return (0);
}