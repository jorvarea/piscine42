/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iballest <iballest@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:41:46 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/23 19:48:15 by iballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (is_space(str[i]))
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	while (is_space(str[i]))
		i++;
	if (str[i])
		return (-1);
	return (nb);
}

void	ft_stratoi(char *str)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		while (str[i] > 32 && str[i] < 127)
			str[j++] = str[i++];
		if (is_space(str[i]))
			str[j++] = ' ';
		while (is_space(str[i]))
			i++;
	}
	if (is_space(str[j - 1]))
		str[j - 1] = '\0';
	str[j] = '\0';
}
