/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:03:40 by yadib             #+#    #+#             */
/*   Updated: 2024/11/05 10:46:36 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst,
					const char *src, size_t dst_size)
{
	size_t	index;
	size_t	src_ind;
	size_t	result;

	if (dst == NULL && dst_size == 0)
		return (ft_strlen(src));
	src_ind = 0;
	result = ((ft_strlen(dst) + ft_strlen(src)));
	index = ft_strlen(dst);
	if (index >= dst_size)
		return (dst_size + ft_strlen(src));
	while (((index + src_ind) < (dst_size - 1)) && src[src_ind])
	{
		dst[index + src_ind] = src[src_ind];
		src_ind++;
	}
	dst[index + src_ind] = '\0';
	return (result);
}
