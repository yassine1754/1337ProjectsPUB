/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:45:09 by yadib             #+#    #+#             */
/*   Updated: 2024/10/31 08:38:34 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					index;
	unsigned char			*point_dst;
	const unsigned char		*point_src;

	index = 0;
	point_dst = (unsigned char *)dst;
	point_src = (unsigned char *)src;
	if ((dst == NULL && src == NULL))
		return (NULL);
	if (dst > src)
	{
		while (len--)
			point_dst[len] = point_src[len];
	}
	else
	{
		while (index < len)
		{
			point_dst[index] = point_src[index];
			index++;
		}
	}
	return ((void *)dst);
}
