/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:12:47 by yadib             #+#    #+#             */
/*   Updated: 2024/11/06 17:13:12 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*copy_s1;
	unsigned char	*copy_s2;

	index = 0;
	copy_s1 = (unsigned char *)(s1);
	copy_s2 = (unsigned char *)(s2);
	while (index < n)
	{
		if (copy_s1[index] != copy_s2[index])
			return (copy_s1[index] - copy_s2[index]);
		index++;
	}
	return (0);
}
