/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_types_v2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:48:18 by yadib             #+#    #+#             */
/*   Updated: 2024/11/21 01:10:37 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_types(char check, size_t *index)
{
	int			i;
	const char	types[10] = {'u', 'c', 's', 'i', 'd', 'p', 'x', 'X', '%', '\0'};

	i = 0;
	while (types[i])
	{
		if (check == types[i])
		{
			*index += 1;
			break ;
		}
		i++;
	}
}
