/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:37:42 by yadib             #+#    #+#             */
/*   Updated: 2024/11/06 11:51:38 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	total_arrays_ft(const char *s, char sep)
{
	size_t	index;
	size_t	total_arrays;

	total_arrays = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == sep && s[index])
			index++;
		if (s[index] != '\0')
			total_arrays++;
		while (s[index] != sep && s[index])
			index++;
	}
	return (total_arrays);
}

static void	modifier_start_end_index(const char *s, char c,
									size_t *start_index, size_t *end_index)
{
	*start_index = *end_index;
	while ((s[*start_index] == c) && s[*start_index])
		*start_index = *start_index + 1;
	*end_index = *start_index;
	while (s[*end_index] != c && s[*end_index])
		*end_index += 1;
}

static char	*split_array(char const *s, char c,
					size_t *start_index, size_t *end_index)
{
	char	*single_arr;
	size_t	leng_of_arr;

	modifier_start_end_index(s, c, start_index, end_index);
	leng_of_arr = *end_index - *start_index;
	single_arr = ft_substr(s, *start_index, leng_of_arr);
	return (single_arr);
}

static void	*free_all_array(char **array_of_array, size_t last_index)
{
	while (last_index--)
		free(array_of_array[last_index]);
	free(array_of_array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	start_index;
	size_t	end_index;
	size_t	total_aray;
	char	**arr_split;
	size_t	arr_to_copy;

	if (s == NULL)
		return (NULL);
	arr_to_copy = 0;
	start_index = 0;
	end_index = 0;
	total_aray = total_arrays_ft(s, c);
	arr_split = (char **)malloc(sizeof(char *) * (total_aray + 1));
	if (arr_split == NULL)
		return (NULL);
	while (arr_to_copy < total_aray)
	{
		arr_split[arr_to_copy] = split_array(s, c, &start_index, &end_index);
		if (arr_split[arr_to_copy] == NULL)
			return (free_all_array(arr_split, arr_to_copy));
		arr_to_copy++;
	}
	arr_split[total_aray] = NULL;
	return (arr_split);
}
