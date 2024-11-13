/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <yadib@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:06:05 by yadib             #+#    #+#             */
/*   Updated: 2024/11/05 10:55:29 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip_spaces(const char *str, int *skip_spaces_signs)
{
	while (str[*skip_spaces_signs] == 32
		|| (str[*skip_spaces_signs] >= 9 && str[*skip_spaces_signs] <= 13))
		*skip_spaces_signs += 1;
}

static void	skip_check_signs(const char *str,
							int *skip_spaces_signs, short *sign)
{
	if (str[*skip_spaces_signs] == '-' || (str[*skip_spaces_signs] == '+'))
	{
		if (str[*skip_spaces_signs] == '-' )
			*sign *= -1;
		*skip_spaces_signs += 1;
	}
}

static int	convert_str_to_int(const char *str,
								int *skip_spaces_signs, short sign)
{
	long long	total_result;
	long long	max_history;

	total_result = 0;
	max_history = 0;
	while ((str[*skip_spaces_signs] >= '0' && str[*skip_spaces_signs] <= '9')
		&& str[*skip_spaces_signs])
	{
		total_result = total_result * 10 + (int)(str[*skip_spaces_signs] - 48);
		*skip_spaces_signs += 1;
		if (total_result < max_history && sign == -1)
			return (0);
		else if (total_result < max_history && sign == 1)
			return (-1);
		max_history = total_result;
	}
	return (total_result);
}

int	ft_atoi(const char *str)
{
	int			atoi_result;
	int			skip_spaces_signs;
	short		sign;

	skip_spaces_signs = 0;
	atoi_result = 0;
	sign = 1;
	skip_spaces(str, &skip_spaces_signs);
	skip_check_signs(str, &skip_spaces_signs, &sign);
	atoi_result = (int) convert_str_to_int(str, &skip_spaces_signs, sign);
	return ((atoi_result * sign));
}