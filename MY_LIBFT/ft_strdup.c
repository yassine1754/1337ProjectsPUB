/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:39:22 by yadib             #+#    #+#             */
/*   Updated: 2024/11/06 11:58:52 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	index_s1;
	size_t	s1_leng;	
	char	*ptr_str;

	index_s1 = 0;
	s1_leng = ft_strlen(s1) + 1;
	ptr_str = malloc(sizeof(char) * (s1_leng));
	if (ptr_str == NULL)
		return (NULL);
	while (s1[index_s1])
	{
		ptr_str[index_s1] = s1[index_s1];
		index_s1++;
	}
	ptr_str[index_s1] = '\0';
	return (ptr_str);
}
