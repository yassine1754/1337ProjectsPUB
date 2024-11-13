/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:10:38 by yadib             #+#    #+#             */
/*   Updated: 2024/11/06 17:02:34 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*iterate_pointer;

	if (lst == NULL || f == NULL)
		return ;
	iterate_pointer = lst;
	while (iterate_pointer)
	{
		f(iterate_pointer->content);
		iterate_pointer = iterate_pointer->next;
	}
}
