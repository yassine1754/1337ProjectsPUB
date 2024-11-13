/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:20:47 by yadib             #+#    #+#             */
/*   Updated: 2024/11/08 10:02:05 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	result;

	if (((long long int)count < 0) || ((long long int)size < 0))
		return (NULL);
	result = count * size;
	if (size > 0 && (count != (result / size)))
		return (NULL);
	pointer = malloc(result);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, result);
	return (pointer);
}
