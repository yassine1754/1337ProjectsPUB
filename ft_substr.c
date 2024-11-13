/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:30:00 by yadib             #+#    #+#             */
/*   Updated: 2024/10/31 08:39:39 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_max_length(char const *org_str,
								unsigned int start, size_t len)
{
	if (len >= ft_strlen(org_str + start))
		return (ft_strlen(org_str + start));
	else
		return (len);
}

char	*ft_substr(char const *org_str, unsigned int start, size_t len)
{
	size_t	index;
	char	*sub_string;

	if (org_str == NULL)
		return (NULL);
	index = 0;
	if (start >= ft_strlen(org_str))
		return (ft_strdup(""));
	len = check_max_length(org_str, start, len);
	sub_string = malloc((len + 1) * sizeof(char));
	if (sub_string == NULL)
		return (NULL);
	while (index < len)
	{
		sub_string[index] = org_str[index + start];
		index++;
	}
	sub_string[index] = '\0';
	return (sub_string);
}
