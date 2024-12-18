/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:51:27 by yadib             #+#    #+#             */
/*   Updated: 2024/11/18 14:26:06 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		return (write(fd, &c, 1));
	else
		return (0);
}
