#include <unistd.h>

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	*str;
	char src[265];
	int	i;

	i = 1;
	while (i <= 255)
	{
		src[i - 1] = i;
		i++;
	}
	src[i - 1] = '\0';

	str = "Coucou\ntu vas bien ?";
	ft_putstr_non_printable(str);
	write(1, "\n", 1);
	ft_putstr_non_printable(src);
	return (0);
}