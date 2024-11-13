/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 07:47:31 by yadib             #+#    #+#             */
/*   Updated: 2024/11/06 17:02:11 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tracking;
	t_list	*current;

	if (*lst == NULL || del == NULL)
		return ;
	tracking = *lst;
	while (tracking != NULL)
	{
		current = tracking->next;
		ft_lstdelone(tracking, del);
		tracking = current;
	}
	*lst = NULL;
}
