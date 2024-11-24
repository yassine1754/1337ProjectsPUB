/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:50:55 by yadib             #+#    #+#             */
/*   Updated: 2024/11/19 19:15:43 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	char unsigned	*point_of_s;

	i = 0;
	point_of_s = (char unsigned *)s;
	while (i < n)
	{
		point_of_s[i] = 0;
		i++;
	}
}
