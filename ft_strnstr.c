/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:44:40 by yadib             #+#    #+#             */
/*   Updated: 2024/10/26 21:49:18 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	find_str(int index, const char *haystack
						, const char *needle, size_t len)
{
	size_t	i_needle;

	i_needle = 0;
	while (needle[i_needle]
		&& (haystack[index + i_needle] == needle[i_needle])
		&& (index + i_needle < len))
		i_needle++;
	if (needle[i_needle] == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i_haystack;

	i_haystack = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i_haystack] && (i_haystack < len))
	{
		if (find_str(i_haystack, haystack, needle, len) == 1)
			return ((char *)(haystack + i_haystack));
		i_haystack++;
	}
	return (NULL);
}
