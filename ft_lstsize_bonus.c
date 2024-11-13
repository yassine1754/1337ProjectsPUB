/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:28:50 by yadib             #+#    #+#             */
/*   Updated: 2024/11/08 10:04:34 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		total_lst;
	t_list	*track_null_lst;

	track_null_lst = lst;
	total_lst = 0;
	while (track_null_lst != NULL)
	{
		track_null_lst = track_null_lst->next;
		total_lst++;
	}
	return (total_lst);
}
