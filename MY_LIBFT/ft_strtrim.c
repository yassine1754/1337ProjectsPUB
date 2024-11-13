/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:32:36 by yadib             #+#    #+#             */
/*   Updated: 2024/11/08 10:40:33 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short	check_is_equal_set(char single_char, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == single_char)
			return (1);
		i++;
	}
	return (0);
}

static void	skip_first_set(char const *s1, char const *set, size_t *start_index)
{
	while (s1[*start_index])
	{
		if (check_is_equal_set(s1[*start_index], set) == 1)
			*start_index += 1;
		else
			break ;
	}
}

static void	skip_last_set(char const *s1, char const *set, size_t *end_index)
{
	*end_index = ft_strlen(s1) - 1;
	while (end_index >= 0)
	{
		if (check_is_equal_set(s1[*end_index], set) == 1)
			*end_index -= 1;
		else
			break ;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;
	char	*without_set;
	size_t	len_total;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start_index = 0;
	end_index = 0;
	if (s1[0] == 0)
		return (ft_strdup(""));
	skip_first_set(s1, set, &start_index);
	skip_last_set(s1, set, &end_index);
	len_total = (end_index - start_index) + 1;
	without_set = ft_substr(s1, start_index, len_total);
	if (without_set == NULL)
		return (NULL);
	return (without_set);
}
