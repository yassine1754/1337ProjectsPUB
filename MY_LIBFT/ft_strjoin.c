/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:07:50 by yadib             #+#    #+#             */
/*   Updated: 2024/11/08 10:07:10 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_leng;
	char	*concatenation_str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	total_leng = ft_strlen(s1) + ft_strlen(s2) + 1;
	concatenation_str = malloc(total_leng * (sizeof(char)));
	if (concatenation_str == NULL)
		return (NULL);
	ft_strlcpy(concatenation_str, s1, (ft_strlen(s1) + 1));
	ft_strlcat(concatenation_str, s2, total_leng);
	return (concatenation_str);
}
