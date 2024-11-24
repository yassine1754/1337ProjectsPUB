/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:42:06 by yadib             #+#    #+#             */
/*   Updated: 2024/11/22 15:44:39 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prints_any_data(va_list args, short type_index, size_t *length)
{
	if (type_index == CHARACTER)
		*length += ft_putchar_fd(va_arg(args, int), 1);
	else if (type_index == STRING)
		*length += ft_putstr_fd(va_arg(args, char *), 1);
	else if (type_index == ADDRESS)
		*length += ft_print_address(va_arg(args, void *));
	else if (type_index == INTEGERS || type_index == DECIMALS)
		*length += ft_putnbr_fd(va_arg(args, unsigned int), type_index);
	else if (type_index == UNSIGNED_DEC)
		*length += ft_putnbr_fd(va_arg(args, unsigned int), type_index);
	else if (type_index == LOWER_HEX || type_index == UPPER_HEX)
		*length += ft_convert_to_hex(va_arg(args, unsigned int), type_index);
}

static short	type_data(const char *array)
{
	char	*all_types[10];
	short	index;

	index = -1;
	all_types[0] = "%c";
	all_types[1] = "%s";
	all_types[2] = "%p";
	all_types[3] = "%d";
	all_types[4] = "%i";
	all_types[5] = "%u";
	all_types[6] = "%x";
	all_types[7] = "%X";
	all_types[8] = "%%";
	while (++index < 9)
	{
		if (ft_strncmp(array, all_types[index], 2) == 0)
			return (index);
	}
	return (NOT_FIND);
}

static short	wirte_and_skip(const char *array, size_t *index, size_t *length)
{
	while (array[*index] != '%' && array[*index] != '\0')
	{
		*length += ft_putchar_fd(array[*index], 1);
		*index += 1;
	}
	return (type_data(&array[*index]));
}

static void	print_one_arg(va_list args,
						short type_data, size_t *length, size_t *index)
{
	if (type_data == PERCENT_SIGN)
		*length += ft_putchar_fd('%', 1);
	else
		prints_any_data(args, type_data, length);
	*index += 2;
}

int	ft_printf(const char *array, ...)
{
	va_list	args;
	size_t	length;
	size_t	index;
	short	type_data;

	if (write(1, 0, 0) == -1)
		return (-1);
	index = 0;
	length = 0;
	va_start(args, array);
	while (array[index] != '\0')
	{
		type_data = wirte_and_skip(array, &index, &length);
		if (type_data != NOT_FIND)
			print_one_arg(args, type_data, &length, &index);
		else if (array[index] == '%' && type_data == NOT_FIND)
		{
			index += 1;
			handle_casses_b2(array, args, &index, &length);
		}
	}
	va_end(args);
	return (length);
}
