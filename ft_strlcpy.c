/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:03:18 by yadib             #+#    #+#             */
/*   Updated: 2024/11/06 17:10:56 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst,
		const char *src,
		size_t dst_size)
{
	size_t	src_ind;
	size_t	result;

	result = ft_strlen(src);
	src_ind = 0;
	if (dst_size == 0)
		return (result);
	while (src[src_ind] && (src_ind < dst_size - 1))
	{
		dst[src_ind] = src[src_ind];
		src_ind++;
	}
	dst[src_ind] = '\0';
	return (result);
}
