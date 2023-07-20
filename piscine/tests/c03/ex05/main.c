#include <stdio.h>
#include <string.h>

int	main(void)
{
	char			s1[100] = "hola";
	char			s2[100] = " princesa";
	char			s3[100] = "hola";
	unsigned int	size;
	unsigned int	result;

	size = 5;
	result = ft_strlcat(s1, s2, size);
	printf("%s\n", s1);
	printf("%d\n", result);
	result = strlcat(s3, s2, size);
	printf("%s\n", s3);
	printf("%d\n", result);
	return (0);
}