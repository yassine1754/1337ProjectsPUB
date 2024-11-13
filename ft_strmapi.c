/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:54:39 by yadib             #+#    #+#             */
/*   Updated: 2024/11/08 10:33:15 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*pointer_result;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (ft_strdup(s));
	index = 0;
	pointer_result = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (pointer_result == NULL)
		return (NULL);
	while (s[index])
	{
		pointer_result[index] = f(index, s[index]);
		index++;
	}
	pointer_result[index] = '\0';
	return (pointer_result);
}
