/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:11:10 by yadib             #+#    #+#             */
/*   Updated: 2024/11/03 12:27:46 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tracking;

	if (lst == NULL)
		return (lst);
	tracking = lst;
	while (tracking->next != NULL)
		tracking = tracking->next;
	return (tracking);
}
