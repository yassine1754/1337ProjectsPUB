/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadib <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:33:05 by yadib             #+#    #+#             */
/*   Updated: 2024/10/22 10:33:08 by yadib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int ascii)
{
	return (ascii >= 0 && ascii <= 127);
}