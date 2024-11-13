/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:09:25 by yadib             #+#    #+#             */
/*   Updated: 2024/11/03 16:51:28 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*copy_str;

	index = 0;
	copy_str = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (index < n)
	{
		if (copy_str[index] == (unsigned char )c)
			return (copy_str + index);
		index++;
	}
	if ((unsigned char)c == '\0' && copy_str[index] == '\0')
		return (copy_str + index);
	return (NULL);
}
