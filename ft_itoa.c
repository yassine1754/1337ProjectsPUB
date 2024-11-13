/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 07:52:28 by yadib             #+#    #+#             */
/*   Updated: 2024/10/28 14:34:17 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	length_num(int n)
{
	short	length;

	length = 0;
	if (n == 0 || n < 0)
		length += 1;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char	check_sign(int n)
{
	if (n >= 0)
		return ('+');
	else
		return ('-');
}

static void	write_num_to_char_array(char *array_of_char, unsigned int n,
								short length, char sign)
{
	array_of_char[length] = '\0';
	while (--length >= 0)
	{
		if (length == 0 && sign == '-')
		{
			array_of_char[length] = '-';
			return ;
		}
		array_of_char[length] = (char)((n % 10) + 48);
		n /= 10;
	}
}

static int	valeur_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (n *= -1);
}

char	*ft_itoa(int n)
{
	char	*array;
	short	length_number;
	char	sign;

	length_number = length_num(n);
	array = malloc(sizeof(char) * (length_number + 1));
	if (array == NULL)
		return (NULL);
	sign = check_sign(n);
	n = valeur_abs(n);
	write_num_to_char_array(array, (unsigned int) n, length_number, sign);
	return (array);
}
