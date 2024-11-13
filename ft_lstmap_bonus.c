/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:21:46 by yadib             #+#    #+#             */
/*   Updated: 2024/11/03 14:10:47 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	void	*content;
	t_list	*original_lst;
	t_list	*current_lst;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_head = NULL;
	original_lst = lst;
	while (original_lst != NULL)
	{
		content = f(original_lst->content);
		current_lst = ft_lstnew(content);
		if (current_lst == NULL)
		{
			if (del == NULL)
				return (NULL);
			del(content);
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_head, current_lst);
		original_lst = original_lst->next;
	}
	return (new_head);
}
