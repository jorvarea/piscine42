/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:53:27 by jorvarea          #+#    #+#             */
/*   Updated: 2023/07/13 12:38:52 by jorvarea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		is_word_start;
	char	c;

	is_word_start = 1;
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			if (is_word_start == 1 && c >= 'a' && c <= 'z')
				str[i] = str[i] - 32;
			else if (is_word_start == 0 && c >= 'A' && c <= 'Z')
				str[i] = str[i] + 32;
			is_word_start = 0;
		}
		else if (c >= '0' && c <= '9')
			is_word_start = 0;
		else
			is_word_start = 1;
		i++;
	}
	return (str);
}
