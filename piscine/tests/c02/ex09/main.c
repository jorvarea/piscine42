#include <unistd.h>

char	*ft_strcapitalize(char *str);

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

int main()
{
	char	str[] = "salUt, comMent tu vas ? 42Mots QuaRante-deux; cinqUante+et+un";
    char    *str2;

	ft_putstr(str);
    write(1, "\n", 1);
	str2 = ft_strcapitalize(str);
	ft_putstr(str2);
	return (0);
}