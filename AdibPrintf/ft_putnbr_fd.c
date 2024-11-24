/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:23:04 by yadib             #+#    #+#             */
/*   Updated: 2024/11/20 00:44:50 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	recursion_int(int n, size_t *length)
{
	if (n == -2147483648)
	{
		*length += ft_putstr_fd("-2147483648", 1);
		return ;
	}
	if (n < 0)
	{
		*length += ft_putchar_fd('-', 1);
		n = n * -1;
	}
	if (n >= 10)
		recursion_int(n / 10, length);
	*length += ft_putchar_fd((n % 10) + 48, 1);
}

void	recursion_unsigned_int(unsigned int n, size_t *length)
{
	if (n >= 10)
		recursion_int(n / 10, length);
	*length += ft_putchar_fd((n % 10) + 48, 1);
}

size_t	ft_putnbr_fd(unsigned int n, short type_data)
{
	size_t	length;

	length = 0;
	if (type_data == UNSIGNED_DEC)
		recursion_unsigned_int(n, &length);
	else if (type_data == DECIMALS || type_data == INTEGERS)
		recursion_int((int)n, &length);
	return (length);
}
