#include <unistd.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

void	ft_putnbr(int nb)
{
	int	i;

	i = 1000000000;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb == -2147483648)
	{
		write(1, "2", 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (i > nb)
		i = i / 10;
	while (i >= 1)
	{
		write(1, &"0123456789"[(nb / i) % 10], 1);
		i = i / 10;
	}
}

void	ft_putstr(char *str)
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
}

int	main(void)
{
	char *src;
	char dest[50];
	int size;
	unsigned int len;

	size = 0;
	src = "analba";
	ft_putstr(src);
	write(1, "\n", 1);
	len = ft_strlcpy(dest, src, size);
	ft_putstr(dest);
	write(1, "\n", 1);
	write(1, "Length: ", 8);
	ft_putnbr(len);
	write(1, "\n", 1);

	len = strlcpy(dest, src, size);
	ft_putstr(dest);
	write(1, "\n", 1);
	write(1, "Length: ", 8);
	ft_putnbr(len);
	write(1, "\n", 1);
}