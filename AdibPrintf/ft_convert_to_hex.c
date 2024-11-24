/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_to_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:27:00 by yadib             #+#    #+#             */
/*   Updated: 2024/11/20 01:38:16 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_lower_hex(short index)
{
	const char	hex_chars[17] = "0123456789abcdef";

	return ((char)hex_chars[index]);
}

static char	ft_upper_hex(short index)
{
	const char	hex_chars[17] = "0123456789ABCDEF";

	return ((char)hex_chars[index]);
}

static void	recursion_write(unsigned int to_print,
							size_t *index, short type_data)
{
	char			store_num;

	if (to_print / 16 != 0)
		recursion_write(to_print / 16, index, type_data);
	else if (to_print == 0)
	{
		*index += ft_putstr_fd("0", 1);
		return ;
	}
	if (type_data == LOWER_HEX)
		store_num = ft_lower_hex((to_print % 16));
	else
		store_num = ft_upper_hex((to_print % 16));
	*index += ft_putchar_fd(store_num, 1);
}

size_t	ft_convert_to_hex(unsigned int degits, short type_data)
{
	size_t	index;

	index = 0;
	recursion_write(degits, &index, type_data);
	return (index);
}
