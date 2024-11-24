/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:12:06 by yadib             #+#    #+#             */
/*   Updated: 2024/11/22 11:28:19 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	size_t	index;

	index = 0;
	if (s == NULL)
	{
		index += write(1, "(null)", 6);
		return (index);
	}
	while (s[index])
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
	return (index);
}
