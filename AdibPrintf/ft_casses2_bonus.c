/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casses2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:33:39 by yadib             #+#    #+#             */
/*   Updated: 2024/11/21 01:09:19 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ultra_skip(const char *arr, size_t *index)
{
	char	*flags;
	size_t	flag_ind;

	flag_ind = 0;
	flags = malloc(4 * sizeof(char));
	if (flags == NULL)
		return (NULL);
	ft_bzero(flags, 4);
	while (arr[*index])
	{
		if (arr[*index] == '#' || arr[*index] == ' ' || arr[*index] == '+')
			flags[flag_ind] = arr[*index];
		else
			break ;
		while (flags[flag_ind] != 0)
		{
			if ((flags[flag_ind] == arr[*index]) && arr[*index])
			{
				flag_ind = -1;
				*index += 1;
			}
			flag_ind++;
		}
	}
	return (flags);
}

static void	print_pad_2(char *flags, char *input, size_t *length, char sign)
{
	if (flags[0] == '\0')
		return ;
	if (ft_strchr(flags, input[0]) != NULL && input[0] == '+'
		&& sign == '+')
		*length += ft_putchar_fd('+', 1);
	else if (ft_strchr(flags, input[1]) != NULL && input[1] == ' '
		&& sign == '+')
		*length += ft_putchar_fd(' ', 1);
	else if (ft_strchr(flags, input[0]) != NULL && input[0] == '#'
		&& sign == '+')
		*length += ft_putstr_fd(&input[1], 1);
}

static void	print_arg_with_pad(char *flags, char type_data,
							va_list args, size_t *length)
{
	unsigned int	store_data;

	if (type_data == 'i' || type_data == 'd')
	{
		store_data = va_arg(args, unsigned int);
		print_pad_2(flags, "+ ", length, (((int)store_data >= 0) + 42));
		*length += ft_putnbr_fd(store_data, INTEGERS);
	}
	else if (type_data == 'p')
		*length += ft_print_address(va_arg(args, void *));
	else if (type_data == 'x')
	{
		store_data = va_arg(args, unsigned int);
		print_pad_2(flags, "#0x", length, ((store_data > 0) + 42));
		*length += ft_convert_to_hex(store_data, LOWER_HEX);
	}
	else if (type_data == 'X')
	{
		store_data = va_arg(args, unsigned int);
		print_pad_2(flags, "#0X", length, ((store_data > 0) + 42));
		*length += ft_convert_to_hex(store_data, UPPER_HEX);
	}
}

static void	print_arg_no_effect(char *flags, char type_data,
								va_list args, size_t *length)
{
	if (type_data == 'c')
		*length += ft_putchar_fd(va_arg(args, int), 1);
	else if (type_data == 's')
		*length += ft_putstr_fd(va_arg(args, char *), 1);
	else if (type_data == 'u')
		*length += ft_putnbr_fd(va_arg(args, unsigned int), UNSIGNED_DEC);
	else if (type_data == '%')
		*length += ft_putchar_fd('%', 1);
	else
		print_arg_with_pad(flags, type_data, args, length);
	free(flags);
}

void	handle_casses_b2(const char *array,
						va_list args, size_t *index, size_t *length)
{
	char	*flags_find;

	flags_find = ultra_skip(array, index);
	print_arg_no_effect(flags_find, array[*index], args, length);
	ft_check_types(array[*index], index);
}
