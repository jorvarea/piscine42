#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

void	ft_putstr_v2(char *str, unsigned int n)
{
	char	c;
	int		i;

	i = 0;
	c = *str;
	while (c != '\0')
	{
		write(1, &c, 1);
		i++;
		c = *(str + i);
	}
	while(i < n)
	{
		write(1, "-", 1);
		i++;
		c = *(str + i);
	}
}

int	ft_strlen(char *str)
{
	char	c;
	int		i;

	i = 0;
	c = *str;
	while (c != '\0')
	{
		i++;
		c = *(str + i);
	}
	return (i);
}

int main()
{
    char    src[100] = "tonto";
    char    dest[100] = "ton";
    unsigned int    n;

    n = ft_strlen(src);
    ft_putstr_v2(src, n);
    write(1, "\n", 1);
    ft_putstr_v2(dest, n);
    write(1, "\n", 1);
    ft_strncpy(dest, src, n);
    ft_putstr_v2(src, n);
    write(1, "\n", 1);
    ft_putstr_v2(dest, n);
    write(1, "\n", 1);
    return (0);
}