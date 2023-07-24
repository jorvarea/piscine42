void	ft_putnbr_base_neg(int nbr, char *base, int base_number, char *number)
{
	int	quotient;
	int	remainder;
	int	i;

	i = 0;
	quotient = -nbr + 1;
	while (quotient != 0)
	{
		remainder = quotient % base_number;
		quotient = quotient / base_number;
		number[i++] = base[base_number - remainder - 1];
	}
	ft_rev_char_str(number, i);
	number[i] = '\0';
	ft_putstr(number);
}