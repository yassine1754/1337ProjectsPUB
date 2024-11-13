/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:25:00 by yadib             #+#    #+#             */
/*   Updated: 2024/11/05 15:50:27 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*pointer;

	pointer = (unsigned char *)b;
	index = 0;
	while (index < len)
	{
		*pointer++ = (unsigned char)(c);
		index++;
	}
	return (b);
}
