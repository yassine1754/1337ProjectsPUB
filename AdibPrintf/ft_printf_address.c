/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:25:58 by yadib             #+#    #+#             */
/*   Updated: 2024/11/18 14:30:11 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	base_chars(short index)
{
	const char	hex_chars[17] = "0123456789abcdef";

	return ((char)hex_chars[index]);
}

static void	recursion_write(unsigned long long to_print, size_t *index)
{
	char			store_num;

	if (to_print / 16 != 0)
		recursion_write(to_print / 16, index);
	else if (to_print == 0)
	{
		*index += ft_putstr_fd("0", 1);
		return ;
	}
	store_num = base_chars((to_print % 16));
	*index += ft_putchar_fd(store_num, 1);
}

size_t	ft_print_address(void *arr)
{
	unsigned long long	address;
	size_t				index;

	index = 0;
	address = (unsigned long long int)arr;
	index += ft_putstr_fd("0x", 1);
	recursion_write(address, &index);
	return (index);
}
