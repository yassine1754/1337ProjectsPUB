/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:23:04 by yadib             #+#    #+#             */
/*   Updated: 2024/11/05 10:54:31 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	ft_length_num(int n)
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

static char	ft_check_sign(int n)
{
	if (n >= 0)
		return ('+');
	else
		return ('-');
}

static void	write_num_to_char_array(char *array_of_char, int n,
								short length, char sign)
{
	array_of_char[length] = '\0';
	if (length > 1 && n < 0)
	{
		array_of_char[--length] = (char)(((n % 10) * -1) + 48);
		n /= 10;
	}
	if (n < 0)
		n *= -1;
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

void	ft_putnbr_fd(int n, int fd)
{
	size_t	leng_number;
	char	sign;
	char	num_to_char[12];

	leng_number = ft_length_num(n);
	sign = ft_check_sign(n);
	write_num_to_char_array(num_to_char, n, leng_number, sign);
	ft_putstr_fd(num_to_char, fd);
}
