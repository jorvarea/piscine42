#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	int		i;
	char	dest[100] = "Why is there something, rather than nothing?";
	char	src[100] = "42";
	
	printf("%s\n", dest);
	ft_strcpy(dest, src);
	printf("%s\n", dest);
    return (0);
}
