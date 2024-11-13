/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:17:43 by yadib             #+#    #+#             */
/*   Updated: 2024/11/06 11:54:41 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					index;
	unsigned char			*src_point;
	unsigned char			*dst_point;

	index = 0;
	src_point = (unsigned char *)(src);
	dst_point = (unsigned char *)(dst);
	if ((dst == NULL && src == NULL))
		return (NULL);
	if (dst == src)
		return (dst);
	while (index < n)
	{
		dst_point[index] = src_point[index];
		index++;
	}
	return ((void *)dst_point);
}
